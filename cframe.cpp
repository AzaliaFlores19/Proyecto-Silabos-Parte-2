#include "cframe.h"
#include "ui_cframe.h"
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <istream>
#include <iostream>
#include <string>
#include <sstream>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QProcess>
#include <fstream>
#include <iostream>
#include <sstream>
#include <QModelIndex>
#include <QVBoxLayout>

using std::ofstream;
using std::ios;
using std::string;

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);

    ui->frameE->setVisible(true);
    ui->frameR->setVisible(true);
    ui->frameB->setVisible(true);
    ui->Dframe2->setVisible(true);
    ui->Dbtn_salir->setVisible(true);

    connect(ui->RTW_revision, &QTableWidget::cellDoubleClicked, this, &cframe::on_btn_revision_2_clicked);

    listaUsuarios.cargarUsuarios();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(ui->tabWidget);
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    ui->tabWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->tabWidget->setMinimumSize(800, 600);

    // ============= Cargar usuario de prueba ===============

    Usuario u("Usuario de Prueba", "101101", "passwd", "Docente");
    listaUsuarios.InsertarFin(u);
}

cframe::~cframe()
{
    delete arbolSilabo;
    arbolSilabo = nullptr;

    delete ui;
}

void cframe::on_btn_entregarM_2_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void cframe::on_btn_revision_2_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void cframe::on_btn_dashboardM_2_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}

void cframe::on_tabWidget_currentChanged(int index)
{
    QMessageBox::StandardButton cambio;
    if ((index == 2 || index == 3 || index == 4) && loginDocente) {
        cambio = QMessageBox::question(this, "Acceso Denegado", "Los docentes no tienen acceso\n¿Desea cerrar sesión? ", QMessageBox::Yes | QMessageBox::No);
        if (cambio == QMessageBox::Yes) {
            loginDocente = false;
            ui->tabWidget->setCurrentIndex(index);
            ui->tab_3->setEnabled(true);
            ui->tab_4->setEnabled(true);
            ui->tab_5->setEnabled(true);
            limpiarEntrega();
        } else {
            ui->tabWidget->setCurrentIndex(1);
        }
    } else if ((index == 1 || index == 3 || index == 4) && loginRevision) {
        cambio = QMessageBox::question(this, "Acceso Denegado", "Ya ha iniciado sesión para otro proceso\n¿Desea cerrar sesión? ", QMessageBox::Yes | QMessageBox::No);
        if (cambio == QMessageBox::Yes) {
            loginRevision = false;
            ui->tabWidget->setCurrentIndex(index);
            ui->tab_2->setEnabled(true);
            ui->tab_4->setEnabled(true);
            ui->tab_5->setEnabled(true);
            limpiarRevision();
        } else {
            ui->tabWidget->setCurrentIndex(2);
        }
    } else if ((index == 1 || index == 2 || index == 4) && loginBoard) {
        cambio = QMessageBox::question(this, "Acceso Denegado", "Ya ha iniciado sesión solo para visualizar\n¿Desea cerrar sesión? ", QMessageBox::Yes | QMessageBox::No);
        if (cambio == QMessageBox::Yes) {
            loginBoard = false;
            ui->tabWidget->setCurrentIndex(index);
            ui->tab_3->setEnabled(true);
            ui->tab_2->setEnabled(true);
            ui->tab_5->setEnabled(true);
            limpiarBoard();
        } else {
            ui->tabWidget->setCurrentIndex(3);
        }
    } else if ((index == 1 || index == 2 || index == 3) && loginCheck) {
        cambio = QMessageBox::question(this, "Acceso Denegado", "Ya ha iniciado sesión solo para otro proceso\n¿Desea cerrar sesión? ", QMessageBox::Yes | QMessageBox::No);
        if (cambio == QMessageBox::Yes) {
            loginCheck = false;
            ui->tabWidget->setCurrentIndex(index);
            ui->tab_3->setEnabled(true);
            ui->tab_2->setEnabled(true);
            ui->tab_4->setEnabled(true);
        } else {
            ui->tabWidget->setCurrentIndex(4);
        }
    }
}

void cframe::on_btn_sesion_clicked()
{
    if (ui->le_claveE->text().isEmpty() || ui->le_cuentaE->text().isEmpty()) {
        QMessageBox::warning(this, "Datos no congruentes", "Favor no deje campos sin completar");
    } else {
        Usuario *user = nullptr;

        string cuenta = ui->le_cuentaE->text().toStdString();
        string pwd = ui->le_claveE->text().toStdString();

        // Recorrer la lista de usuarios hasta encontrar datos ingresados
        for (nodoD<Usuario> *nodoUser = listaUsuarios.PrimPtr; nodoUser != nullptr; nodoUser = nodoUser->SigPtr) {
            if (cuenta == nodoUser->Dato.cuenta) {
                user = &nodoUser->Dato;
                break;
            }
        }

        if (user == nullptr) {
            QMessageBox::warning(this, "Usuario Incorrecto", "El número de cuenta no está registrado.");
            return;
        }

        if (user->contrasena == pwd) {
            usuarioActual = user;

            // TODO: Habilitar tabs correspondientes al usuario

            // popup de prueba
            QMessageBox::warning(this, "TEST", QString::fromStdString(usuarioActual->name));
        } else {
            QMessageBox::warning(this, "Login", "Contraseña incorrecta.");
        }
    }
}

void cframe::on_btn_closeE_clicked()
{
    loginDocente = false;
    ui->tab_3->setEnabled(true);
    ui->tab_4->setEnabled(true);
    ui->tab_5->setEnabled(true);
    limpiarEntrega();
    ui->tabWidget->setCurrentIndex(0);
}

void cframe::limpiarEntrega()
{
    QStringList items;
    ui->cb_carreraE->clear();
    items << "...";
    ui->cb_carreraE->addItems(items);
    ui->le_codigoE->clear();
    ui->le_pathE->clear();

    // No ocultar la opción de entrega
    ui->frameE->setVisible(true);
    ui->frameE2_2->setEnabled(true);

    // Limpiar los campos solo si no hay sesión de docente iniciada
    if (!loginDocente) {
        ui->le_cuentaE->clear();
        ui->le_claveE->clear();
        ui->cb_facultadE->setCurrentIndex(0);
        ui->cb_carreraE->setCurrentIndex(0);
    }
}

void cframe::on_btn_silaboE_clicked()
{
    if (ui->cb_facultadE->currentIndex() == 0 || ui->cb_carreraE->currentIndex() == 0 || ui->le_codigoE->text().isEmpty() || ui->le_pathE->text().isEmpty()) {
        QMessageBox::warning(this, "Datos no congruentes", "Favor no deje campos sin completar");
    } else {
        QMessageBox::information(this, "Enviado", "Datos han sido enviados");
        cantSilabos = this->arbolSilabo->getCantidadArbol() + 1; // id sería cantidad en árbol más uno

        string facultad = ui->cb_facultadE->currentText().toStdString();
        string carrera = ui->cb_carreraE->currentText().toStdString();
        QString path = ui->le_pathE->text();

        // Verificar que usuarioActual no sea nullptr
        if (!usuarioActual) {
            QMessageBox::critical(this, "Error", "Usuario no autenticado.");
            return;
        }

        Silabo* nuevoSilabo = new Silabo(cantSilabos, "NombreArchivo", Prerevision, "...", 0, "bytes",
                                         facultad, carrera, usuarioActual->getName(), ui->le_codigoE->text().toStdString(), path,
                                         "NombreClase", "SubidoPor");

        this->arbolSilabo->insertar(nuevoSilabo);
        arbolSilabo->mostrarDetallesSilabos();

        // Mantener la opción de entrega visible después de insertar
        limpiarEntrega();

        // Asegurar visibilidad de los elementos relacionados
        ui->frameE->setVisible(true);
        ui->frameE2_2->setEnabled(true);
    }
}

void cframe::on_btn_archivoE_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos Word Documents", QDir::homePath(), "Word Files (*.docx)");
    if (!filePath.isEmpty()) {
               QFileInfo fileInfo(filePath);
               QString nombreA=fileInfo.fileName();

               QString codigoClase= ui->le_codigoE->text();
               QString nombreClase= ui->le_nombreClase->text();
               QString nombreA_Esperado= QString("%1_%2.docx").arg(codigoClase, nombreClase);

               if (nombreA == nombreA_Esperado) {
                   ui->le_pathE->setText(filePath);
               } else {
                   QMessageBox::warning(this, "Nombre de archivo incorrecto", "El archivo debe llamarse " + nombreA_Esperado);
               }
           }
}

void cframe::on_cb_facultadE_currentIndexChanged(int i)
{
    QStringList items;
    ui->cb_carreraE->clear();
    if (i == 1) {
        items << "..." << "INGENIERÍA BIOMÉDICA" << "INGENIERÍA EN CIENCIA DE DATOS E INTELIGENCIA ARTIFICIAL" << "INGENIERÍA CIVIL" << "INGENIERÍA EN ENERGÍA" << "INGENIERÍA INDUSTRIAL Y DE SISTEMAS" << "INGENIERÍA EN MECATRÓNICA" << "INGENIERÍA EN SISTEMAS COMPUTACIONALES" << "INGENIERÍA EN TELECOMUNICACIONES Y ELECTRÓNICA"<<"INGENIERÍA EN INFORMÁTICA"<<"INGENIERÍA EN ELECTRÓNICA"<<"INGENIERÍA EN GESTIÓN LOGÍSTICA"<<"INGENIERÍA EN GESTIÓN DE AMBIENTE Y DESARROLLO";
        ui->cb_carreraE->addItems(items);
    } else if (i == 2) {
        items << "..." << "LICENCIATURA EN ADMINISTRACIÓN DE LA HOSPITALIDAD Y EL TURISMO" << "LICENCIATURA EN ADMINISTRACIÓN INDUSTRIAL E INTELICENCIA DE NEGOCIOS" << "LICENCIATURA EN AMINISTRACIÓN INDUSTRIAL Y EMPRENDIMIENTO" << "LICENCIATURA EN ADMINISTRACIÓN INDUSTRIAL Y OPERACIONES" << "LICENCIATURA EN DERECHO" << "LICENCIATURA EN FINANZAS Y ECONOMÍA" << "LICENCIATURA EN MERCADOTECNIA Y NEGOCIOS INTERNACIONALES" << "LICENCIATURA EN RELACIONES INTERNACIONALES"<<"LICENCIATURA EN CONTADURÍA PÚBLICA Y FINANZAS"<<"LICENCIATURA EN MERCADOTECNIA"<<"LICENCIATURA EN ADMINISTRACIÓN DE EMPRESAS"<<"LICENCIATURA EN RECURSOS HUMANOS"<<"LICENCIATURA EN ECONOMÍA"<<"LICENCIATURA EN PERIODISMO";
        ui->cb_carreraE->addItems(items);
    } else if (i == 3) {
        items << "..." << "LICENCIATURA EN ANIMACIÓN DIGITAL y DISEÑO INTERACTIVO" << "ARQUITECTURA" << "LICENCIATURA EN COMUNICACIÓN AUDIOVISUAL Y PUBLICITARIA" << "LICENCIATURA EN DISEÑO DE MODAS" << "LICENCIATURA EN DISEÑO GRÁFICO" << "LICENCIATURA EN GASTRONOMÍA";
        ui->cb_carreraE->addItems(items);
    }else if (i == 4) {
        items << "..." << "LICENCIATURA EN PSICOLOGÍA" << "MEDICINA Y CIRUGÍA" << "CIRUGÍA DENTAL" << "LICENCIATURA EN NUTRICIÓN" << "LICENCIATURA EN TERAPIA FÍSICA Y OCUPACIONAL" << "LICENCIATURA EN ENFERMERÍA";
        ui->cb_carreraE->addItems(items);
    }else if (i == 5) {
    items << "..." << "MAESTRÍA EN FINANZAS" << "MAESTRÍA EN GESTIÓN DEL MARKETING ESTRATÉGICO Y DIGITAL" << "MAESTRÍA EN DIRECCIÓN EMPRESARIAL" << "MAESTRÍA EN ADMINISTRACIÓN DE PROYECTOS" << "MAESTRÍA EN DERECHO EMPRESARIAL" << "MAESTRÍA EN DIRECCIÓN DE RECURSOS HUMANOS"<< "MAESTRÍA EN GESTIÓN DE OPERACIONES Y LOGÍSTICA" << "MAESTRÍA EN GESTIÓN DE TECNOLOGÍAS DE LA INFORMACIÓN"<< "MAESTRÍA EN SISTEMAS DE GESTIÓN DE LA CALIDAD INTEGRADOS" << "MAESTRÍA DE DIRECCIÓN DE LA COMUNICACIÓN CORPORATIVA" << "MAESTRÍA EN GESTIÓN DE ENERGÍAS RENOVABLES"<< "MAESTRÍA EN GESTIÓN DE SERVICIOS DE SALUD" << "MAESTRÍA EN GESTIÓN PÚBLICA" << "MAESTRIA EN DERECHOS HUMANOS"<< "MAESTRÍA EN PSICOLOGÍA CLÍNICA" << "MAESTRÍA EN DERECHO TRIBUTARIO" << "MAESTRÍA EN ANALÍTICA DE NEGOCIOS"<< "MAESTRÍA EN RESPONSABILIDAD SOCIAL Y SOSTENIBILIDAD" << "MAESTRÍA EN GESTIÓN DE LA INNOVACIÓN Y EL EMPRENDIMIENTO" << "MAESTRÍA EN DESARROLLO LOCAL Y COOPERACIÓN INTERNACIONAL" << "MAESTRÍA EN SALUD PÚBLICA" ;
    ui->cb_carreraE->addItems(items);
}
    else if (i == 6) {
        items << "..." << "TÉCNICO UNIVERSITARIO EN ENFERMERÍA AUXILIAR" << "TÉCNICO UNIVERSITARIO EN INSTALACIÓN DE REDES" << "TÉCNICO UNIVERSITARIO EN DESARROLLO DE APLICACIONES WEB" << "TÉCNICO UNIVERSITARIO EN DISEÑO DE INTERIORES" << "TÉCNICO UNIVERSITARIO BILINGÜE EN CALL CENTER" << "TÉCNICO UNIVERSITARIO EN INSTRUMENTACIÓN QUIRÚRGICA"<< "TÉCNICO UNIVERSITARIO EN URGENCIAS MÉDICAS" << "TÉCNICO UNIVERSITARIO BILINGÜE EN TURISMO"<< "TÉCNICO UNIVERSITARIO EN MARKETING DIGITAL" << "TÉCNICO UNIVERSITARIO EN DESARROLLO Y CUIDADO INFANTIL" << "TÉCNICO UNIVERSITARIO EN COMERCIALIZACIÓN Y PROMOCIÓN RETAIL"<< "TÉCNICO UNIVERSITARIO EN DISEÑO GRÁFICO" << "TÉCNICO UNIVERSITARIO EN ADMINISTRACIÓN";
        ui->cb_carreraE->addItems(items);
    }
}

void cframe::on_Rcb_usuario_currentIndexChanged(int i)
{
    QStringList items;
    ui->Rcb_cambiarE->clear();
    if (i == 1 || i == 2) { // jefe o coordinador
        items << "..." << "Cargar silabo (Enviar a IEDD)" << "Rechazar";
        ui->Rcb_cambiarE->addItems(items);
    } else if (i == 3) { // en IEDD
        items << "..." << "Listo para revision 1" << "Devolver a Academia";
        ui->Rcb_cambiarE->addItems(items);
    } else if (i == 4) { // consultor
        items << "...";
        ui->Rcb_cambiarE->addItems(items);
    }
}

void cframe::on_Rbtn_sesion_clicked()
{
    if (ui->Rle_name->text().isEmpty() || ui->Rle_clave->text().isEmpty() || ui->Rcb_usuario->currentIndex() == 0) {
        QMessageBox::warning(this, "Datos no congruentes", "Favor no deje campos sin completar");
    } else {
        if ((ui->Rcb_usuario->currentIndex() == 1 && ui->Rle_clave->text().toStdString() == claveJefe) ||
            (ui->Rcb_usuario->currentIndex() == 2 && ui->Rle_clave->text().toStdString() == claveCoordinador) ||
            (ui->Rcb_usuario->currentIndex() == 3 && ui->Rle_clave->text().toStdString() == claveIEDD) ||
            (ui->Rcb_usuario->currentIndex() == 4 && ui->Rle_clave->text().toStdString() == claveConsultor)) {

            ui->frameR->setVisible(true);
            ui->frameR1->setEnabled(false);
            loginRevision = true;
            ui->tab_2->setEnabled(false);
            ui->tab_4->setEnabled(false);
            ui->tab_5->setEnabled(false);
            pruebitaBotonesTab();
        } else {
            QMessageBox::warning(this, "Datos no congruentes", "Clave incorrecta");
        }
    }
}

void cframe::limpiarRevision()
{
    QStringList items;
    ui->Rle_comentario->clear();
    ui->Rle_seleccion->clear();
    ui->Rle_estadoA->clear();
    if (loginRevision) {
        ui->Rcb_cambiarE->setCurrentIndex(0);
    } else {
        ui->Rcb_cambiarE->clear();
        items << "...";
        ui->Rcb_cambiarE->addItems(items);
        ui->Rle_name->clear();
        ui->Rle_clave->clear();
        ui->Rcb_usuario->setCurrentIndex(0);
        ui->Rcb_cambiarE->setCurrentIndex(0);
        ui->frameR->setVisible(false);
        ui->frameR1->setEnabled(true);
    }
}

void cframe::on_Rbtn_cerrar_clicked()
{
    loginRevision = false;
    ui->RTW_revision->setRowCount(0);
    ui->tab_2->setEnabled(true);
    ui->tab_4->setEnabled(true);
    ui->tab_5->setEnabled(true);
    limpiarRevision();
    ui->tabWidget->setCurrentIndex(0);
}

void cframe::on_Rbtn_cambiar_clicked()
{
    if (ui->Rle_estadoA->text().isEmpty() || ui->Rle_seleccion->text().isEmpty()) {
        QMessageBox::warning(this, "Datos no congruentes", "No ha seleccionado qué editar");
    } else if (ui->Rle_comentario->text().isEmpty()) {
        QMessageBox::warning(this, "Datos no congruentes", "No olvide comentar");
    } else if (ui->Rcb_cambiarE->currentIndex() == 0) {
        QMessageBox::warning(this, "Datos no congruentes", "No ha seleccionado estado a cambiar");
    } else {
        cambiarEstado = true;
        modificarDatosSilabo(arbolSilabo->getRaiz(), id, "QString pathNuevo");
        QMessageBox::information(this, "Datos congruentes", "Datos han sido actualizados");
        limpiarRevision();
    }
}

void cframe::cambiarSilabo(int id, QString pathActual)
{
    QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos PDF", QDir::homePath(), "PDF Files (*.pdf)");
    if (pathActual == filePath) { // buscar en el árbol
        QMessageBox::warning(this, "No posible", "Ha seleccionado el mismo silabo");
    } else if (!filePath.isEmpty()) {
        cambiarPath = true;
        modificarDatosSilabo(arbolSilabo->getRaiz(), id, filePath);
    } else {
        QMessageBox::warning(this, "No posible", "No ha seleccionado");
    }
}

void cframe::modificarDatosSilabo(NodoArbolB *nodo, int id, QString pathNuevo)
{
    if (nodo == nullptr) {
        return;
    }
    modificarDatosSilabo(nodo->getChild(0), id, pathNuevo); // Recursión en el hijo izquierdo

    for (int i = 0; i < nodo->getN(); i++) {
        Silabo *silabo = nodo->getSilabo(i);
        if (silabo->getId() == id) {
            if (cambiarPath) {
                silabo->setRuta(pathNuevo);
                cambiarPath = false;
            }
            if (cambiarEstado) {
                silabo->setEstado(static_cast<Estado>(ui->Rcb_cambiarE->currentIndex() - 1));
                silabo->setObservacion(ui->Rle_comentario->text().toStdString());
                cambiarEstado = false;
            }
        }
    }

    modificarDatosSilabo(nodo->getChild(nodo->getN()), id, pathNuevo); // Recursión en el hijo derecho
}

string cframe::obtenerNombre(std::string cuenta)
{
    nodoD<Usuario> *actD = listaUsuarios.PrimPtr;
    while (actD != nullptr) {
        if (cuenta == actD->Dato.cuenta) {
            return actD->Dato.name;
        }
        actD = actD->SigPtr;
    }
    return "...";
}

void cframe::pruebitaBotonesTab()
{
    ui->RTW_revision->clearContents();
    ui->RTW_revision->setRowCount(0);

    ui->RTW_revision->setColumnCount(13); // tab 2 tw_doble

    ui->RTW_revision->setHorizontalHeaderLabels(QStringList() << "MODIFICAR" << "VER DOCX" << "ORDEN DE INGRESO" << "ESTADO" << "INGRESADO POR" << "# CUENTA" << "FACULTAD" << "CARRERA" << "CODIGO CLASE" << "PATH" << "OBSERVACION" << "RELOAD" << "# REVISIONES");
    int fila = 0;

    recorrerArbolParaTabla(arbolSilabo->getRaiz(), fila, listaUsuarios.PrimPtr);
}

void cframe::recorrerArbolParaTabla(NodoArbolB *nodo, int &fila, nodoD<Usuario> *actD)
{
    if (nodo == nullptr || actD == nullptr) {
        return;
    }

    recorrerArbolParaTabla(nodo->getChild(0), fila, actD);

    for (int i = 0; i < nodo->getN(); i++) {
        Silabo *silabo = nodo->getSilabo(i);
        bool mostrar = false;

        if ((ui->Rcb_usuario->currentIndex() == 1 || ui->Rcb_usuario->currentIndex() == 2) && (estadoToString(silabo->getEstado()) == "Prerevision" || estadoToString(silabo->getEstado()) == "DevueltoAcademia")) {
            mostrar = true;
        } else if (ui->Rcb_usuario->currentIndex() == 3 && (estadoToString(silabo->getEstado()) == "ListoRevision" || estadoToString(silabo->getEstado()) == "CorrecionMayor" || estadoToString(silabo->getEstado()) == "CorrecionMenor" || estadoToString(silabo->getEstado()) == "AprobadoCondicion")) {
            mostrar = true;
        } else if (ui->Rcb_usuario->currentIndex() == 4 && (estadoToString(silabo->getEstado()) == "ListoRevision" || estadoToString(silabo->getEstado()) == "Aprobado" || estadoToString(silabo->getEstado()) == "AprobadoCondicion")) {
            mostrar = true;
        }

        if (mostrar) {
            ui->RTW_revision->setRowCount(fila + 1);
            ui->RTW_revision->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString("EDITAR")));
            ui->RTW_revision->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString("VER")));
            ui->RTW_revision->setItem(fila, 2, new QTableWidgetItem(QString::number(silabo->getId())));
            ui->RTW_revision->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(estadoToString(silabo->getEstado()))));
            ui->RTW_revision->setItem(fila, 4, new QTableWidgetItem(QString::fromStdString(obtenerNombre(silabo->getInsertadoPor()))));
            ui->RTW_revision->setItem(fila, 5, new QTableWidgetItem(QString::fromStdString(silabo->getInsertadoPor())));
            ui->RTW_revision->setItem(fila, 6, new QTableWidgetItem(QString::fromStdString(silabo->getFacultad())));
            ui->RTW_revision->setItem(fila, 7, new QTableWidgetItem(QString::fromStdString(silabo->getCarrera())));
            ui->RTW_revision->setItem(fila, 8, new QTableWidgetItem(QString::fromStdString(silabo->getCodigoClase())));
            ui->RTW_revision->setItem(fila, 9, new QTableWidgetItem(silabo->getRuta()));
            ui->RTW_revision->setItem(fila, 10, new QTableWidgetItem(QString::fromStdString(silabo->getObservacion())));
            ui->RTW_revision->setItem(fila, 11, new QTableWidgetItem(QString::fromStdString("NUEVO SILABO")));
            ui->RTW_revision->setItem(fila, 12, new QTableWidgetItem(QString::number(silabo->getNumeroderevisiones())));

            fila++;
        }
    }

    recorrerArbolParaTabla(nodo->getChild(nodo->getN()), fila, actD);
}

void cframe::on_RTW_revision_cellClicked(int row, int column)
{
    if (column == 0) {
        QString dato = ui->RTW_revision->item(row, 8)->text() + "    Observacion:" + ui->RTW_revision->item(row, 10)->text();
        id = ui->RTW_revision->item(row, 2)->text().toInt();
        ui->Rle_seleccion->setText(dato);
        QString estado = ui->RTW_revision->item(row, 3)->text();
        ui->Rle_estadoA->setText(estado);

        if (ui->Rcb_usuario->currentIndex() == 4) {
            QStringList items;
            ui->Rcb_cambiarE->clear();
            if (ui->RTW_revision->item(row, 3)->text().toStdString() == "Aprobado") {
                items << "..." << "Aprobar" << "Aprobado con condicion";
            } else {
                items << "..." << "Aprobado" << "Correcion Mayor" << "Correcion Menor";
            }
            ui->Rcb_cambiarE->addItems(items);
        }
    } else if (column == 1) {
        QString selectedFilePath = ui->RTW_revision->item(row, 9)->text();
        QDesktopServices::openUrl(QUrl::fromLocalFile(selectedFilePath));
    } else if (column == 11) {
        cambiarSilabo(ui->RTW_revision->item(row, 2)->text().toInt(), ui->RTW_revision->item(row, 9)->text());
    }
}

void cframe::on_Bbtn_sesion_clicked()
{
    if (ui->Ble_name->text().isEmpty() || ui->Ble_clave->text().isEmpty() || ui->Bcb_usuario->currentIndex() == 0) {
        QMessageBox::warning(this, "Datos no congruentes", "Favor no deje campos sin completar");
    } else {
        if ((ui->Bcb_usuario->currentIndex() == 1 && ui->Ble_clave->text().toStdString() == claveDirector) ||
            (ui->Bcb_usuario->currentIndex() == 2 && ui->Ble_clave->text().toStdString() == claveDecano)) {

            ui->frameB->setVisible(true);
            ui->frameB1->setEnabled(false);
            loginBoard = true;
            ui->tab_3->setEnabled(false);
            ui->tab_2->setEnabled(false);

            // Limpiar el QTableWidget antes de agregar nuevos datos
            ui->tableWidget->clear();
            ui->tableWidget->setRowCount(0); // Limpiar todas las filas existentes

            // Agregar encabezados de columna al QTableWidget
            QStringList headers;
            headers << "Facultad" << "Carrera" << "Numero de Cuenta" << "Código de Clase" << "Ruta" << "Estado" << "Observación" << "ID" << "Número de Revisiones";
            ui->tableWidget->setColumnCount(headers.size());
            ui->tableWidget->setHorizontalHeaderLabels(headers);

            // Llamar a la función para agregar datos al QTableWidget
            recorrerArbolParaTable(arbolSilabo->getRaiz(), ui->tableWidget, "Prerevision");

        } else {
            QMessageBox::warning(this, "Datos no congruentes", "Clave incorrecta");
        }
    }
}

void cframe::on_Bbtn_aceptados_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QStringList headers;
    headers << "Facultad" << "Carrera" << "Numero de Cuenta" << "Código de Clase" << "Ruta" << "Estado" << "Observación" << "ID" << "Número de Revisiones";
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    recorrerArbolParaTable(arbolSilabo->getRaiz(), ui->tableWidget, "Aprobado");
}

void cframe::on_Bbtn_proceso_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QStringList headers;
    headers << "Facultad" << "Carrera" << "Numero de Cuenta" << "Código de Clase" << "Ruta" << "Estado" << "Observación" << "ID" << "Número de Revisiones";
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    recorrerArbolParaTable(arbolSilabo->getRaiz(), ui->tableWidget, "n");
}

void cframe::recorrerArbolParaTable(NodoArbolB *nodo, QTableWidget *tableWidget, const std::string &estadoMostrar)
{
    if (nodo == nullptr) {
        return;
    }

    recorrerArbolParaTable(nodo->getChild(0), tableWidget, estadoMostrar);

    for (int i = 0; i < nodo->getN(); i++) {
        Silabo *silabo = nodo->getSilabo(i);

        if ((estadoMostrar == "Aprobado" && estadoToString(silabo->getEstado()) == "Aprobado") ||
            (estadoMostrar != "Aprobado" && estadoToString(silabo->getEstado()) != "Aprobado")) {

            int row = tableWidget->rowCount();
            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(silabo->getFacultad())));
            tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(silabo->getCarrera())));
            tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(silabo->getInsertadoPor())));
            tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(silabo->getCodigoClase())));
            tableWidget->setItem(row, 4, new QTableWidgetItem(silabo->getRuta()));
            tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(estadoToString(silabo->getEstado()))));
            tableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(silabo->getObservacion())));
            tableWidget->setItem(row, 7, new QTableWidgetItem(QString::number(silabo->getId())));
            tableWidget->setItem(row, 8, new QTableWidgetItem(QString::number(silabo->getNumeroderevisiones())));
        }
    }

    recorrerArbolParaTable(nodo->getChild(nodo->getN()), tableWidget, estadoMostrar);
}

void cframe::on_Bbtn_cerrar_clicked()
{
    loginBoard = false;
    limpiarBoard();
}

void cframe::limpiarBoard()
{
    ui->Ble_name->clear();
    ui->Ble_clave->clear();
    ui->Bcb_usuario->setCurrentIndex(0);
    ui->tab_3->setEnabled(true);
    ui->tab_2->setEnabled(true);
    ui->tab_5->setEnabled(true);
    ui->frameB->setVisible(false);
    ui->frameB1->setEnabled(true);
}

void cframe::on_Dbtn_sesion_clicked()
{
    if (ui->Dle_clave->text().isEmpty() || ui->Dle_cuenta->text().isEmpty() || ui->Dle_name->text().isEmpty()) {
        QMessageBox::warning(this, "Datos incompletos", "Favor, no deje campos vacíos");
    } else if (ui->Dle_clave->text().toStdString() != claveDocente) {
        QMessageBox::warning(this, "Datos incongruentes", "Clave incorrecta");
    } else {
        string name = obtenerNombre(ui->Dle_cuenta->text().toStdString());
        if (name == "...") {
            QMessageBox::warning(this, "Datos incongruentes", "Número de cuenta o usuario incorrectos");
        } else {
            if (name != ui->Dle_name->text().toStdString()) {
                QMessageBox::warning(this, "Datos incongruentes", "Número de cuenta o usuario incorrectos");
            } else {
                loginCheck = true;
                ui->tab_3->setEnabled(false);
                ui->tab_2->setEnabled(false);
                ui->tab_4->setEnabled(false);
                ui->Dframe2->setVisible(true);
                ui->Dbtn_salir->setVisible(true);

                ui->DRTW_revision->clearContents();
                ui->DRTW_revision->setColumnCount(10); // tab 2 tw_doble
                ui->DRTW_revision->setHorizontalHeaderLabels(QStringList() << "VER DOCX" << "ORDEN DE INGRESO" << "INGRESADO POR" << "# CUENTA" << "FACULTAD" << "CARRERA" << "CODIGO CLASE" << "OBSERVACION" << "PATH" << "RELOAD");
                mostrarDocente(arbolSilabo->getRaiz(), 0, ui->Dle_cuenta->text().toStdString());
            }
        }
    }
}

void cframe::mostrarDocente(NodoArbolB *nodo, int fila, string numCuenta)
{
    if (nodo == nullptr) {
        return;
    }

    mostrarDocente(nodo->getChild(0), fila, numCuenta);

    for (int i = 0; i < nodo->getN(); i++) {
        Silabo *silabo = nodo->getSilabo(i);

        if (numCuenta == silabo->getInsertadoPor() && (estadoToString(silabo->getEstado()) == "Rechazar" || estadoToString(silabo->getEstado()) == "Aprobado")) {
            ui->DRTW_revision->setRowCount(fila + 1);
            ui->DRTW_revision->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString("VER")));
            ui->DRTW_revision->setItem(fila, 1, new QTableWidgetItem(QString::number(silabo->getId())));
            ui->DRTW_revision->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(obtenerNombre(silabo->getInsertadoPor()))));
            ui->DRTW_revision->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(silabo->getInsertadoPor())));
            ui->DRTW_revision->setItem(fila, 4, new QTableWidgetItem(QString::fromStdString(silabo->getFacultad())));
            ui->DRTW_revision->setItem(fila, 5, new QTableWidgetItem(QString::fromStdString(silabo->getCarrera())));
            ui->DRTW_revision->setItem(fila, 6, new QTableWidgetItem(QString::fromStdString(silabo->getCodigoClase())));
            ui->DRTW_revision->setItem(fila, 7, new QTableWidgetItem(QString::fromStdString(silabo->getObservacion())));
            ui->DRTW_revision->setItem(fila, 8, new QTableWidgetItem(silabo->getRuta()));
            ui->DRTW_revision->setItem(fila, 9, new QTableWidgetItem(QString::fromStdString("NUEVO SILABO")));

            fila++;
        }
    }

    mostrarDocente(nodo->getChild(nodo->getN()), fila, numCuenta);
}

void cframe::on_Dbtn_salir_clicked()
{
    ui->DRTW_revision->clear();
    ui->Dle_clave->clear();
    ui->Dle_cuenta->clear();
    ui->Dle_name->clear();
    ui->tab_3->setEnabled(true);
    ui->tab_2->setEnabled(true);
    ui->tab_4->setEnabled(true);
    ui->Dframe2->setVisible(false);
    loginCheck = false;
    ui->Dbtn_salir->setVisible(false);
}

void cframe::on_DRTW_revision_cellClicked(int row, int column)
{
    if (column == 0) {
        QString selectedFilePath = ui->DRTW_revision->item(row, 8)->text();
        QDesktopServices::openUrl(QUrl::fromLocalFile(selectedFilePath));
    } else if (column == 9) {
        cambiarSilabo(ui->DRTW_revision->item(row, 1)->text().toInt(), ui->DRTW_revision->item(row, 8)->text());
    }
}

std::string cframe::estadoToString(Estado estado) const {
    switch (estado) {
    case Prerevision: return "Prerevision";
    case ListoRevision: return "ListoRevision";
    case Aprobado: return "Aprobado";
    case AprobadoCondicion: return "AprobadoCondicion";
    case SolicitudCambio: return "SolicitudCambio";
    case DevueltoAcademia: return "DevueltoAcademia";
    case Correcion: return "Correcion";
    case CorrecionMayor: return "CorrecionMayor";
    case CorrecionMenor: return "CorrecionMenor";
    default: return "Desconocido";
    }
}

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
#include <QFileInfo>

using std::ofstream;
using std::ios;
using std::string;

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);

    QImage menu(":/new/prefix1/imInicio.jpg");
    ui->lbl_pngM->setPixmap(QPixmap::fromImage(menu));
    ui->Dlabel->setStyleSheet("background-color: #062458;");
    ui->Dlabel2->setStyleSheet("background-color: #062458;");

    QImage entrega(":/new/prefix1/imEntrega.jpg");
    ui->lbl_pngE->setPixmap(QPixmap::fromImage(entrega));

    QImage revision(":/new/prefix1/imRevision.jpg");
    ui->lbl_pngR->setPixmap(QPixmap::fromImage(revision));

    QImage board(":/new/prefix1/imBoard.jpg");
    ui->lbl_pngB->setPixmap(QPixmap::fromImage(board));

    QImage docente(":/new/prefix1/imDocente.jpg");
    ui->lbl_pngD->setPixmap(QPixmap::fromImage(docente));

    QImage registro(":/new/prefix1/imRegistro.jpg");
    ui->lbl_pngRegistrar->setPixmap(QPixmap::fromImage(registro));


    ui->frameE->setVisible(true);
    ui->frameR->setVisible(true);
    ui->frameB->setVisible(true);
    ui->Dframe2->setVisible(true);
    ui->Dbtn_salir->setVisible(true);

    connect(ui->RTW_revision, &QTableWidget::cellDoubleClicked, this, &cframe::on_btn_revision_2_clicked);

    // -= Cargar usuarios desde la DB =-
    DB.loadUsers(listaUsuarios);
    DB.loadSilabos(arbolSilabo);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(ui->tabWidget);
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    ui->tabWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->tabWidget->setMinimumSize(800, 600);

    //USUARIO GLOBAL CON ACCESO A TODAS LAS TABS
    Usuario UA("Ceutec","010101","admin","CEUTEC","GLOBAL","Relaciones Internacionales");
    Usuario u("Unitec", "101010", "admin", "UNITEC", "GLOBAL", "Ingenieria en Sistemas Computacionales");

    Usuario B("Jefe","111111","passboss","UNITEC","Jefe", "Ingenieria en Mecatronica");
    Usuario I("IEDD","222222","passiedd","UNITEC","IEDD", "Ingenieria en Mecatronica");
    Usuario C("Coordinador","3333333","passcord","UNITEC","Coordinador", "Ingenieria en Mecatronica");
    Usuario D("Docente","000000","passteacher","UNITEC","Docente", "Ingenieria en Mecatronica");
    Usuario CC("Consultor","444444","passcost","UNITEC","Consultor", "Ingenieria en Mecatronica");
    Usuario DD("Decano","555555","passdean","UNITEC","Decano", "Ingenieria en Mecatronica");
    Usuario DI("Director","666666","passdirector","UNITEC","Director", "Ingenieria en Mecatronica");

    listaUsuarios.InsertarFin(u);
    listaUsuarios.InsertarFin(B);
    listaUsuarios.InsertarFin(I);
    listaUsuarios.InsertarFin(C);
    listaUsuarios.InsertarFin(D);
    listaUsuarios.InsertarFin(CC);
    listaUsuarios.InsertarFin(DD);
    listaUsuarios.InsertarFin(DI);
    listaUsuarios.InsertarFin(UA);

    desactivarTabs();
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
    if (hayUsuarioLogeado == true){

        if(index==2){ // Tab revision
            pruebitaBotonesTab();
        }else if(index==3){ // Tab board

            // Limpiar el QTableWidget antes de agregar nuevos datos
            ui->tableWidget->clear();
            ui->tableWidget->setRowCount(0); // Limpiar todas las filas existentes

            // Agregar encabezados de columna al QTableWidget
            QStringList headers;
            headers << "Facultad" << "Carrera" << "Numero de Cuenta" << "Código de Clase" << "Ruta" << "Estado" << "Observación" << "ID" << "Número de Revisiones";
            ui->tableWidget->setColumnCount(headers.size());
            ui->tableWidget->setHorizontalHeaderLabels(headers);
            //DB.loadSilabos(arbolSilabo);----->comente aqui

            // recorrerArbolParaTable(arbolSilabo->getRaiz(), ui->tableWidget, "Prerevision");
        }else if(index==4){ // Tab docente
            loginCheck = true;
            ui->Dframe2->setVisible(true);
            ui->Dbtn_salir->setVisible(true);

            ui->DRTW_revision->clearContents();
            ui->DRTW_revision->setColumnCount(9); // tab 2 tw_doble
            ui->DRTW_revision->setHorizontalHeaderLabels(QStringList() << "VER DOCX" << "ORDEN DE INGRESO"
                                                         << "INGRESADO POR" << "ESTADO"
                                                         << "CARRERA" << "CODIGO CLASE" << "RUTA"
                                                         << "# REVISIONES" << "CUADRO FECHAS");

            mostrarDocente(arbolSilabo->getRaiz(), 0, usuarioActual->getCuenta());
        }

        if (index == 5){
            mostrarUsuarios();
        }
    }
}

void cframe::on_btn_sesion_clicked()
{
    ui->tabWidget->tabBar()->show();
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
            QStringList items;

            //Habilitar tabs correspondientes al usuario
            if (usuarioActual->getTipo() == "Docente"){
                desactivarTabs();
                ui->tabWidget->setTabEnabled(1, true);
                ui->tabWidget->setTabEnabled(4, true);

            }else if(usuarioActual->getTipo() == "Coordinador"){
                desactivarTabs();
                ui->tabWidget->setTabEnabled(2, true);
                items << "Cargar silabo (Enviar a IEDD)" << "Rechazar";
                ui->Rcb_cambiarE->addItems(items);

            }else if(usuarioActual->getTipo() == "IEDD"){
                desactivarTabs();
                ui->tabWidget->setTabEnabled(2, true);
                ui->tabWidget->setTabEnabled(5, true);
                items << "Listo para revision 1" << "Devolver a Academia";
                ui->Rcb_cambiarE->addItems(items);
            }else if(usuarioActual->getTipo() == "Consultor"){
                desactivarTabs();
                ui->tabWidget->setTabEnabled(2, true);
                items << "...";
                ui->Rcb_cambiarE->addItems(items);

            }else if(usuarioActual->getTipo()=="Jefe"){
                desactivarTabs();
                ui->tabWidget->setTabEnabled(2, true);
                loginRevision=true;
                items << "Cargar silabo (Enviar a IEDD)" << "Rechazar";
                ui->Rcb_cambiarE->addItems(items);

            }else if(usuarioActual->getTipo() == "Decano"){
                desactivarTabs();
                ui->tabWidget->setTabEnabled(3, true);
            }else if(usuarioActual->getTipo() == "Director"){
                desactivarTabs();
                ui->tabWidget->setTabEnabled(3, true);
            }else if(usuarioActual->getTipo() == "GLOBAL"){
                activarTabs(); // ACTIVAR TODOS LOS TABS PARA EL USUARIO GLOBAL
                loginRevision = true;
            }

            if(usuarioActual->getInstitucion()=="UNITEC"){
                quitarBotonCuadroFecha(false);
            }else{
                quitarBotonCuadroFecha(true);
            }

            ui->le_cuentaE->setText("");
            ui->le_claveE->setText("");
            //Por mientras para saber que tipo de usuario esta ingresando
            QMessageBox::warning(this, "Tipo usuario", QString::fromStdString(usuarioActual->getTipo()));
            ui->tab->setEnabled(false);
            hayUsuarioLogeado = true;
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
    desactivarTabs();
    ui->tab->setEnabled(true);
    ui->tabWidget->tabBar()->hide();
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
        ui->le_nombreClase->clear();
        ui->cb_facultadE->setCurrentIndex(0);
        ui->cb_carreraE->setCurrentIndex(0);
    }
}

// ======================= Boton entregar silabo ==================
void cframe::on_btn_silaboE_clicked()
{
    if (ui->cb_facultadE->currentIndex() == 0 || ui->cb_carreraE->currentIndex() == 0 || ui->le_codigoE->text().isEmpty() || ui->le_pathE->text().isEmpty() || (ui->le_pathCF->text().isEmpty() && usuarioActual->institucion == "UNITEC")) {
        QMessageBox::warning(this, "Datos no congruentes", "Favor no deje campos sin completar");
        return;
    }

    cantSilabos = this->arbolSilabo->getCantidadArbol() + 1; // id sería cantidad en árbol más uno

    string facultad = ui->cb_facultadE->currentText().toStdString();
    string carrera = ui->cb_carreraE->currentText().toStdString();
    QString path = ui->le_pathE->text();
    QString pathCuadro = ui->le_pathCF->text();
    QFileInfo fileInfo(path);
    QFileInfo fileInfoCuadro(pathCuadro);

    // Verificar que usuarioActual no sea nullptr
    if (!usuarioActual) {
        QMessageBox::critical(this, "Error", "Usuario no autenticado.");
        return;
    }

    CuadroFechas *cuadroFechas = nullptr;
    Silabo *nuevoSilabo = nullptr;

    if (usuarioActual->getInstitucion() == "CEUTEC") {
        nuevoSilabo = new Silabo(cantSilabos, fileInfo.fileName().toStdString(), Estado(Prerevision), "...", 0,
                                 facultad, carrera, ui->le_codigoE->text().toStdString(),
                                 ui->le_nombreClase->text().toStdString(), usuarioActual->getCuenta(), usuarioActual->getInstitucion(), cuadroFechas);
    } else {
        cuadroFechas = new CuadroFechas(cantCuadroFechas, fileInfoCuadro.fileName().toStdString(), Estado(Prerevision), "...", 0, cantSilabos);
        cantCuadroFechas++;
        nuevoSilabo = new Silabo(cantSilabos, fileInfo.fileName().toStdString(), Estado(Prerevision), "...", 0,
                                 facultad, carrera, ui->le_codigoE->text().toStdString(),
                                 ui->le_nombreClase->text().toStdString(), usuarioActual->getCuenta(), usuarioActual->getInstitucion(), cuadroFechas);
    }
    cantSilabos++;

    if (nuevoSilabo == nullptr) {
        QMessageBox::critical(this, "Error", "No se pudo crear el objeto Silabo.");
        return;
    }

    if (cuadroFechas != nullptr) {
        DB.saveCuadroFechas(cuadroFechas, pathCuadro.toStdString(), fileInfoCuadro.fileName().toStdString());
    }


    DB.saveSilabo(nuevoSilabo, path.toStdString());
    this->arbolSilabo->insertar(nuevoSilabo);

    //arbolSilabo->mostrarDetallesSilabos(*arbolSilabo);

    // Mantener la opción de entrega visible después de insertar
    limpiarEntrega();

    // Asegurar visibilidad de los elementos relacionados
    ui->frameE->setVisible(true);
    ui->frameE2_2->setEnabled(true);
    QMessageBox::information(this, "Enviado", "Datos han sido enviados");

    // QMessageBox::warning(this, "Institucion", QString::fromStdString(usuarioActual->getInstitucion()));
    // QMessageBox::warning(this, "Institucion", QString::fromStdString(nuevoSilabo->getInstitucion()));
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

        if (usuarioActual->getInstitucion() == "UNITEC") {
            ui->le_pathCF->clear();
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
        //        ui->Rle_name->clear();
        //        ui->Rle_clave->clear();
        //        ui->Rcb_usuario->setCurrentIndex(0);
        ui->Rcb_cambiarE->setCurrentIndex(0);
        // ui->frameR1->setEnabled(true);
    }
}

void cframe::on_Rbtn_cerrar_clicked()
{
    loginRevision = false;
    ui->RTW_revision->setRowCount(0);
    ui->tab_2->setEnabled(true);
    ui->tab_4->setEnabled(true);
    ui->tab_5->setEnabled(true);
    ui->tab->setEnabled(true);
    limpiarRevision();
    ui->tabWidget->setCurrentIndex(0);
    desactivarTabs();
    ui->tabWidget->tabBar()->hide();
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
    QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos Word Documents", QDir::homePath(), "Word Files (*.docx)");

    if (!filePath.isEmpty()) {
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
                silabo->settRuta(pathNuevo.toStdString());
                cambiarPath = false;
            }
            if (cambiarEstado) {
                string nuevoEstado = ui->Rcb_cambiarE->currentText().toStdString();
                Estado status(Aprobado); // dummy

                // cuando lo tiene el jefe o el coordinador (lo manda a iedd o regresa a docente)
                if (nuevoEstado == "Cargar silabo (Enviar a IEDD)"){
                    status = Estado(ListoRevision);
                }
                if (nuevoEstado == "Rechazar"){
                    status = Estado(Prerevision);
                }


                // cuando lo tiene alguien de iedd (lo manda a consultor o regresa a jefe o coordinador)
                if (nuevoEstado == "Listo para revision 1"){
                    status = Estado(AprobadoIEDD);
                }
                if (nuevoEstado == "Devolver a Academia"){
                    status = Estado(Prerevision);
                }

                // cuando lo tiene un consultor (lo manda a director o decano)
                if (nuevoEstado == "Aprobado con condicion"){
                    status = Estado(AprobadoCondicion);
                }
                //No se pone el de aprobado porque del combobox ya se saca el texto de Aprobado

                QMessageBox::information(this,"Cosa", QString::fromStdString(nuevoEstado)); // para ver a que estado esta cambiando
                string nuevaObservacion=ui->Rle_comentario->text().toStdString();

                silabo->setEstado(status);
                silabo->setObservacion(nuevaObservacion);
                pruebitaBotonesTab();

                DB.updateSilabo(silabo);

                cambiarEstado = false;
                return;
            }
        }
    }

    modificarDatosSilabo(nodo->getChild(nodo->getN()), id, pathNuevo); // Recursión en el hijo derecho
}

Usuario* cframe::obtenerUsuario(std::string cuenta)
{
    nodoD<Usuario> *actD = listaUsuarios.PrimPtr;
    while (actD != nullptr) {
        if (cuenta == actD->Dato.cuenta) {
            return &actD->Dato;
        }
        actD = actD->SigPtr;
    }
    return nullptr;
}

void cframe::pruebitaBotonesTab()
{
    ui->RTW_revision->clearContents();
    ui->RTW_revision->setRowCount(0);

    ui->RTW_revision->setColumnCount(13); // tab 2 tw_doble

    if (usuarioActual->getInstitucion() == "CEUTEC"){
        ui->RTW_revision->setHorizontalHeaderLabels(QStringList() << "MODIFICAR" << "VER SILABO" << "ORDEN DE INGRESO" << "ESTADO" << "INGRESADO POR" << "# CUENTA" << "FACULTAD" << "CARRERA" << "CODIGO CLASE" << "PATH" << "OBSERVACION" << "RELOAD" << "# REVISIONES");
    }else{
        ui->RTW_revision->setHorizontalHeaderLabels(QStringList() << "MODIFICAR" << "VER SILABO" << "VER CUADRO"<< "ORDEN DE INGRESO" << "ESTADO" << "INGRESADO POR" << "# CUENTA" << "FACULTAD" << "CARRERA" << "CODIGO CLASE" << "PATH SILABO" <<"PATH CUADRO" << "OBSERVACION" << "RELOAD" << "# REVISIONES");
    }
    int fila = 0;
    //DB.loadSilabos(arbolSilabo->getRaiz());------>comente aqui
    recorrerArbolParaTabla(arbolSilabo->getRaiz(), fila, listaUsuarios.PrimPtr);
}

void cframe::desactivarTabs()
{
    // Desactivar todas las pestañas menos la del login
    for (int i = 1; i < ui->tabWidget->count(); ++i) {
        ui->tabWidget->setTabEnabled(i, false);
    }
}

void cframe::activarTabs()
{
    // Activar todas las pestañas
    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        ui->tabWidget->setTabEnabled(i, true);
    }
}

void cframe::quitarBotonCuadroFecha(bool estado)
{
    ui->btn_archivoCF->setHidden(estado);
    ui->le_pathCF->setHidden(estado);
    ui->lbl_archivoCF->setHidden(estado);
}

void cframe::recorrerArbolParaTabla(NodoArbolB *nodo, int &fila, nodoD<Usuario> *actD)
{
    if (nodo == nullptr || actD == nullptr) {
        return;
    }

    recorrerArbolParaTabla(nodo->getChild(0), fila, actD);

    string tipoUsuario = (usuarioActual != nullptr) ? usuarioActual->getTipo(): "";



    for (int i = 0; i < nodo->getN(); i++) {
        Silabo *silabo = nodo->getSilabo(i);
        bool mostrar = false;

        if ((tipoUsuario == "Jefe" || tipoUsuario == "Coordinador") &&
                (silabo->getEstado() == Estado(Prerevision) || silabo->getEstado() == Estado(DevueltoAcademia))) {
            mostrar = true;
        } else if (tipoUsuario == "IEDD" &&
                   ((silabo->getEstado()) == Estado(ListoRevision) || (silabo->getEstado()) == Estado(CorrecionMayor) || (silabo->getEstado()) == Estado(CorrecionMenor) || (silabo->getEstado()) == Estado(AprobadoCondicion))) {
            mostrar = true;
        } else if (tipoUsuario == "Consultor" &&
                   ((silabo->getEstado()) == Estado(AprobadoIEDD) || (silabo->getEstado()) == Estado(AprobadoCondicion))) {
            mostrar = true;
        }

        EstadoNombres nombres;
        Usuario *u = obtenerUsuario(silabo->getSubidoPor());
        if (mostrar) {

            /* Columnas
             * MODIFICAR, VER DOCX, ORDEN DE INGRESO (ID), INGRESADO POR, #CUENTA, FACULTAD, CARRERA, CODIGO CLASE,
             * PATH, OBSERVACION, RELOAD, # REVISIONES
             */


            string path = silabo->getNombreArchivo();


            if (usuarioActual->getInstitucion() == "CEUTEC"){
                ui->RTW_revision->setRowCount(fila + 1);
                ui->RTW_revision->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString("EDITAR")));
                ui->RTW_revision->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString("VER")));
                ui->RTW_revision->setItem(fila, 2, new QTableWidgetItem(QString::number(silabo->getId())));
                ui->RTW_revision->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(( nombres.nombres[silabo->getEstado()] ))));
                ui->RTW_revision->setItem(fila, 4, new QTableWidgetItem(QString::fromStdString( u->getName() )));
                ui->RTW_revision->setItem(fila, 5, new QTableWidgetItem(QString::fromStdString( u->getCuenta() )));
                ui->RTW_revision->setItem(fila, 6, new QTableWidgetItem(QString::fromStdString( silabo->getFacultad() )));
                ui->RTW_revision->setItem(fila, 7, new QTableWidgetItem(QString::fromStdString( silabo->getCarrera() )));
                ui->RTW_revision->setItem(fila, 8, new QTableWidgetItem(QString::fromStdString( silabo->getCodigoClase()) ));
                ui->RTW_revision->setItem(fila, 9, new QTableWidgetItem(QString::fromStdString( path )));
                ui->RTW_revision->setItem(fila, 10, new QTableWidgetItem(QString::fromStdString( silabo->getObservacion() )));
                ui->RTW_revision->setItem(fila, 11, new QTableWidgetItem( QString::fromStdString("...") ));
                ui->RTW_revision->setItem(fila, 12, new QTableWidgetItem(QString::number(silabo->getRevisiones())));

            }else{
                //string pathCuadro = silabo->getCuadrofechas()->getNombreArchivo();
                ui->RTW_revision->setRowCount(fila + 1);
                ui->RTW_revision->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString("EDITAR")));
                ui->RTW_revision->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString("VER")));
                ui->RTW_revision->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString("VER")));
                ui->RTW_revision->setItem(fila, 3, new QTableWidgetItem(QString::number(silabo->getId())));
                ui->RTW_revision->setItem(fila, 4, new QTableWidgetItem(QString::fromStdString(( nombres.nombres[silabo->getEstado()] ))));
                ui->RTW_revision->setItem(fila, 5, new QTableWidgetItem(QString::fromStdString( u->getName() )));
                ui->RTW_revision->setItem(fila, 6, new QTableWidgetItem(QString::fromStdString( u->getCuenta() )));
                ui->RTW_revision->setItem(fila, 7, new QTableWidgetItem(QString::fromStdString( silabo->getFacultad() )));
                ui->RTW_revision->setItem(fila, 8, new QTableWidgetItem(QString::fromStdString( silabo->getCarrera() )));
                ui->RTW_revision->setItem(fila, 9, new QTableWidgetItem(QString::fromStdString( silabo->getCodigoClase()) ));
                ui->RTW_revision->setItem(fila, 10, new QTableWidgetItem(QString::fromStdString( path )));
                //ui->RTW_revision->setItem(fila, 11, new QTableWidgetItem(QString::fromStdString( pathCuadro )));
                ui->RTW_revision->setItem(fila, 12, new QTableWidgetItem(QString::fromStdString( silabo->getObservacion() )));
                ui->RTW_revision->setItem(fila, 13, new QTableWidgetItem( QString::fromStdString("...") ));
                ui->RTW_revision->setItem(fila, 14, new QTableWidgetItem(QString::number(silabo->getRevisiones())));

            }

            fila++;
        }
    }

    recorrerArbolParaTabla(nodo->getChild(nodo->getN()), fila, actD);
}

void cframe::on_RTW_revision_cellClicked(int row, int column)
{
    if (column == 0) {
        QString dato = ui->RTW_revision->item(row, 8)->text() + "    Observacion:" + ui->RTW_revision->item(row, 10)->text();
        id = ui->RTW_revision->item(row, 3)->text().toInt();
        ui->Rle_seleccion->setText(dato);
        QString estado = ui->RTW_revision->item(row, 4)->text();
        ui->Rle_estadoA->setText(estado);

        std::string tipoUsuario = usuarioActual->getTipo();

        if (tipoUsuario == "Consultor") {
            QStringList items;
            ui->Rcb_cambiarE->clear();
            if (ui->RTW_revision->item(row,4)->text().toStdString()=="Aprobado") {
                items << "..." << "Aprobar" << "Aprobado con condicion";
            } else {
                items << "..." << "Aprobado" << "Correcion Mayor" << "Correcion Menor";
            }
            ui->Rcb_cambiarE->addItems(items);
        }
    } else if (column == 1) {
        int silaboId = ui->RTW_revision->item(row, 3)->text().toInt();
        // Write the file to the local system from the database
        if (Database().writeFiles(silaboId)) {
            // If successfully written, open the file
            QString path = QDir::home().filePath("silabos/" + ui->RTW_revision->item(row, 10)->text());
            QDesktopServices::openUrl(QUrl::fromLocalFile(path));
        } else {
            qDebug() << "Error: failed to write file from database";
        }

    } else if (column == 11) {
        cambiarSilabo(ui->RTW_revision->item(row, 2)->text().toInt(), ui->RTW_revision->item(row, 9)->text());
    }
}


void cframe::on_Bbtn_aceptados_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QStringList headers;
    if(usuarioActual->getInstitucion()=="CEUTEC"){
        headers << "VER SILABO" <<"Path silabo"<< "Facultad" << "Carrera" << "Numero de Cuenta" << "Código de Clase" << "Nombre de la Clase" << "Institucion"<< "Estado" << "Observación" << "ID" << "Número de Revisiones";
    }else{
        headers << "VER SILABO" <<"Path silabo"<<"Facultad" << "Carrera" << "Numero de Cuenta" << "Código de Clase" << "Nombre de la Clase" << "Institucion" <<"Estado" << "Observación" << "ID" << "Número de Revisiones"
                << "VER CUADRO" << "Path cuadro";
    }

    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    recorrerArbolParaTableAprobados(arbolSilabo->getRaiz(), ui->tableWidget);
}

void cframe::on_Bbtn_proceso_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QStringList headers;
    if(usuarioActual->getInstitucion()=="CEUTEC"){
        headers << "VER SILABO" <<"Path silabo"<< "Facultad" << "Carrera" << "Numero de Cuenta" << "Código de Clase" << "Nombre de la Clase" << "Institucion" << "Estado" << "Observacion" << "ID" << "Número de Revisiones";
    }else{
        headers <<"VER SILABO" <<"Path silabo"<<"Facultad" << "Carrera" << "Numero de Cuenta" << "Código de Clase" << "Nombre de la Clase" << "Institucion" <<"Estado" << "Observación" << "ID" << "Número de Revisiones"
                << "VER CUADRO" <<"Path cuadro";
    }

    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    recorrerArbolParaTableEnProceso(arbolSilabo->getRaiz(), ui->tableWidget);
}

void cframe::recorrerArbolParaTableAprobados(NodoArbolB *nodo, QTableWidget *tableWidget) {
    if (nodo == nullptr) {
        return;
    }

    recorrerArbolParaTableAprobados(nodo->getChild(0), tableWidget);
    EstadoNombres nombres;

    for (int i = 0; i < nodo->getN(); i++) {
        Silabo *silabo = nodo->getSilabo(i);

        // Solo insertar una nueva fila si el usuario actual y el estado del silabo cumplen las condiciones
        if (usuarioActual->getInstitucion() == silabo->getInstitucion() && nombres.nombres[silabo->getEstado()] == "Aprobado") {
            int row = tableWidget->rowCount();
            tableWidget->insertRow(row);
            string path = silabo->getNombreArchivo();
            tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString("ABRIR")));
            tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(path)));
            tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(silabo->getFacultad())));
            tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(silabo->getCarrera())));
            tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(silabo->getSubidoPor())));
            tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(silabo->getCodigoClase())));
            tableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(silabo->getNombreClase())));
            tableWidget->setItem(row, 7, new QTableWidgetItem(QString::fromStdString(silabo->getInstitucion())));
            tableWidget->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(nombres.nombres[silabo->getEstado()])));
            tableWidget->setItem(row, 9, new QTableWidgetItem(QString::fromStdString(silabo->getObservacion())));
            tableWidget->setItem(row, 10, new QTableWidgetItem(QString::number(silabo->getId())));
            tableWidget->setItem(row, 11, new QTableWidgetItem(QString::number(silabo->getRevisiones())));

            if (silabo->getInstitucion() == "UNITEC") {
                tableWidget->setItem(row, 12, new QTableWidgetItem(QString::fromStdString("VER CUADRO")));
                //tableWidget->setItem(row, 14, new QTableWidgetItem(QString::fromStdString(silabo->getCuadrofechas()->getNombreArchivo())));
            }
        }
    }

    recorrerArbolParaTableAprobados(nodo->getChild(nodo->getN()), tableWidget);
}


void cframe::recorrerArbolParaTableEnProceso(NodoArbolB *nodo, QTableWidget *tableWidget) {
    if (nodo == nullptr) {
        return;
    }

    recorrerArbolParaTableEnProceso(nodo->getChild(0), tableWidget);
    EstadoNombres nombres;

    for (int i = 0; i < nodo->getN(); i++) {
        Silabo *silabo = nodo->getSilabo(i);

        // Solo insertar una nueva fila si el usuario actual y el estado del silabo cumplen las condiciones
        if (usuarioActual->getInstitucion() == silabo->getInstitucion() && nombres.nombres[silabo->getEstado()] != "Aprobado") {
            int row = tableWidget->rowCount();
            tableWidget->insertRow(row);
            string path = silabo->getNombreArchivo();
            tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString("ABRIR")));
            tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(path)));
            tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(silabo->getFacultad())));
            tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(silabo->getCarrera())));
            tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(silabo->getSubidoPor())));
            tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(silabo->getCodigoClase())));
            tableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(silabo->getNombreClase())));
            tableWidget->setItem(row, 7, new QTableWidgetItem(QString::fromStdString(silabo->getInstitucion())));
            tableWidget->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(nombres.nombres[silabo->getEstado()])));
            tableWidget->setItem(row, 9, new QTableWidgetItem(QString::fromStdString(silabo->getObservacion())));
            tableWidget->setItem(row, 10, new QTableWidgetItem(QString::number(silabo->getId())));
            tableWidget->setItem(row, 11, new QTableWidgetItem(QString::number(silabo->getRevisiones())));

            if (silabo->getInstitucion() == "UNITEC") {
                tableWidget->setItem(row, 12, new QTableWidgetItem(QString::fromStdString("VER CUADRO")));
                //tableWidget->setItem(row, 14, new QTableWidgetItem(QString::fromStdString(silabo->getCuadrofechas()->getNombreArchivo())));

            }
        }
    }

    recorrerArbolParaTableEnProceso(nodo->getChild(nodo->getN()), tableWidget);
}




void cframe::on_Bbtn_cerrar_clicked()
{
    ui->tab->setEnabled(true);
    loginBoard = false;
    limpiarBoard();
    desactivarTabs();
    ui->tabWidget->tabBar()->hide();
}

void cframe::limpiarBoard()
{
    ui->tab_3->setEnabled(true);
    ui->tab_2->setEnabled(true);
    ui->tab_5->setEnabled(true);


}



void cframe::mostrarDocente(NodoArbolB *nodo, int fila, string numCuenta)
{
    if (nodo == nullptr) {
        return;
    }
    EstadoNombres nombres;
    mostrarDocente(nodo->getChild(0), fila, numCuenta);

    for (int i = 0; i < nodo->getN(); i++) {
        Silabo *silabo = nodo->getSilabo(i);

        if (silabo->getSubidoPor() == numCuenta ) {
            ui->DRTW_revision->setRowCount(fila + 1);
            ui->DRTW_revision->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString("VER")));
            ui->DRTW_revision->setItem(fila, 1, new QTableWidgetItem(QString::number(silabo->getId())));
            ui->DRTW_revision->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(silabo->getSubidoPor())));
            ui->DRTW_revision->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(nombres.nombres[silabo->getEstado()])));
            ui->DRTW_revision->setItem(fila, 4, new QTableWidgetItem(QString::fromStdString(silabo->getCarrera())));
            ui->DRTW_revision->setItem(fila, 5, new QTableWidgetItem(QString::fromStdString(silabo->getCodigoClase())));
            ui->DRTW_revision->setItem(fila, 6, new QTableWidgetItem(QString::fromStdString(silabo->getRuta())));
            ui->DRTW_revision->setItem(fila, 7, new QTableWidgetItem(QString::number(silabo->getRevisiones())));

            if(usuarioActual->institucion == "UNITEC"){
                ui->DRTW_revision->setItem(fila, 8, new QTableWidgetItem(QString::fromStdString("VER CUADRO")));
            }else{
                ui->DRTW_revision->setItem(fila, 8, new QTableWidgetItem(QString::fromStdString("NO APLICA")));
            }


            fila++;
        }
    }

    mostrarDocente(nodo->getChild(nodo->getN()), fila, numCuenta);
}

void cframe::on_Dbtn_salir_clicked()
{
    ui->tab->setEnabled(true);
    ui->DRTW_revision->clear();
    ui->tab->setEnabled(true);
    ui->tab_3->setEnabled(true);
    ui->tab_2->setEnabled(true);
    ui->tab_4->setEnabled(true);
    loginCheck = false;
    ui->Dbtn_salir->setVisible(false);
    desactivarTabs();
    ui->tabWidget->tabBar()->hide();
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

//std::string cframe::(Estado estado) const {
//    switch (estado) {
//    case Prerevision: return "Prerevision";
//    case ListoRevision: return "ListoRevision";
//    case Aprobado: return "Aprobado";
//    case AprobadoCondicion: return "AprobadoCondicion";
//    case SolicitudCambio: return "SolicitudCambio";
//    case DevueltoAcademia: return "DevueltoAcademia";
//    case Correcion: return "Correcion";
//    case CorrecionMayor: return "CorrecionMayor";
//    case CorrecionMenor: return "CorrecionMenor";
//    default: return "Desconocido";
//    }
//}


// ====================== REGISTRAR ===========================
void cframe::on_btn_registraruser_clicked()
{
    string nombre = ui->le_nombreR->text().toStdString();
    string numeroCuenta = ui->le_numcuentaR->text().toStdString();
    string clave = ui->le_claveR->text().toStdString();
    string institucion = ui->cb_institucionR->currentText().toStdString();
    string tipousuario = ui->cb_tipousuarioR->currentText().toStdString();
    string carrera = ui->cb_carreraRegistro->currentText().toStdString();

    // Verificar que no haya espacios vacíos
    if (nombre.empty() || numeroCuenta.empty() || clave.empty() || institucion.empty() || tipousuario.empty()) {
        QMessageBox::warning(this, "Error", "Por favor, complete todos los campos.");
        return;
    }

    // Verificar que el número de cuenta no se repita
    nodoD<Usuario>* temp = listaUsuarios.PrimPtr;
    while (temp != nullptr) {
        if (temp->getDato().getCuenta() == numeroCuenta) {
            QMessageBox::warning(this, "Error", "Un usuario con ese número de cuenta ya existe. Nombre: " + QString::fromStdString(temp->getDato().getName()));
            return;
        }
        temp = temp->SigPtr;
    }

    // Si no se encuentra un usuario con el mismo número de cuenta, registrar el nuevo usuario
    Usuario nuevoUser(nombre, numeroCuenta, clave, institucion, tipousuario, carrera);
    listaUsuarios.InsertarFin(nuevoUser);
    //listaUsuarios.guardarUsuarios(listaUsuarios);

    DB.saveUser(nuevoUser);
    limpiarRegistro();
    QMessageBox::information(this, "Registro Exitoso", "El usuario ha sido registrado exitosamente.");
    mostrarUsuarios();

}




void cframe::on_btn_registrarSalir_clicked()
{
    ui->tab->setEnabled(true);
    ui->tabWidget->setCurrentIndex(0);
    desactivarTabs();
    ui->tabWidget->tabBar()->hide();
}

void cframe::limpiarRegistro()
{
    ui->le_nombreR->clear();
    ui->le_numcuentaR->clear();
    ui->le_claveR->clear();
    ui->cb_institucionR->setCurrentIndex(0);
    ui->cb_tipousuarioR->setCurrentIndex(0);

}


void cframe::on_btn_archivoCF_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos Word Documents", QDir::homePath(), "Word Files (*.docx)");
    if (!filePath.isEmpty()) {
        ui->le_pathCF->setText(filePath);
    }
}

void cframe::on_cb_facultadRegistro_currentIndexChanged(int i)
{
    QStringList items;
    ui->cb_carreraRegistro->clear();
    if (i == 1) {
        items << "..." << "INGENIERÍA BIOMÉDICA" << "INGENIERÍA EN CIENCIA DE DATOS E INTELIGENCIA ARTIFICIAL" << "INGENIERÍA CIVIL" << "INGENIERÍA EN ENERGÍA" << "INGENIERÍA INDUSTRIAL Y DE SISTEMAS" << "INGENIERÍA EN MECATRÓNICA" << "INGENIERÍA EN SISTEMAS COMPUTACIONALES" << "INGENIERÍA EN TELECOMUNICACIONES Y ELECTRÓNICA"<<"INGENIERÍA EN INFORMÁTICA"<<"INGENIERÍA EN ELECTRÓNICA"<<"INGENIERÍA EN GESTIÓN LOGÍSTICA"<<"INGENIERÍA EN GESTIÓN DE AMBIENTE Y DESARROLLO";
        ui->cb_carreraRegistro->addItems(items);
    } else if (i == 2) {
        items << "..." << "LICENCIATURA EN ADMINISTRACIÓN DE LA HOSPITALIDAD Y EL TURISMO" << "LICENCIATURA EN ADMINISTRACIÓN INDUSTRIAL E INTELICENCIA DE NEGOCIOS" << "LICENCIATURA EN AMINISTRACIÓN INDUSTRIAL Y EMPRENDIMIENTO" << "LICENCIATURA EN ADMINISTRACIÓN INDUSTRIAL Y OPERACIONES" << "LICENCIATURA EN DERECHO" << "LICENCIATURA EN FINANZAS Y ECONOMÍA" << "LICENCIATURA EN MERCADOTECNIA Y NEGOCIOS INTERNACIONALES" << "LICENCIATURA EN RELACIONES INTERNACIONALES"<<"LICENCIATURA EN CONTADURÍA PÚBLICA Y FINANZAS"<<"LICENCIATURA EN MERCADOTECNIA"<<"LICENCIATURA EN ADMINISTRACIÓN DE EMPRESAS"<<"LICENCIATURA EN RECURSOS HUMANOS"<<"LICENCIATURA EN ECONOMÍA"<<"LICENCIATURA EN PERIODISMO";
        ui->cb_carreraRegistro->addItems(items);
    } else if (i == 3) {
        items << "..." << "LICENCIATURA EN ANIMACIÓN DIGITAL y DISEÑO INTERACTIVO" << "ARQUITECTURA" << "LICENCIATURA EN COMUNICACIÓN AUDIOVISUAL Y PUBLICITARIA" << "LICENCIATURA EN DISEÑO DE MODAS" << "LICENCIATURA EN DISEÑO GRÁFICO" << "LICENCIATURA EN GASTRONOMÍA";
        ui->cb_carreraRegistro->addItems(items);
    }else if (i == 4) {
        items << "..." << "LICENCIATURA EN PSICOLOGÍA" << "MEDICINA Y CIRUGÍA" << "CIRUGÍA DENTAL" << "LICENCIATURA EN NUTRICIÓN" << "LICENCIATURA EN TERAPIA FÍSICA Y OCUPACIONAL" << "LICENCIATURA EN ENFERMERÍA";
        ui->cb_carreraRegistro->addItems(items);
    }else if (i == 5) {
        items << "..." << "MAESTRÍA EN FINANZAS" << "MAESTRÍA EN GESTIÓN DEL MARKETING ESTRATÉGICO Y DIGITAL" << "MAESTRÍA EN DIRECCIÓN EMPRESARIAL" << "MAESTRÍA EN ADMINISTRACIÓN DE PROYECTOS" << "MAESTRÍA EN DERECHO EMPRESARIAL" << "MAESTRÍA EN DIRECCIÓN DE RECURSOS HUMANOS"<< "MAESTRÍA EN GESTIÓN DE OPERACIONES Y LOGÍSTICA" << "MAESTRÍA EN GESTIÓN DE TECNOLOGÍAS DE LA INFORMACIÓN"<< "MAESTRÍA EN SISTEMAS DE GESTIÓN DE LA CALIDAD INTEGRADOS" << "MAESTRÍA DE DIRECCIÓN DE LA COMUNICACIÓN CORPORATIVA" << "MAESTRÍA EN GESTIÓN DE ENERGÍAS RENOVABLES"<< "MAESTRÍA EN GESTIÓN DE SERVICIOS DE SALUD" << "MAESTRÍA EN GESTIÓN PÚBLICA" << "MAESTRIA EN DERECHOS HUMANOS"<< "MAESTRÍA EN PSICOLOGÍA CLÍNICA" << "MAESTRÍA EN DERECHO TRIBUTARIO" << "MAESTRÍA EN ANALÍTICA DE NEGOCIOS"<< "MAESTRÍA EN RESPONSABILIDAD SOCIAL Y SOSTENIBILIDAD" << "MAESTRÍA EN GESTIÓN DE LA INNOVACIÓN Y EL EMPRENDIMIENTO" << "MAESTRÍA EN DESARROLLO LOCAL Y COOPERACIÓN INTERNACIONAL" << "MAESTRÍA EN SALUD PÚBLICA" ;
        ui->cb_carreraRegistro->addItems(items);
    }
    else if (i == 6) {
        items << "..." << "TÉCNICO UNIVERSITARIO EN ENFERMERÍA AUXILIAR" << "TÉCNICO UNIVERSITARIO EN INSTALACIÓN DE REDES" << "TÉCNICO UNIVERSITARIO EN DESARROLLO DE APLICACIONES WEB" << "TÉCNICO UNIVERSITARIO EN DISEÑO DE INTERIORES" << "TÉCNICO UNIVERSITARIO BILINGÜE EN CALL CENTER" << "TÉCNICO UNIVERSITARIO EN INSTRUMENTACIÓN QUIRÚRGICA"<< "TÉCNICO UNIVERSITARIO EN URGENCIAS MÉDICAS" << "TÉCNICO UNIVERSITARIO BILINGÜE EN TURISMO"<< "TÉCNICO UNIVERSITARIO EN MARKETING DIGITAL" << "TÉCNICO UNIVERSITARIO EN DESARROLLO Y CUIDADO INFANTIL" << "TÉCNICO UNIVERSITARIO EN COMERCIALIZACIÓN Y PROMOCIÓN RETAIL"<< "TÉCNICO UNIVERSITARIO EN DISEÑO GRÁFICO" << "TÉCNICO UNIVERSITARIO EN ADMINISTRACIÓN";
        ui->cb_carreraRegistro->addItems(items);
    }
}

void cframe::mostrarUsuarios()
{
    // Limpiar el widget de tabla
    ui->tw_usuarios->clear();
    ui->tw_usuarios->setColumnCount(7);  // Ajusta según el número de columnas necesarias
    QStringList headers = {"Número de Cuenta", "Nombre", "Clave", "Organización", "Tipo", "Carrera", "Cambiar Contraseña"};

    ui->tw_usuarios->setHorizontalHeaderLabels(headers);
    ui->tw_usuarios->setRowCount(listaUsuarios.Cantidad);
    ui->tw_usuarios->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Recorrer la lista de usuarios y agregarlos a la tabla
    nodoD<Usuario> *current = listaUsuarios.PrimPtr;
    int row = 0;
    while (current != nullptr) {
        Usuario user = current->getDato();
        ui->tw_usuarios->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(user.getCuenta())));
        ui->tw_usuarios->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(user.getName())));
        ui->tw_usuarios->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(user.getContrasena())));
        ui->tw_usuarios->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(user.getInstitucion())));
        ui->tw_usuarios->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(user.getTipo())));
        ui->tw_usuarios->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(user.getCarrera())));
        ui->tw_usuarios->setItem(row, 6, new QTableWidgetItem(QString::fromStdString("Cambiar")));


        current = current->SigPtr;
        row++;
    }
}



void cframe::on_tw_usuarios_cellClicked(int row, int column)
{
    if (column == 6) { // la columna donde dice cambiar
        bool ok;
        QString nuevaContra = QInputDialog::getText(this, "Nueva Contraseña", "Ingrese la nueva contraseña:", QLineEdit::Normal, "", &ok);

        if (ok && !nuevaContra.isEmpty()) {
            // Obtener el número de cuenta del usuario seleccionado en la tabla
            QString cuentaSeleccionada = ui->tw_usuarios->item(row, 0)->text();
            std::string cuentaStr = cuentaSeleccionada.toStdString();

            // Buscar el usuario en la lista
            nodoD<Usuario> *current = listaUsuarios.PrimPtr;
            while (current != nullptr) {
                Usuario usuario = current->getDato();

                if (usuario.getCuenta() == cuentaStr) {
                    // Actualizar la contraseña del usuario
                    usuario.setContrasena(nuevaContra.toStdString());

                    // Actualizar en la base de datos
                    if (!DB.actualizarUsuario(usuario)) {
                        QMessageBox::information(this, "Error", "No se ha podido actualizar la base de datos");
                    } else {
                        // Actualizar el dato en el nodo de la lista
                        current->Dato= usuario;
                        QMessageBox::information(this, "Éxito", "La contraseña ha sido actualizada correctamente");
                    }
                    break;
                }

                current = current->SigPtr;
            }
        } else {
            QMessageBox::information(this, "Datos incompletos", "Por favor, no deje campos vacíos");
        }

        // Refrescar la tabla de usuarios para mostrar los cambios
        mostrarUsuarios();
    }
}



#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <Usuario.h>
#include <string>
#include <listaD.h>
#include <nodoD.h>
#include <Estado.h>
#include <ArbolB.h>
#include <QTableWidgetItem>
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();

private slots:
    void on_btn_entregarM_2_clicked();
    void on_btn_revision_2_clicked();
    void on_btn_dashboardM_2_clicked();

    void on_tabWidget_currentChanged(int index);
    void on_btn_silaboE_clicked();
    void on_btn_archivoE_clicked();
    void on_cb_facultadE_currentIndexChanged(int index);
    void on_btn_closeE_clicked();

    void on_Rcb_usuario_currentIndexChanged(int index);
    void on_Rbtn_sesion_clicked();
    void on_Rbtn_cerrar_clicked();
    void on_Rbtn_cambiar_clicked();
    void on_RTW_revision_cellClicked(int row, int column);

    void on_Bbtn_sesion_clicked();
    void on_Bbtn_cerrar_clicked();
    void on_Bbtn_proceso_clicked();
    void on_Bbtn_aceptados_clicked();

    void on_Dbtn_sesion_clicked();
    void on_Dbtn_salir_clicked();
    void on_DRTW_revision_cellClicked(int row, int column);

    void on_btn_sesion_clicked();

private:
    Ui::cframe *ui;

    bool loginDocente=false, loginRevision=false, revision2=false, loginBoard=false, loginCheck=false;
    void limpiarEntrega();
    void limpiarRevision();
    void limpiarBoard();

    void recorrerArbolParaTabla(NodoArbolB *nodo, int &fila, nodoD<Usuario> *actD);
    void recorrerArbolParaTable(NodoArbolB *nodo, QTableWidget *tableWidget, const std::string &estado);
    bool todo=false;

    void pruebitaBotonesTab();

    void cambiarSilabo(int id, QString pathActual);
    void modificarDatosSilabo(NodoArbolB *nodo, int id, QString pathNuevo);
    string obtenerNombre(string cuenta);
    bool cambiarPath=false, cambiarEstado=false;

    listaD<Usuario> listaUsuarios;
    nodoD<Usuario> *actD;
    nodoD<Usuario> *ultD;

    ArbolB *arbolSilabo = new ArbolB(3); // Grado mínimo t = 3

    int cantSilabos=0;
    int id=0;

    string claveDocente="teacher123", claveJefe="boss123", claveCoordinador="coordinator123", claveIEDD="what123", claveConsultor="advisor123", claveDecano="dean123", claveDirector="director123";

    void mostrarDocente(NodoArbolB *nodo, int fila, string numCuenta);

    Usuario *usuarioActual = nullptr;
};

#endif // CFRAME_H

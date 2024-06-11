#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <Usuario.h>
#include <string>
#include <listaD.h>
#include <nodoD.h>
#include <Estado.h>
#include <Arbol.h>
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

       //tab entrega
       void on_tabWidget_currentChanged(int index);
       void on_btn_silaboE_clicked();
       void on_btn_archivoE_clicked();
       void on_cb_facultadE_currentIndexChanged(int index);
       void on_btn_closeE_clicked();

       //tab revision
       void on_Rcb_usuario_currentIndexChanged(int index);
       void on_Rbtn_sesion_clicked();
       void on_Rbtn_cerrar_clicked();
       void on_Rbtn_cambiar_clicked();
       void on_RTW_revision_cellClicked(int row, int column);

       //tab board
       void on_Bbtn_sesion_clicked();
       void on_Bbtn_cerrar_clicked();
       void on_Bbtn_proceso_clicked();
       void on_Bbtn_aceptados_clicked();

       //tab reload
       void on_Dbtn_sesion_clicked();
       void on_Dbtn_salir_clicked();
       void on_DRTW_revision_cellClicked(int row, int column);


       void on_btn_sesion_clicked();

private:
    Ui::cframe *ui;


    bool loginDocente=false,loginRevision=false, revision2=false, loginBoard=false, loginCheck=false;
    void limpiarEntrega();
    void limpiarRevision();
    void limpiarBoard();

    void recorrerArbolParaTabla(Arbol *nodo, int &fila,nodoD<Usuario> *actD);
    void recorrerArbolParaTable(Arbol *nodo, QTableWidget *tableWidget, const std::string &estado);
    bool todo=false;

    void pruebitaBotonesTab();

    void cambiarSilabo(int id,QString pathActual);
    void modificarDatosSilabo(Arbol *nodo,int id,QString pathNuevo);
    string obtenerNombre(string);
    bool cambiarPath=false, cambiarEstado=false;

    listaD<Usuario> listaUsuarios;
    nodoD<Usuario> *actD;
    nodoD<Usuario> *ultD;

    Arbol *actS;
    Arbol *arbolSilabo  = new Arbol(nullptr);

    int cantSilabos=0;
    int id=0;

    string claveDocente="teacher123", claveJefe="boss123",claveCoordinador="coordinator123",claveIEDD="what123",claveConsultor="advisor123",claveDecano="dean123",claveDirector="director123";

    void mostrarDocente(Arbol *nodo,int fila,string numCuenta);
};
#endif // CFRAME_H

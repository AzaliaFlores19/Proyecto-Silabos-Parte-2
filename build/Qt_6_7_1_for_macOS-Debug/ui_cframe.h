/********************************************************************************
** Form generated from reading UI file 'cframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFRAME_H
#define UI_CFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cframe
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_b1M;
    QLabel *lbl_pngMenu;
    QFrame *frameE2_2;
    QGridLayout *gridLayout_23;
    QLineEdit *le_claveE;
    QLabel *lbl_cuentaE;
    QLabel *lbl_contraE_6;
    QLineEdit *le_cuentaE;
    QPushButton *btn_sesion;
    QLabel *lbl_b2M;
    QPushButton *btn_entregarM_2;
    QPushButton *btn_revision_2;
    QPushButton *btn_dashboardM_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *lbl_pngE;
    QLabel *lbl_b2M_2;
    QFrame *frameE;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbl_facultadE;
    QComboBox *cb_facultadE;
    QLabel *lbl_carreraE;
    QComboBox *cb_carreraE;
    QLabel *lbl_codigoE;
    QLineEdit *le_codigoE;
    QLabel *lbl_nombreClase;
    QLineEdit *le_nombreClase;
    QLabel *lbl_archivoS;
    QPushButton *btn_archivoE;
    QLineEdit *le_pathE;
    QLabel *lbl_archivoCF;
    QPushButton *btn_archivoCF;
    QLineEdit *le_pathCF;
    QPushButton *btn_silaboE;
    QPushButton *btn_closeE;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QLabel *lbl_b2M_3;
    QFrame *frameR;
    QGridLayout *gridLayout_10;
    QFrame *frame_2;
    QGridLayout *gridLayout_11;
    QLabel *Rlbl_seleccion;
    QLineEdit *Rle_comentario;
    QLabel *Rlbl_comentario;
    QPushButton *Rbtn_cambiar;
    QLabel *Rlbl_estadoA;
    QLineEdit *Rle_seleccion;
    QLineEdit *Rle_estadoA;
    QLabel *Rlbl_name_4;
    QComboBox *Rcb_cambiarE;
    QPushButton *Rbtn_cerrar;
    QFrame *Rframe1;
    QGridLayout *gridLayout_12;
    QTableWidget *RTW_revision;
    QLabel *lbl_pngR;
    QWidget *tab_4;
    QGridLayout *gridLayout_6;
    QLabel *lbl_pngD;
    QFrame *frameB1;
    QGridLayout *gridLayout_13;
    QFrame *frameB;
    QGridLayout *gridLayout_15;
    QRadioButton *Bbtn_aceptados;
    QRadioButton *Bbtn_proceso;
    QPushButton *Bbtn_cerrar;
    QTableWidget *tableWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_18;
    QFrame *Dframe2;
    QGridLayout *gridLayout_17;
    QLabel *Dlabel2;
    QTableWidget *DRTW_revision;
    QLabel *Dlabel;
    QFrame *Dframe1;
    QVBoxLayout *verticalLayout_5;
    QPushButton *Dbtn_sesion;
    QPushButton *Dbtn_salir;
    QLabel *lbl_b2M_4;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_11;
    QFrame *frame;
    QVBoxLayout *verticalLayout_10;
    QLabel *lbl_facultadE_2;
    QLabel *lbl_facultadE_7;
    QLineEdit *le_nombreR;
    QLabel *lbl_facultadE_3;
    QLineEdit *le_numcuentaR;
    QLabel *lbl_facultadE_4;
    QLineEdit *le_claveR;
    QLabel *lbl_facultadE_5;
    QComboBox *cb_institucionR;
    QLabel *lbl_facultadE_6;
    QComboBox *cb_tipousuarioR;
    QPushButton *btn_registraruser;
    QPushButton *btn_registrarSalir;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cframe)
    {
        if (cframe->objectName().isEmpty())
            cframe->setObjectName("cframe");
        cframe->resize(1038, 687);
        centralwidget = new QWidget(cframe);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 20, 1149, 720));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName("tabWidget");
        QPalette palette;
        QBrush brush(QColor(203, 232, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        tabWidget->setPalette(palette);
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_b1M = new QLabel(tab);
        lbl_b1M->setObjectName("lbl_b1M");
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        lbl_b1M->setPalette(palette1);
        lbl_b1M->setScaledContents(false);

        verticalLayout_2->addWidget(lbl_b1M);

        lbl_pngMenu = new QLabel(tab);
        lbl_pngMenu->setObjectName("lbl_pngMenu");
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        lbl_pngMenu->setPalette(palette2);
        lbl_pngMenu->setScaledContents(true);

        verticalLayout_2->addWidget(lbl_pngMenu);

        frameE2_2 = new QFrame(tab);
        frameE2_2->setObjectName("frameE2_2");
        frameE2_2->setFrameShape(QFrame::StyledPanel);
        frameE2_2->setFrameShadow(QFrame::Raised);
        gridLayout_23 = new QGridLayout(frameE2_2);
        gridLayout_23->setObjectName("gridLayout_23");
        le_claveE = new QLineEdit(frameE2_2);
        le_claveE->setObjectName("le_claveE");
        QFont font;
        font.setPointSize(11);
        le_claveE->setFont(font);

        gridLayout_23->addWidget(le_claveE, 1, 1, 1, 1);

        lbl_cuentaE = new QLabel(frameE2_2);
        lbl_cuentaE->setObjectName("lbl_cuentaE");
        QFont font1;
        font1.setPointSize(12);
        lbl_cuentaE->setFont(font1);

        gridLayout_23->addWidget(lbl_cuentaE, 0, 0, 1, 1);

        lbl_contraE_6 = new QLabel(frameE2_2);
        lbl_contraE_6->setObjectName("lbl_contraE_6");
        lbl_contraE_6->setFont(font1);

        gridLayout_23->addWidget(lbl_contraE_6, 1, 0, 1, 1);

        le_cuentaE = new QLineEdit(frameE2_2);
        le_cuentaE->setObjectName("le_cuentaE");
        le_cuentaE->setFont(font);

        gridLayout_23->addWidget(le_cuentaE, 0, 1, 1, 1);

        btn_sesion = new QPushButton(frameE2_2);
        btn_sesion->setObjectName("btn_sesion");
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_sesion->setPalette(palette3);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font2.setPointSize(11);
        font2.setBold(false);
        btn_sesion->setFont(font2);

        gridLayout_23->addWidget(btn_sesion, 2, 1, 1, 1);


        verticalLayout_2->addWidget(frameE2_2);

        lbl_b2M = new QLabel(tab);
        lbl_b2M->setObjectName("lbl_b2M");
        lbl_b2M->setScaledContents(false);

        verticalLayout_2->addWidget(lbl_b2M);

        btn_entregarM_2 = new QPushButton(tab);
        btn_entregarM_2->setObjectName("btn_entregarM_2");
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_entregarM_2->setPalette(palette4);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cambria")});
        font3.setPointSize(14);
        font3.setBold(false);
        btn_entregarM_2->setFont(font3);

        verticalLayout_2->addWidget(btn_entregarM_2);

        btn_revision_2 = new QPushButton(tab);
        btn_revision_2->setObjectName("btn_revision_2");
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_revision_2->setPalette(palette5);
        btn_revision_2->setFont(font3);

        verticalLayout_2->addWidget(btn_revision_2);

        btn_dashboardM_2 = new QPushButton(tab);
        btn_dashboardM_2->setObjectName("btn_dashboardM_2");
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_dashboardM_2->setPalette(palette6);
        btn_dashboardM_2->setFont(font3);

        verticalLayout_2->addWidget(btn_dashboardM_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        lbl_pngE = new QLabel(tab_2);
        lbl_pngE->setObjectName("lbl_pngE");
        lbl_pngE->setScaledContents(true);

        verticalLayout_4->addWidget(lbl_pngE);

        lbl_b2M_2 = new QLabel(tab_2);
        lbl_b2M_2->setObjectName("lbl_b2M_2");
        lbl_b2M_2->setScaledContents(false);

        verticalLayout_4->addWidget(lbl_b2M_2);

        frameE = new QFrame(tab_2);
        frameE->setObjectName("frameE");
        frameE->setEnabled(true);
        frameE->setFrameShape(QFrame::StyledPanel);
        frameE->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frameE);
        verticalLayout_3->setObjectName("verticalLayout_3");
        lbl_facultadE = new QLabel(frameE);
        lbl_facultadE->setObjectName("lbl_facultadE");
        lbl_facultadE->setFont(font1);

        verticalLayout_3->addWidget(lbl_facultadE);

        cb_facultadE = new QComboBox(frameE);
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->setObjectName("cb_facultadE");
        cb_facultadE->setFont(font);

        verticalLayout_3->addWidget(cb_facultadE);

        lbl_carreraE = new QLabel(frameE);
        lbl_carreraE->setObjectName("lbl_carreraE");
        lbl_carreraE->setFont(font1);

        verticalLayout_3->addWidget(lbl_carreraE);

        cb_carreraE = new QComboBox(frameE);
        cb_carreraE->addItem(QString());
        cb_carreraE->setObjectName("cb_carreraE");
        cb_carreraE->setFont(font);

        verticalLayout_3->addWidget(cb_carreraE);

        lbl_codigoE = new QLabel(frameE);
        lbl_codigoE->setObjectName("lbl_codigoE");
        lbl_codigoE->setFont(font1);

        verticalLayout_3->addWidget(lbl_codigoE);

        le_codigoE = new QLineEdit(frameE);
        le_codigoE->setObjectName("le_codigoE");
        le_codigoE->setFont(font);

        verticalLayout_3->addWidget(le_codigoE);

        lbl_nombreClase = new QLabel(frameE);
        lbl_nombreClase->setObjectName("lbl_nombreClase");
        lbl_nombreClase->setFont(font1);

        verticalLayout_3->addWidget(lbl_nombreClase);

        le_nombreClase = new QLineEdit(frameE);
        le_nombreClase->setObjectName("le_nombreClase");
        le_nombreClase->setFont(font);

        verticalLayout_3->addWidget(le_nombreClase);

        lbl_archivoS = new QLabel(frameE);
        lbl_archivoS->setObjectName("lbl_archivoS");
        lbl_archivoS->setFont(font1);

        verticalLayout_3->addWidget(lbl_archivoS);

        btn_archivoE = new QPushButton(frameE);
        btn_archivoE->setObjectName("btn_archivoE");

        verticalLayout_3->addWidget(btn_archivoE);

        le_pathE = new QLineEdit(frameE);
        le_pathE->setObjectName("le_pathE");
        le_pathE->setEnabled(false);

        verticalLayout_3->addWidget(le_pathE);

        lbl_archivoCF = new QLabel(frameE);
        lbl_archivoCF->setObjectName("lbl_archivoCF");
        lbl_archivoCF->setFont(font1);

        verticalLayout_3->addWidget(lbl_archivoCF);

        btn_archivoCF = new QPushButton(frameE);
        btn_archivoCF->setObjectName("btn_archivoCF");

        verticalLayout_3->addWidget(btn_archivoCF);

        le_pathCF = new QLineEdit(frameE);
        le_pathCF->setObjectName("le_pathCF");
        le_pathCF->setEnabled(false);

        verticalLayout_3->addWidget(le_pathCF);

        btn_silaboE = new QPushButton(frameE);
        btn_silaboE->setObjectName("btn_silaboE");
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_silaboE->setPalette(palette7);
        btn_silaboE->setFont(font2);

        verticalLayout_3->addWidget(btn_silaboE);

        btn_closeE = new QPushButton(frameE);
        btn_closeE->setObjectName("btn_closeE");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font4.setPointSize(7);
        btn_closeE->setFont(font4);

        verticalLayout_3->addWidget(btn_closeE);


        verticalLayout_4->addWidget(frameE);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName("gridLayout_5");
        lbl_b2M_3 = new QLabel(tab_3);
        lbl_b2M_3->setObjectName("lbl_b2M_3");
        lbl_b2M_3->setScaledContents(false);

        gridLayout_5->addWidget(lbl_b2M_3, 1, 0, 1, 1);

        frameR = new QFrame(tab_3);
        frameR->setObjectName("frameR");
        frameR->setFrameShape(QFrame::StyledPanel);
        frameR->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frameR);
        gridLayout_10->setObjectName("gridLayout_10");
        frame_2 = new QFrame(frameR);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_2);
        gridLayout_11->setObjectName("gridLayout_11");
        Rlbl_seleccion = new QLabel(frame_2);
        Rlbl_seleccion->setObjectName("Rlbl_seleccion");
        Rlbl_seleccion->setFont(font1);

        gridLayout_11->addWidget(Rlbl_seleccion, 0, 0, 1, 1);

        Rle_comentario = new QLineEdit(frame_2);
        Rle_comentario->setObjectName("Rle_comentario");
        Rle_comentario->setEnabled(true);

        gridLayout_11->addWidget(Rle_comentario, 3, 1, 1, 1);

        Rlbl_comentario = new QLabel(frame_2);
        Rlbl_comentario->setObjectName("Rlbl_comentario");
        Rlbl_comentario->setFont(font1);

        gridLayout_11->addWidget(Rlbl_comentario, 3, 0, 1, 1);

        Rbtn_cambiar = new QPushButton(frame_2);
        Rbtn_cambiar->setObjectName("Rbtn_cambiar");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font5.setPointSize(11);
        Rbtn_cambiar->setFont(font5);

        gridLayout_11->addWidget(Rbtn_cambiar, 4, 1, 1, 1);

        Rlbl_estadoA = new QLabel(frame_2);
        Rlbl_estadoA->setObjectName("Rlbl_estadoA");
        Rlbl_estadoA->setFont(font1);

        gridLayout_11->addWidget(Rlbl_estadoA, 1, 0, 1, 1);

        Rle_seleccion = new QLineEdit(frame_2);
        Rle_seleccion->setObjectName("Rle_seleccion");
        Rle_seleccion->setEnabled(false);

        gridLayout_11->addWidget(Rle_seleccion, 0, 1, 1, 1);

        Rle_estadoA = new QLineEdit(frame_2);
        Rle_estadoA->setObjectName("Rle_estadoA");
        Rle_estadoA->setEnabled(false);

        gridLayout_11->addWidget(Rle_estadoA, 1, 1, 1, 1);

        Rlbl_name_4 = new QLabel(frame_2);
        Rlbl_name_4->setObjectName("Rlbl_name_4");
        Rlbl_name_4->setFont(font1);

        gridLayout_11->addWidget(Rlbl_name_4, 2, 0, 1, 1);

        Rcb_cambiarE = new QComboBox(frame_2);
        Rcb_cambiarE->addItem(QString());
        Rcb_cambiarE->setObjectName("Rcb_cambiarE");
        Rcb_cambiarE->setFont(font);

        gridLayout_11->addWidget(Rcb_cambiarE, 2, 1, 1, 1);

        Rbtn_cerrar = new QPushButton(frame_2);
        Rbtn_cerrar->setObjectName("Rbtn_cerrar");

        gridLayout_11->addWidget(Rbtn_cerrar, 5, 1, 1, 1);


        gridLayout_10->addWidget(frame_2, 0, 1, 1, 1);

        Rframe1 = new QFrame(frameR);
        Rframe1->setObjectName("Rframe1");
        Rframe1->setFrameShape(QFrame::StyledPanel);
        Rframe1->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(Rframe1);
        gridLayout_12->setObjectName("gridLayout_12");
        RTW_revision = new QTableWidget(Rframe1);
        RTW_revision->setObjectName("RTW_revision");

        gridLayout_12->addWidget(RTW_revision, 0, 0, 1, 1);


        gridLayout_10->addWidget(Rframe1, 0, 0, 1, 1);


        gridLayout_5->addWidget(frameR, 2, 0, 1, 1);

        lbl_pngR = new QLabel(tab_3);
        lbl_pngR->setObjectName("lbl_pngR");
        lbl_pngR->setScaledContents(true);

        gridLayout_5->addWidget(lbl_pngR, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setObjectName("gridLayout_6");
        lbl_pngD = new QLabel(tab_4);
        lbl_pngD->setObjectName("lbl_pngD");
        lbl_pngD->setScaledContents(true);

        gridLayout_6->addWidget(lbl_pngD, 0, 0, 1, 1);

        frameB1 = new QFrame(tab_4);
        frameB1->setObjectName("frameB1");
        frameB1->setFrameShape(QFrame::StyledPanel);
        frameB1->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frameB1);
        gridLayout_13->setObjectName("gridLayout_13");

        gridLayout_6->addWidget(frameB1, 1, 0, 1, 1);

        frameB = new QFrame(tab_4);
        frameB->setObjectName("frameB");
        frameB->setFrameShape(QFrame::StyledPanel);
        frameB->setFrameShadow(QFrame::Raised);
        gridLayout_15 = new QGridLayout(frameB);
        gridLayout_15->setObjectName("gridLayout_15");
        Bbtn_aceptados = new QRadioButton(frameB);
        Bbtn_aceptados->setObjectName("Bbtn_aceptados");

        gridLayout_15->addWidget(Bbtn_aceptados, 1, 2, 1, 1);

        Bbtn_proceso = new QRadioButton(frameB);
        Bbtn_proceso->setObjectName("Bbtn_proceso");

        gridLayout_15->addWidget(Bbtn_proceso, 0, 2, 1, 1);

        Bbtn_cerrar = new QPushButton(frameB);
        Bbtn_cerrar->setObjectName("Bbtn_cerrar");

        gridLayout_15->addWidget(Bbtn_cerrar, 2, 2, 1, 1);

        tableWidget = new QTableWidget(frameB);
        tableWidget->setObjectName("tableWidget");

        gridLayout_15->addWidget(tableWidget, 2, 0, 1, 1);


        gridLayout_6->addWidget(frameB, 2, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        gridLayout_18 = new QGridLayout(tab_5);
        gridLayout_18->setObjectName("gridLayout_18");
        Dframe2 = new QFrame(tab_5);
        Dframe2->setObjectName("Dframe2");
        Dframe2->setFrameShape(QFrame::StyledPanel);
        Dframe2->setFrameShadow(QFrame::Raised);
        gridLayout_17 = new QGridLayout(Dframe2);
        gridLayout_17->setObjectName("gridLayout_17");
        Dlabel2 = new QLabel(Dframe2);
        Dlabel2->setObjectName("Dlabel2");
        QPalette palette8;
        QBrush brush3(QColor(6, 36, 88, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush3);
        QBrush brush4(QColor(6, 36, 88, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        QBrush brush5(QColor(120, 120, 120, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        Dlabel2->setPalette(palette8);

        gridLayout_17->addWidget(Dlabel2, 0, 0, 1, 1);

        DRTW_revision = new QTableWidget(Dframe2);
        DRTW_revision->setObjectName("DRTW_revision");

        gridLayout_17->addWidget(DRTW_revision, 0, 1, 1, 1);

        Dlabel = new QLabel(Dframe2);
        Dlabel->setObjectName("Dlabel");
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        Dlabel->setPalette(palette9);

        gridLayout_17->addWidget(Dlabel, 0, 2, 1, 1);


        gridLayout_18->addWidget(Dframe2, 2, 0, 1, 1);

        Dframe1 = new QFrame(tab_5);
        Dframe1->setObjectName("Dframe1");
        Dframe1->setFrameShape(QFrame::StyledPanel);
        Dframe1->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(Dframe1);
        verticalLayout_5->setObjectName("verticalLayout_5");
        Dbtn_sesion = new QPushButton(Dframe1);
        Dbtn_sesion->setObjectName("Dbtn_sesion");
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush);
        Dbtn_sesion->setPalette(palette10);
        Dbtn_sesion->setFont(font2);

        verticalLayout_5->addWidget(Dbtn_sesion);

        Dbtn_salir = new QPushButton(Dframe1);
        Dbtn_salir->setObjectName("Dbtn_salir");

        verticalLayout_5->addWidget(Dbtn_salir);


        gridLayout_18->addWidget(Dframe1, 1, 0, 1, 1);

        lbl_b2M_4 = new QLabel(tab_5);
        lbl_b2M_4->setObjectName("lbl_b2M_4");
        lbl_b2M_4->setScaledContents(false);

        gridLayout_18->addWidget(lbl_b2M_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        verticalLayout_11 = new QVBoxLayout(tab_6);
        verticalLayout_11->setObjectName("verticalLayout_11");
        frame = new QFrame(tab_6);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame);
        verticalLayout_10->setObjectName("verticalLayout_10");
        lbl_facultadE_2 = new QLabel(frame);
        lbl_facultadE_2->setObjectName("lbl_facultadE_2");
        lbl_facultadE_2->setFont(font1);

        verticalLayout_10->addWidget(lbl_facultadE_2);

        lbl_facultadE_7 = new QLabel(frame);
        lbl_facultadE_7->setObjectName("lbl_facultadE_7");
        lbl_facultadE_7->setFont(font1);

        verticalLayout_10->addWidget(lbl_facultadE_7);

        le_nombreR = new QLineEdit(frame);
        le_nombreR->setObjectName("le_nombreR");

        verticalLayout_10->addWidget(le_nombreR);

        lbl_facultadE_3 = new QLabel(frame);
        lbl_facultadE_3->setObjectName("lbl_facultadE_3");
        lbl_facultadE_3->setFont(font1);

        verticalLayout_10->addWidget(lbl_facultadE_3);

        le_numcuentaR = new QLineEdit(frame);
        le_numcuentaR->setObjectName("le_numcuentaR");

        verticalLayout_10->addWidget(le_numcuentaR);

        lbl_facultadE_4 = new QLabel(frame);
        lbl_facultadE_4->setObjectName("lbl_facultadE_4");
        lbl_facultadE_4->setFont(font1);

        verticalLayout_10->addWidget(lbl_facultadE_4);

        le_claveR = new QLineEdit(frame);
        le_claveR->setObjectName("le_claveR");

        verticalLayout_10->addWidget(le_claveR);

        lbl_facultadE_5 = new QLabel(frame);
        lbl_facultadE_5->setObjectName("lbl_facultadE_5");
        lbl_facultadE_5->setFont(font1);

        verticalLayout_10->addWidget(lbl_facultadE_5);

        cb_institucionR = new QComboBox(frame);
        cb_institucionR->addItem(QString());
        cb_institucionR->addItem(QString());
        cb_institucionR->addItem(QString());
        cb_institucionR->setObjectName("cb_institucionR");
        cb_institucionR->setMaxVisibleItems(3);

        verticalLayout_10->addWidget(cb_institucionR);

        lbl_facultadE_6 = new QLabel(frame);
        lbl_facultadE_6->setObjectName("lbl_facultadE_6");
        lbl_facultadE_6->setFont(font1);

        verticalLayout_10->addWidget(lbl_facultadE_6);

        cb_tipousuarioR = new QComboBox(frame);
        cb_tipousuarioR->addItem(QString());
        cb_tipousuarioR->addItem(QString());
        cb_tipousuarioR->addItem(QString());
        cb_tipousuarioR->addItem(QString());
        cb_tipousuarioR->addItem(QString());
        cb_tipousuarioR->addItem(QString());
        cb_tipousuarioR->setObjectName("cb_tipousuarioR");

        verticalLayout_10->addWidget(cb_tipousuarioR);

        btn_registraruser = new QPushButton(frame);
        btn_registraruser->setObjectName("btn_registraruser");
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_registraruser->setPalette(palette11);
        btn_registraruser->setFont(font2);

        verticalLayout_10->addWidget(btn_registraruser);

        btn_registrarSalir = new QPushButton(frame);
        btn_registrarSalir->setObjectName("btn_registrarSalir");
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_registrarSalir->setPalette(palette12);
        btn_registrarSalir->setFont(font2);

        verticalLayout_10->addWidget(btn_registrarSalir);


        verticalLayout_11->addWidget(frame);

        tabWidget->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget);

        cframe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(cframe);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1038, 26));
        cframe->setMenuBar(menubar);
        statusbar = new QStatusBar(cframe);
        statusbar->setObjectName("statusbar");
        cframe->setStatusBar(statusbar);

        retranslateUi(cframe);

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(cframe);
    } // setupUi

    void retranslateUi(QMainWindow *cframe)
    {
        cframe->setWindowTitle(QCoreApplication::translate("cframe", "cframe", nullptr));
        lbl_b1M->setText(QString());
        lbl_pngMenu->setText(QString());
        lbl_cuentaE->setText(QCoreApplication::translate("cframe", "Numero de cuenta:", nullptr));
        lbl_contraE_6->setText(QCoreApplication::translate("cframe", "Clave:", nullptr));
        btn_sesion->setText(QCoreApplication::translate("cframe", "Iniciar Sesion", nullptr));
        lbl_b2M->setText(QString());
        btn_entregarM_2->setText(QCoreApplication::translate("cframe", "ENTREGA", nullptr));
        btn_revision_2->setText(QCoreApplication::translate("cframe", "REVISION", nullptr));
        btn_dashboardM_2->setText(QCoreApplication::translate("cframe", "VER DASHBOARD", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("cframe", "MENU", nullptr));
        lbl_pngE->setText(QString());
        lbl_b2M_2->setText(QString());
        lbl_facultadE->setText(QCoreApplication::translate("cframe", "Facultad:", nullptr));
        cb_facultadE->setItemText(0, QCoreApplication::translate("cframe", "...", nullptr));
        cb_facultadE->setItemText(1, QCoreApplication::translate("cframe", "FACULTAD DE INGENIER\303\215A", nullptr));
        cb_facultadE->setItemText(2, QCoreApplication::translate("cframe", "FACULTAD DE CIENCIAS ADMINISTRATIVAS Y SOCIALES", nullptr));
        cb_facultadE->setItemText(3, QCoreApplication::translate("cframe", "FACULTAD DE ARTE Y DISE\303\221O", nullptr));
        cb_facultadE->setItemText(4, QCoreApplication::translate("cframe", "FACULTAD DE CIENCIAS DE LA SALUD", nullptr));
        cb_facultadE->setItemText(5, QCoreApplication::translate("cframe", "FACULTAD DE POSTGRADO", nullptr));
        cb_facultadE->setItemText(6, QCoreApplication::translate("cframe", "FACULTAD DE T\303\211CNICOS", nullptr));

        lbl_carreraE->setText(QCoreApplication::translate("cframe", "Programa Acad\303\251mico:", nullptr));
        cb_carreraE->setItemText(0, QCoreApplication::translate("cframe", "...", nullptr));

        lbl_codigoE->setText(QCoreApplication::translate("cframe", "C\303\263digo de clase:", nullptr));
        lbl_nombreClase->setText(QCoreApplication::translate("cframe", "Nombre de la  clase:", nullptr));
        lbl_archivoS->setText(QCoreApplication::translate("cframe", "Archivo de S\303\255labo:", nullptr));
        btn_archivoE->setText(QCoreApplication::translate("cframe", "BUSCAR", nullptr));
        le_pathE->setText(QString());
        lbl_archivoCF->setText(QCoreApplication::translate("cframe", "Archivo de cuadro de fechas::", nullptr));
        btn_archivoCF->setText(QCoreApplication::translate("cframe", "BUSCAR", nullptr));
        le_pathCF->setText(QString());
        btn_silaboE->setText(QCoreApplication::translate("cframe", "Ingresar", nullptr));
        btn_closeE->setText(QCoreApplication::translate("cframe", "Cerrar\n"
"Sesion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("cframe", "ENTREGA", nullptr));
        lbl_b2M_3->setText(QString());
        Rlbl_seleccion->setText(QCoreApplication::translate("cframe", "Seleccion:", nullptr));
        Rlbl_comentario->setText(QCoreApplication::translate("cframe", "Comentario:", nullptr));
        Rbtn_cambiar->setText(QCoreApplication::translate("cframe", "Cambiar", nullptr));
        Rlbl_estadoA->setText(QCoreApplication::translate("cframe", "Estado Actual:", nullptr));
        Rlbl_name_4->setText(QCoreApplication::translate("cframe", "Cambiar Estado:", nullptr));
        Rcb_cambiarE->setItemText(0, QCoreApplication::translate("cframe", "...", nullptr));

        Rbtn_cerrar->setText(QCoreApplication::translate("cframe", "Cerrar Sesion", nullptr));
        lbl_pngR->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("cframe", "REVISION", nullptr));
        lbl_pngD->setText(QString());
        Bbtn_aceptados->setText(QCoreApplication::translate("cframe", "Aceptados", nullptr));
        Bbtn_proceso->setText(QCoreApplication::translate("cframe", "En proceso", nullptr));
        Bbtn_cerrar->setText(QCoreApplication::translate("cframe", "Cerrar Sesion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("cframe", "BOARD", nullptr));
        Dlabel2->setText(QCoreApplication::translate("cframe", "..................................................................................", nullptr));
        Dlabel->setText(QCoreApplication::translate("cframe", "...................................................................................", nullptr));
        Dbtn_sesion->setText(QCoreApplication::translate("cframe", "REVISAR", nullptr));
        Dbtn_salir->setText(QCoreApplication::translate("cframe", "SALIR", nullptr));
        lbl_b2M_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("cframe", "DOCENTE", nullptr));
        lbl_facultadE_2->setText(QCoreApplication::translate("cframe", "Creaci\303\263n de un nuevo usuario", nullptr));
        lbl_facultadE_7->setText(QCoreApplication::translate("cframe", "Nombre:", nullptr));
        lbl_facultadE_3->setText(QCoreApplication::translate("cframe", "N\303\272mero de cuenta:", nullptr));
        lbl_facultadE_4->setText(QCoreApplication::translate("cframe", "Clave:", nullptr));
        lbl_facultadE_5->setText(QCoreApplication::translate("cframe", "Instituci\303\263n:", nullptr));
        cb_institucionR->setItemText(0, QCoreApplication::translate("cframe", "...", nullptr));
        cb_institucionR->setItemText(1, QCoreApplication::translate("cframe", "UNITEC", nullptr));
        cb_institucionR->setItemText(2, QCoreApplication::translate("cframe", "CEUTEC", nullptr));

        lbl_facultadE_6->setText(QCoreApplication::translate("cframe", "Tipo de usuario:", nullptr));
        cb_tipousuarioR->setItemText(0, QCoreApplication::translate("cframe", "...", nullptr));
        cb_tipousuarioR->setItemText(1, QCoreApplication::translate("cframe", "Docente", nullptr));
        cb_tipousuarioR->setItemText(2, QCoreApplication::translate("cframe", "Coordinador", nullptr));
        cb_tipousuarioR->setItemText(3, QCoreApplication::translate("cframe", "IEDD", nullptr));
        cb_tipousuarioR->setItemText(4, QCoreApplication::translate("cframe", "Consultor", nullptr));
        cb_tipousuarioR->setItemText(5, QCoreApplication::translate("cframe", "Decano", nullptr));

        btn_registraruser->setText(QCoreApplication::translate("cframe", "Registrar", nullptr));
        btn_registrarSalir->setText(QCoreApplication::translate("cframe", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("cframe", "REGISTRAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cframe: public Ui_cframe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFRAME_H

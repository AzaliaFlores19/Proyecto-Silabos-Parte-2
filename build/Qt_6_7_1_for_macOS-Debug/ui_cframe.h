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
    QLabel *lbl_pngM;
    QFrame *frameE2_2;
    QGridLayout *gridLayout_23;
    QLabel *lbl_cuentaE;
    QLineEdit *le_claveE;
    QLabel *lbl_contraE_6;
    QLineEdit *le_cuentaE;
    QPushButton *btn_sesion;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QFrame *frameE;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbl_pngE;
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
    QFrame *frameB;
    QGridLayout *gridLayout_15;
    QRadioButton *Bbtn_aceptados;
    QRadioButton *Bbtn_proceso;
    QPushButton *Bbtn_cerrar;
    QTableWidget *tableWidget;
    QLabel *lbl_pngB;
    QWidget *tab_5;
    QGridLayout *gridLayout_18;
    QFrame *Dframe1;
    QVBoxLayout *verticalLayout_5;
    QPushButton *Dbtn_sesion;
    QPushButton *Dbtn_salir;
    QFrame *Dframe2;
    QGridLayout *gridLayout_17;
    QLabel *Dlabel2;
    QTableWidget *DRTW_revision;
    QLabel *Dlabel;
    QLabel *lbl_pngD;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_11;
    QLabel *lbl_pngRegistrar;
    QFrame *frame;
    QVBoxLayout *verticalLayout_10;
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
    QLabel *lbl_facultadE_8;
    QComboBox *cb_facultadRegistro;
    QLabel *lbl_carreraE_2;
    QComboBox *cb_carreraRegistro;
    QTableWidget *tw_usuarios;
    QPushButton *btn_registraruser;
    QPushButton *btn_registrarSalir;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cframe)
    {
        if (cframe->objectName().isEmpty())
            cframe->setObjectName("cframe");
        cframe->resize(1228, 940);
        centralwidget = new QWidget(cframe);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 20, 2054, 942));
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
        lbl_pngM = new QLabel(tab);
        lbl_pngM->setObjectName("lbl_pngM");
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        lbl_pngM->setPalette(palette1);
        lbl_pngM->setScaledContents(true);

        verticalLayout_2->addWidget(lbl_pngM);

        frameE2_2 = new QFrame(tab);
        frameE2_2->setObjectName("frameE2_2");
        frameE2_2->setFrameShape(QFrame::StyledPanel);
        frameE2_2->setFrameShadow(QFrame::Raised);
        gridLayout_23 = new QGridLayout(frameE2_2);
        gridLayout_23->setObjectName("gridLayout_23");
        lbl_cuentaE = new QLabel(frameE2_2);
        lbl_cuentaE->setObjectName("lbl_cuentaE");
        QFont font;
        font.setPointSize(16);
        lbl_cuentaE->setFont(font);

        gridLayout_23->addWidget(lbl_cuentaE, 0, 0, 1, 1);

        le_claveE = new QLineEdit(frameE2_2);
        le_claveE->setObjectName("le_claveE");
        le_claveE->setFont(font);

        gridLayout_23->addWidget(le_claveE, 1, 1, 1, 1);

        lbl_contraE_6 = new QLabel(frameE2_2);
        lbl_contraE_6->setObjectName("lbl_contraE_6");
        lbl_contraE_6->setFont(font);

        gridLayout_23->addWidget(lbl_contraE_6, 1, 0, 1, 1);

        le_cuentaE = new QLineEdit(frameE2_2);
        le_cuentaE->setObjectName("le_cuentaE");
        le_cuentaE->setFont(font);

        gridLayout_23->addWidget(le_cuentaE, 0, 1, 1, 1);

        btn_sesion = new QPushButton(frameE2_2);
        btn_sesion->setObjectName("btn_sesion");
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_sesion->setPalette(palette2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font1.setPointSize(16);
        font1.setBold(false);
        btn_sesion->setFont(font1);

        gridLayout_23->addWidget(btn_sesion, 2, 1, 1, 1);


        verticalLayout_2->addWidget(frameE2_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        frameE = new QFrame(tab_2);
        frameE->setObjectName("frameE");
        frameE->setEnabled(true);
        frameE->setFrameShape(QFrame::StyledPanel);
        frameE->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frameE);
        verticalLayout_3->setObjectName("verticalLayout_3");
        lbl_pngE = new QLabel(frameE);
        lbl_pngE->setObjectName("lbl_pngE");
        lbl_pngE->setScaledContents(true);

        verticalLayout_3->addWidget(lbl_pngE);

        lbl_facultadE = new QLabel(frameE);
        lbl_facultadE->setObjectName("lbl_facultadE");
        QFont font2;
        font2.setPointSize(12);
        lbl_facultadE->setFont(font2);

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
        QFont font3;
        font3.setPointSize(11);
        cb_facultadE->setFont(font3);

        verticalLayout_3->addWidget(cb_facultadE);

        lbl_carreraE = new QLabel(frameE);
        lbl_carreraE->setObjectName("lbl_carreraE");
        lbl_carreraE->setFont(font2);

        verticalLayout_3->addWidget(lbl_carreraE);

        cb_carreraE = new QComboBox(frameE);
        cb_carreraE->addItem(QString());
        cb_carreraE->setObjectName("cb_carreraE");
        cb_carreraE->setFont(font3);

        verticalLayout_3->addWidget(cb_carreraE);

        lbl_codigoE = new QLabel(frameE);
        lbl_codigoE->setObjectName("lbl_codigoE");
        lbl_codigoE->setFont(font2);

        verticalLayout_3->addWidget(lbl_codigoE);

        le_codigoE = new QLineEdit(frameE);
        le_codigoE->setObjectName("le_codigoE");
        le_codigoE->setFont(font3);

        verticalLayout_3->addWidget(le_codigoE);

        lbl_nombreClase = new QLabel(frameE);
        lbl_nombreClase->setObjectName("lbl_nombreClase");
        lbl_nombreClase->setFont(font2);

        verticalLayout_3->addWidget(lbl_nombreClase);

        le_nombreClase = new QLineEdit(frameE);
        le_nombreClase->setObjectName("le_nombreClase");
        le_nombreClase->setFont(font3);

        verticalLayout_3->addWidget(le_nombreClase);

        lbl_archivoS = new QLabel(frameE);
        lbl_archivoS->setObjectName("lbl_archivoS");
        lbl_archivoS->setFont(font2);

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
        lbl_archivoCF->setFont(font2);

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
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_silaboE->setPalette(palette3);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font4.setPointSize(11);
        font4.setBold(false);
        btn_silaboE->setFont(font4);

        verticalLayout_3->addWidget(btn_silaboE);

        btn_closeE = new QPushButton(frameE);
        btn_closeE->setObjectName("btn_closeE");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font5.setPointSize(7);
        btn_closeE->setFont(font5);

        verticalLayout_3->addWidget(btn_closeE);


        verticalLayout_4->addWidget(frameE);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName("gridLayout_5");
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
        Rlbl_seleccion->setFont(font2);

        gridLayout_11->addWidget(Rlbl_seleccion, 0, 0, 1, 1);

        Rle_comentario = new QLineEdit(frame_2);
        Rle_comentario->setObjectName("Rle_comentario");
        Rle_comentario->setEnabled(true);

        gridLayout_11->addWidget(Rle_comentario, 3, 1, 1, 1);

        Rlbl_comentario = new QLabel(frame_2);
        Rlbl_comentario->setObjectName("Rlbl_comentario");
        Rlbl_comentario->setFont(font2);

        gridLayout_11->addWidget(Rlbl_comentario, 3, 0, 1, 1);

        Rbtn_cambiar = new QPushButton(frame_2);
        Rbtn_cambiar->setObjectName("Rbtn_cambiar");
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font6.setPointSize(11);
        Rbtn_cambiar->setFont(font6);

        gridLayout_11->addWidget(Rbtn_cambiar, 4, 1, 1, 1);

        Rlbl_estadoA = new QLabel(frame_2);
        Rlbl_estadoA->setObjectName("Rlbl_estadoA");
        Rlbl_estadoA->setFont(font2);

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
        Rlbl_name_4->setFont(font2);

        gridLayout_11->addWidget(Rlbl_name_4, 2, 0, 1, 1);

        Rcb_cambiarE = new QComboBox(frame_2);
        Rcb_cambiarE->addItem(QString());
        Rcb_cambiarE->setObjectName("Rcb_cambiarE");
        Rcb_cambiarE->setFont(font3);

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


        gridLayout_5->addWidget(frameR, 1, 0, 1, 1);

        lbl_pngR = new QLabel(tab_3);
        lbl_pngR->setObjectName("lbl_pngR");
        lbl_pngR->setScaledContents(true);

        gridLayout_5->addWidget(lbl_pngR, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setObjectName("gridLayout_6");
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


        gridLayout_6->addWidget(frameB, 1, 0, 1, 1);

        lbl_pngB = new QLabel(tab_4);
        lbl_pngB->setObjectName("lbl_pngB");
        lbl_pngB->setScaledContents(true);

        gridLayout_6->addWidget(lbl_pngB, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        gridLayout_18 = new QGridLayout(tab_5);
        gridLayout_18->setObjectName("gridLayout_18");
        Dframe1 = new QFrame(tab_5);
        Dframe1->setObjectName("Dframe1");
        Dframe1->setFrameShape(QFrame::StyledPanel);
        Dframe1->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(Dframe1);
        verticalLayout_5->setObjectName("verticalLayout_5");
        Dbtn_sesion = new QPushButton(Dframe1);
        Dbtn_sesion->setObjectName("Dbtn_sesion");
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        Dbtn_sesion->setPalette(palette4);
        Dbtn_sesion->setFont(font4);

        verticalLayout_5->addWidget(Dbtn_sesion);

        Dbtn_salir = new QPushButton(Dframe1);
        Dbtn_salir->setObjectName("Dbtn_salir");

        verticalLayout_5->addWidget(Dbtn_salir);


        gridLayout_18->addWidget(Dframe1, 2, 0, 1, 1);

        Dframe2 = new QFrame(tab_5);
        Dframe2->setObjectName("Dframe2");
        Dframe2->setFrameShape(QFrame::StyledPanel);
        Dframe2->setFrameShadow(QFrame::Raised);
        gridLayout_17 = new QGridLayout(Dframe2);
        gridLayout_17->setObjectName("gridLayout_17");
        Dlabel2 = new QLabel(Dframe2);
        Dlabel2->setObjectName("Dlabel2");
        QPalette palette5;
        QBrush brush3(QColor(6, 36, 88, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush3);
        QBrush brush4(QColor(6, 36, 88, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        QBrush brush5(QColor(120, 120, 120, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        Dlabel2->setPalette(palette5);

        gridLayout_17->addWidget(Dlabel2, 0, 0, 1, 1);

        DRTW_revision = new QTableWidget(Dframe2);
        DRTW_revision->setObjectName("DRTW_revision");

        gridLayout_17->addWidget(DRTW_revision, 0, 1, 1, 1);

        Dlabel = new QLabel(Dframe2);
        Dlabel->setObjectName("Dlabel");
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        Dlabel->setPalette(palette6);

        gridLayout_17->addWidget(Dlabel, 0, 2, 1, 1);


        gridLayout_18->addWidget(Dframe2, 3, 0, 1, 1);

        lbl_pngD = new QLabel(tab_5);
        lbl_pngD->setObjectName("lbl_pngD");
        lbl_pngD->setScaledContents(true);

        gridLayout_18->addWidget(lbl_pngD, 1, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        verticalLayout_11 = new QVBoxLayout(tab_6);
        verticalLayout_11->setObjectName("verticalLayout_11");
        lbl_pngRegistrar = new QLabel(tab_6);
        lbl_pngRegistrar->setObjectName("lbl_pngRegistrar");
        lbl_pngRegistrar->setMinimumSize(QSize(1000, 70));
        lbl_pngRegistrar->setMaximumSize(QSize(16777215, 200));
        lbl_pngRegistrar->setScaledContents(true);

        verticalLayout_11->addWidget(lbl_pngRegistrar);

        frame = new QFrame(tab_6);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame);
        verticalLayout_10->setObjectName("verticalLayout_10");
        lbl_facultadE_7 = new QLabel(frame);
        lbl_facultadE_7->setObjectName("lbl_facultadE_7");
        lbl_facultadE_7->setFont(font2);

        verticalLayout_10->addWidget(lbl_facultadE_7);

        le_nombreR = new QLineEdit(frame);
        le_nombreR->setObjectName("le_nombreR");

        verticalLayout_10->addWidget(le_nombreR);

        lbl_facultadE_3 = new QLabel(frame);
        lbl_facultadE_3->setObjectName("lbl_facultadE_3");
        lbl_facultadE_3->setFont(font2);

        verticalLayout_10->addWidget(lbl_facultadE_3);

        le_numcuentaR = new QLineEdit(frame);
        le_numcuentaR->setObjectName("le_numcuentaR");

        verticalLayout_10->addWidget(le_numcuentaR);

        lbl_facultadE_4 = new QLabel(frame);
        lbl_facultadE_4->setObjectName("lbl_facultadE_4");
        lbl_facultadE_4->setFont(font2);

        verticalLayout_10->addWidget(lbl_facultadE_4);

        le_claveR = new QLineEdit(frame);
        le_claveR->setObjectName("le_claveR");

        verticalLayout_10->addWidget(le_claveR);

        lbl_facultadE_5 = new QLabel(frame);
        lbl_facultadE_5->setObjectName("lbl_facultadE_5");
        lbl_facultadE_5->setFont(font2);

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
        lbl_facultadE_6->setFont(font2);

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

        lbl_facultadE_8 = new QLabel(frame);
        lbl_facultadE_8->setObjectName("lbl_facultadE_8");
        lbl_facultadE_8->setFont(font2);

        verticalLayout_10->addWidget(lbl_facultadE_8);

        cb_facultadRegistro = new QComboBox(frame);
        cb_facultadRegistro->addItem(QString());
        cb_facultadRegistro->addItem(QString());
        cb_facultadRegistro->addItem(QString());
        cb_facultadRegistro->addItem(QString());
        cb_facultadRegistro->addItem(QString());
        cb_facultadRegistro->addItem(QString());
        cb_facultadRegistro->addItem(QString());
        cb_facultadRegistro->setObjectName("cb_facultadRegistro");
        cb_facultadRegistro->setFont(font3);

        verticalLayout_10->addWidget(cb_facultadRegistro);

        lbl_carreraE_2 = new QLabel(frame);
        lbl_carreraE_2->setObjectName("lbl_carreraE_2");
        lbl_carreraE_2->setFont(font2);

        verticalLayout_10->addWidget(lbl_carreraE_2);

        cb_carreraRegistro = new QComboBox(frame);
        cb_carreraRegistro->addItem(QString());
        cb_carreraRegistro->setObjectName("cb_carreraRegistro");
        cb_carreraRegistro->setFont(font3);

        verticalLayout_10->addWidget(cb_carreraRegistro);

        tw_usuarios = new QTableWidget(frame);
        tw_usuarios->setObjectName("tw_usuarios");

        verticalLayout_10->addWidget(tw_usuarios);

        btn_registraruser = new QPushButton(frame);
        btn_registraruser->setObjectName("btn_registraruser");
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_registraruser->setPalette(palette7);
        btn_registraruser->setFont(font4);

        verticalLayout_10->addWidget(btn_registraruser);

        btn_registrarSalir = new QPushButton(frame);
        btn_registrarSalir->setObjectName("btn_registrarSalir");
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_registrarSalir->setPalette(palette8);
        btn_registrarSalir->setFont(font4);

        verticalLayout_10->addWidget(btn_registrarSalir);


        verticalLayout_11->addWidget(frame);

        tabWidget->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget);

        cframe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(cframe);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1228, 24));
        cframe->setMenuBar(menubar);
        statusbar = new QStatusBar(cframe);
        statusbar->setObjectName("statusbar");
        cframe->setStatusBar(statusbar);

        retranslateUi(cframe);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(cframe);
    } // setupUi

    void retranslateUi(QMainWindow *cframe)
    {
        cframe->setWindowTitle(QCoreApplication::translate("cframe", "cframe", nullptr));
        lbl_pngM->setText(QString());
        lbl_cuentaE->setText(QCoreApplication::translate("cframe", "Numero de cuenta:", nullptr));
        lbl_contraE_6->setText(QCoreApplication::translate("cframe", "Clave:", nullptr));
        btn_sesion->setText(QCoreApplication::translate("cframe", "Iniciar Sesion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("cframe", "MENU", nullptr));
        lbl_pngE->setText(QString());
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
        lbl_archivoCF->setText(QCoreApplication::translate("cframe", "Archivo de cuadro de fechas:", nullptr));
        btn_archivoCF->setText(QCoreApplication::translate("cframe", "BUSCAR", nullptr));
        le_pathCF->setText(QString());
        btn_silaboE->setText(QCoreApplication::translate("cframe", "Ingresar", nullptr));
        btn_closeE->setText(QCoreApplication::translate("cframe", "Cerrar\n"
"Sesion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("cframe", "ENTREGA", nullptr));
        Rlbl_seleccion->setText(QCoreApplication::translate("cframe", "Seleccion:", nullptr));
        Rlbl_comentario->setText(QCoreApplication::translate("cframe", "Comentario:", nullptr));
        Rbtn_cambiar->setText(QCoreApplication::translate("cframe", "Cambiar", nullptr));
        Rlbl_estadoA->setText(QCoreApplication::translate("cframe", "Estado Actual:", nullptr));
        Rlbl_name_4->setText(QCoreApplication::translate("cframe", "Cambiar Estado:", nullptr));
        Rcb_cambiarE->setItemText(0, QCoreApplication::translate("cframe", "...", nullptr));

        Rbtn_cerrar->setText(QCoreApplication::translate("cframe", "Cerrar Sesion", nullptr));
        lbl_pngR->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("cframe", "REVISION", nullptr));
        Bbtn_aceptados->setText(QCoreApplication::translate("cframe", "Aceptados", nullptr));
        Bbtn_proceso->setText(QCoreApplication::translate("cframe", "En proceso", nullptr));
        Bbtn_cerrar->setText(QCoreApplication::translate("cframe", "Cerrar Sesion", nullptr));
        lbl_pngB->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("cframe", "BOARD", nullptr));
        Dbtn_sesion->setText(QCoreApplication::translate("cframe", "REVISAR", nullptr));
        Dbtn_salir->setText(QCoreApplication::translate("cframe", "SALIR", nullptr));
        Dlabel2->setText(QCoreApplication::translate("cframe", "..................................................................................", nullptr));
        Dlabel->setText(QCoreApplication::translate("cframe", "...................................................................................", nullptr));
        lbl_pngD->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("cframe", "DOCENTE", nullptr));
        lbl_pngRegistrar->setText(QString());
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

        lbl_facultadE_8->setText(QCoreApplication::translate("cframe", "Facultad:", nullptr));
        cb_facultadRegistro->setItemText(0, QCoreApplication::translate("cframe", "...", nullptr));
        cb_facultadRegistro->setItemText(1, QCoreApplication::translate("cframe", "FACULTAD DE INGENIER\303\215A", nullptr));
        cb_facultadRegistro->setItemText(2, QCoreApplication::translate("cframe", "FACULTAD DE CIENCIAS ADMINISTRATIVAS Y SOCIALES", nullptr));
        cb_facultadRegistro->setItemText(3, QCoreApplication::translate("cframe", "FACULTAD DE ARTE Y DISE\303\221O", nullptr));
        cb_facultadRegistro->setItemText(4, QCoreApplication::translate("cframe", "FACULTAD DE CIENCIAS DE LA SALUD", nullptr));
        cb_facultadRegistro->setItemText(5, QCoreApplication::translate("cframe", "FACULTAD DE POSTGRADO", nullptr));
        cb_facultadRegistro->setItemText(6, QCoreApplication::translate("cframe", "FACULTAD DE T\303\211CNICOS", nullptr));

        lbl_carreraE_2->setText(QCoreApplication::translate("cframe", "Programa Acad\303\251mico:", nullptr));
        cb_carreraRegistro->setItemText(0, QCoreApplication::translate("cframe", "...", nullptr));

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

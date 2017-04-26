/********************************************************************************
** Form generated from reading UI file 'vehiculo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEHICULO_H
#define UI_VEHICULO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vehiculo
{
public:
    QWidget *centralWidget;
    QLabel *label_8;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *gasolina;
    QRadioButton *diesel;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *colorVerde;
    QRadioButton *colorAmarillo;
    QRadioButton *colorAzul;
    QRadioButton *colorRojo;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *ruedaRespuesto;
    QRadioButton *kitReparacion;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *dosRuedas;
    QRadioButton *cuatroRuedas;
    QRadioButton *otroRuedas;
    QLineEdit *textoOtrosRuedas;
    QLabel *label_5;
    QTextBrowser *textBrowser;
    QLineEdit *matricula;
    QLabel *label_11;
    QLineEdit *nombreVehiculo;
    QLabel *label_6;
    QPushButton *guardarVehiculo;
    QSpinBox *numeroBocinas;
    QFrame *line;
    QLabel *label_4;
    QLabel *label_10;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLCDNumber *contadorCaballos;
    QSlider *caballosPotencia;
    QCheckBox *burbuja;
    QCheckBox *portavasos;
    QLabel *contCoches;
    QComboBox *vehiculosCreados;
    QPushButton *mostrarVehiculo;
    QLineEdit *tipoVehiculo;
    QLabel *complementos;
    QLabel *label_7;
    QPushButton *borrarDatos;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *vehiculo)
    {
        if (vehiculo->objectName().isEmpty())
            vehiculo->setObjectName(QStringLiteral("vehiculo"));
        vehiculo->resize(1119, 730);
        vehiculo->setAnimated(true);
        centralWidget = new QWidget(vehiculo);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("background-color: rgb(181, 181, 181);\n"
""));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 610, 91, 16));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_8->setFont(font);
        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(490, 200, 191, 61));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        gasolina = new QRadioButton(horizontalLayoutWidget_3);
        gasolina->setObjectName(QStringLiteral("gasolina"));
        QFont font1;
        font1.setFamily(QStringLiteral("Courier New"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        gasolina->setFont(font1);

        horizontalLayout_3->addWidget(gasolina);

        diesel = new QRadioButton(horizontalLayoutWidget_3);
        diesel->setObjectName(QStringLiteral("diesel"));
        diesel->setFont(font1);

        horizontalLayout_3->addWidget(diesel);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 180, 151, 21));
        label_2->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(380, 350, 321, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        colorVerde = new QRadioButton(horizontalLayoutWidget_2);
        colorVerde->setObjectName(QStringLiteral("colorVerde"));
        colorVerde->setFont(font1);
        colorVerde->setStyleSheet(QStringLiteral("color: rgb(7, 255, 3);"));

        horizontalLayout_2->addWidget(colorVerde);

        colorAmarillo = new QRadioButton(horizontalLayoutWidget_2);
        colorAmarillo->setObjectName(QStringLiteral("colorAmarillo"));
        colorAmarillo->setFont(font1);
        colorAmarillo->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));

        horizontalLayout_2->addWidget(colorAmarillo);

        colorAzul = new QRadioButton(horizontalLayoutWidget_2);
        colorAzul->setObjectName(QStringLiteral("colorAzul"));
        colorAzul->setFont(font1);
        colorAzul->setStyleSheet(QStringLiteral("color: rgb(64, 77, 255);"));

        horizontalLayout_2->addWidget(colorAzul);

        colorRojo = new QRadioButton(horizontalLayoutWidget_2);
        colorRojo->setObjectName(QStringLiteral("colorRojo"));
        colorRojo->setFont(font1);
        colorRojo->setStyleSheet(QStringLiteral("color: rgb(255, 21, 21);"));

        horizontalLayout_2->addWidget(colorRojo);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 221, 31));
        label->setFont(font);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 490, 178, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ruedaRespuesto = new QRadioButton(verticalLayoutWidget);
        ruedaRespuesto->setObjectName(QStringLiteral("ruedaRespuesto"));
        ruedaRespuesto->setFont(font1);

        verticalLayout->addWidget(ruedaRespuesto);

        kitReparacion = new QRadioButton(verticalLayoutWidget);
        kitReparacion->setObjectName(QStringLiteral("kitReparacion"));
        kitReparacion->setFont(font1);

        verticalLayout->addWidget(kitReparacion);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 220, 131, 21));
        label_3->setFont(font);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 210, 231, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dosRuedas = new QRadioButton(horizontalLayoutWidget);
        dosRuedas->setObjectName(QStringLiteral("dosRuedas"));
        dosRuedas->setFont(font1);

        horizontalLayout->addWidget(dosRuedas);

        cuatroRuedas = new QRadioButton(horizontalLayoutWidget);
        cuatroRuedas->setObjectName(QStringLiteral("cuatroRuedas"));
        cuatroRuedas->setFont(font1);

        horizontalLayout->addWidget(cuatroRuedas);

        otroRuedas = new QRadioButton(horizontalLayoutWidget);
        otroRuedas->setObjectName(QStringLiteral("otroRuedas"));
        otroRuedas->setFont(font1);

        horizontalLayout->addWidget(otroRuedas);

        textoOtrosRuedas = new QLineEdit(horizontalLayoutWidget);
        textoOtrosRuedas->setObjectName(QStringLiteral("textoOtrosRuedas"));
        textoOtrosRuedas->setEnabled(true);
        textoOtrosRuedas->setStyleSheet(QStringLiteral("background-color: rgb(247, 247, 247);"));

        horizontalLayout->addWidget(textoOtrosRuedas);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(380, 320, 61, 21));
        label_5->setFont(font);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(320, 20, 421, 61));
        textBrowser->setStyleSheet(QStringLiteral("background-color: rgb(197, 197, 197);"));
        matricula = new QLineEdit(centralWidget);
        matricula->setObjectName(QStringLiteral("matricula"));
        matricula->setGeometry(QRect(460, 610, 211, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Courier New"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        matricula->setFont(font2);
        matricula->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        matricula->setReadOnly(true);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(310, 610, 131, 31));
        label_11->setFont(font);
        nombreVehiculo = new QLineEdit(centralWidget);
        nombreVehiculo->setObjectName(QStringLiteral("nombreVehiculo"));
        nombreVehiculo->setGeometry(QRect(20, 120, 181, 31));
        nombreVehiculo->setStyleSheet(QStringLiteral("background-color: rgb(252, 252, 252);"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 470, 161, 16));
        label_6->setFont(font);
        guardarVehiculo = new QPushButton(centralWidget);
        guardarVehiculo->setObjectName(QStringLiteral("guardarVehiculo"));
        guardarVehiculo->setGeometry(QRect(730, 120, 121, 31));
        numeroBocinas = new QSpinBox(centralWidget);
        numeroBocinas->setObjectName(QStringLiteral("numeroBocinas"));
        numeroBocinas->setGeometry(QRect(50, 630, 42, 22));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        numeroBocinas->setFont(font3);
        numeroBocinas->setStyleSheet(QStringLiteral("background-color: rgb(249, 249, 249);"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(710, 100, 20, 541));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 310, 111, 21));
        label_4->setFont(font);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(320, 110, 321, 16));
        label_10->setFont(font);
        horizontalLayoutWidget_4 = new QWidget(centralWidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(20, 350, 251, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        contadorCaballos = new QLCDNumber(horizontalLayoutWidget_4);
        contadorCaballos->setObjectName(QStringLiteral("contadorCaballos"));
        contadorCaballos->setEnabled(true);
        contadorCaballos->setFont(font3);
        contadorCaballos->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));

        horizontalLayout_4->addWidget(contadorCaballos);

        caballosPotencia = new QSlider(horizontalLayoutWidget_4);
        caballosPotencia->setObjectName(QStringLiteral("caballosPotencia"));
        caballosPotencia->setFont(font3);
        caballosPotencia->setMaximum(1000);
        caballosPotencia->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(caballosPotencia);

        burbuja = new QCheckBox(centralWidget);
        burbuja->setObjectName(QStringLiteral("burbuja"));
        burbuja->setGeometry(QRect(410, 460, 191, 17));
        burbuja->setFont(font1);
        burbuja->setStyleSheet(QStringLiteral(""));
        portavasos = new QCheckBox(centralWidget);
        portavasos->setObjectName(QStringLiteral("portavasos"));
        portavasos->setGeometry(QRect(410, 520, 191, 17));
        portavasos->setFont(font1);
        portavasos->setStyleSheet(QStringLiteral(""));
        contCoches = new QLabel(centralWidget);
        contCoches->setObjectName(QStringLiteral("contCoches"));
        contCoches->setEnabled(true);
        contCoches->setGeometry(QRect(320, 130, 321, 31));
        contCoches->setFont(font1);
        vehiculosCreados = new QComboBox(centralWidget);
        vehiculosCreados->setObjectName(QStringLiteral("vehiculosCreados"));
        vehiculosCreados->setGeometry(QRect(730, 210, 121, 22));
        mostrarVehiculo = new QPushButton(centralWidget);
        mostrarVehiculo->setObjectName(QStringLiteral("mostrarVehiculo"));
        mostrarVehiculo->setGeometry(QRect(860, 120, 121, 31));
        tipoVehiculo = new QLineEdit(centralWidget);
        tipoVehiculo->setObjectName(QStringLiteral("tipoVehiculo"));
        tipoVehiculo->setGeometry(QRect(870, 210, 221, 31));
        tipoVehiculo->setFont(font);
        tipoVehiculo->setStyleSheet(QLatin1String("background-color: rgb(244, 244, 244);\n"
""));
        tipoVehiculo->setReadOnly(true);
        complementos = new QLabel(centralWidget);
        complementos->setObjectName(QStringLiteral("complementos"));
        complementos->setGeometry(QRect(420, 430, 161, 16));
        complementos->setFont(font);
        complementos->setStyleSheet(QStringLiteral(""));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(860, 170, 241, 31));
        label_7->setFont(font);
        borrarDatos = new QPushButton(centralWidget);
        borrarDatos->setObjectName(QStringLiteral("borrarDatos"));
        borrarDatos->setGeometry(QRect(990, 120, 121, 31));
        vehiculo->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(vehiculo);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1119, 21));
        vehiculo->setMenuBar(menuBar);
        mainToolBar = new QToolBar(vehiculo);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        vehiculo->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(vehiculo);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        vehiculo->setStatusBar(statusBar);

        retranslateUi(vehiculo);
        QObject::connect(caballosPotencia, SIGNAL(valueChanged(int)), contadorCaballos, SLOT(display(int)));

        QMetaObject::connectSlotsByName(vehiculo);
    } // setupUi

    void retranslateUi(QMainWindow *vehiculo)
    {
        vehiculo->setWindowTitle(QApplication::translate("vehiculo", "vehiculo", Q_NULLPTR));
        label_8->setText(QApplication::translate("vehiculo", "Bocinas", Q_NULLPTR));
        gasolina->setText(QApplication::translate("vehiculo", "Gasolina", Q_NULLPTR));
        diesel->setText(QApplication::translate("vehiculo", "Diesel", Q_NULLPTR));
        label_2->setText(QApplication::translate("vehiculo", "Ruedas", Q_NULLPTR));
        colorVerde->setText(QApplication::translate("vehiculo", "Verde", Q_NULLPTR));
        colorAmarillo->setText(QApplication::translate("vehiculo", "Amarillo", Q_NULLPTR));
        colorAzul->setText(QApplication::translate("vehiculo", "Azul", Q_NULLPTR));
        colorRojo->setText(QApplication::translate("vehiculo", "Rojo", Q_NULLPTR));
        label->setText(QApplication::translate("vehiculo", "Nombre del Vehiculo", Q_NULLPTR));
        ruedaRespuesto->setText(QApplication::translate("vehiculo", "Rueda de Repuesto", Q_NULLPTR));
        kitReparacion->setText(QApplication::translate("vehiculo", "Kit de Reparaci\303\263n", Q_NULLPTR));
        label_3->setText(QApplication::translate("vehiculo", "Combustible", Q_NULLPTR));
        dosRuedas->setText(QApplication::translate("vehiculo", "2", Q_NULLPTR));
        cuatroRuedas->setText(QApplication::translate("vehiculo", "4", Q_NULLPTR));
        otroRuedas->setText(QApplication::translate("vehiculo", "Otros", Q_NULLPTR));
        textoOtrosRuedas->setText(QString());
        label_5->setText(QApplication::translate("vehiculo", "Color", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("vehiculo", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:28pt; font-weight:600; text-decoration: underline; color:#ffaa00;\">!CREA TU VEHICULO!</span></p></body></html>", Q_NULLPTR));
        matricula->setText(QString());
        label_11->setText(QApplication::translate("vehiculo", "Matricula", Q_NULLPTR));
        nombreVehiculo->setText(QString());
        label_6->setText(QApplication::translate("vehiculo", "Herramientas", Q_NULLPTR));
        guardarVehiculo->setText(QApplication::translate("vehiculo", "Guardar Vehiculo", Q_NULLPTR));
        label_4->setText(QApplication::translate("vehiculo", "Potencia", Q_NULLPTR));
        label_10->setText(QApplication::translate("vehiculo", "N\303\272mero de Vehiculos Guardados", Q_NULLPTR));
        burbuja->setText(QApplication::translate("vehiculo", "Burbuja Para Ni\303\261os", Q_NULLPTR));
        portavasos->setText(QApplication::translate("vehiculo", "Portavasos Gigantes", Q_NULLPTR));
        contCoches->setText(QString());
        mostrarVehiculo->setText(QApplication::translate("vehiculo", "Mostrar Vehiculo", Q_NULLPTR));
        tipoVehiculo->setText(QString());
        complementos->setText(QApplication::translate("vehiculo", "Complementos", Q_NULLPTR));
        label_7->setText(QApplication::translate("vehiculo", "Nombre Coche Guardado", Q_NULLPTR));
        borrarDatos->setText(QApplication::translate("vehiculo", "Crear Coche", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class vehiculo: public Ui_vehiculo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHICULO_H

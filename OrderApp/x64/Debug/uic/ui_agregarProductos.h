/********************************************************************************
** Form generated from reading UI file 'agregarProductos.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARPRODUCTOS_H
#define UI_AGREGARPRODUCTOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_agregarProductos
{
public:
    QLabel *label_11;
    QLabel *txt_estado;
    QLabel *txt_orden;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_3;
    QListWidget *list_res;
    QWidget *tab_2;
    QLabel *label_6;
    QListWidget *list_pollo;
    QWidget *tab_3;
    QLabel *label_4;
    QListWidget *list_cerdo;
    QWidget *tab_4;
    QLabel *label_5;
    QListWidget *list_camarones;
    QWidget *tab_5;
    QLabel *label_7;
    QListWidget *list_pescado;
    QWidget *tab_6;
    QListWidget *list_mixtos;
    QLabel *label_17;
    QWidget *tab_7;
    QListWidget *list_tipicos;
    QLabel *label_18;
    QWidget *tab_8;
    QLabel *label_19;
    QListWidget *list_extras;
    QWidget *tab_9;
    QLabel *label_20;
    QListWidget *list_bebidas;
    QLabel *label_15;
    QLabel *label_12;
    QPushButton *butt_agregar;
    QLabel *txt_cliente;
    QPushButton *butt_view_order;
    QLabel *txt_fecha;
    QLabel *label_13;
    QPushButton *butt_cancel;

    void setupUi(QDialog *agregarProductos)
    {
        if (agregarProductos->objectName().isEmpty())
            agregarProductos->setObjectName("agregarProductos");
        agregarProductos->resize(1032, 540);
        label_11 = new QLabel(agregarProductos);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(23, 10, 61, 20));
        QFont font;
        font.setPointSize(11);
        label_11->setFont(font);
        txt_estado = new QLabel(agregarProductos);
        txt_estado->setObjectName("txt_estado");
        txt_estado->setGeometry(QRect(73, 60, 101, 20));
        txt_estado->setFont(font);
        txt_orden = new QLabel(agregarProductos);
        txt_orden->setObjectName("txt_orden");
        txt_orden->setGeometry(QRect(73, 10, 101, 20));
        txt_orden->setFont(font);
        tabWidget = new QTabWidget(agregarProductos);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 118, 1011, 341));
        QFont font1;
        font1.setPointSize(18);
        tabWidget->setFont(font1);
        tabWidget->setIconSize(QSize(16, 16));
        tab = new QWidget();
        tab->setObjectName("tab");
        tab->setEnabled(true);
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 331, 20));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        label_3->setFont(font2);
        list_res = new QListWidget(tab);
        list_res->setObjectName("list_res");
        list_res->setGeometry(QRect(0, 40, 1011, 261));
        list_res->setFont(font1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 10, 51, 20));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        label_6->setFont(font3);
        list_pollo = new QListWidget(tab_2);
        list_pollo->setObjectName("list_pollo");
        list_pollo->setGeometry(QRect(0, 40, 1011, 291));
        list_pollo->setFont(font1);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        label_4 = new QLabel(tab_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 10, 331, 20));
        label_4->setFont(font3);
        list_cerdo = new QListWidget(tab_3);
        list_cerdo->setObjectName("list_cerdo");
        list_cerdo->setGeometry(QRect(0, 40, 1011, 261));
        list_cerdo->setFont(font1);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        label_5 = new QLabel(tab_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 10, 331, 20));
        label_5->setFont(font3);
        list_camarones = new QListWidget(tab_4);
        list_camarones->setObjectName("list_camarones");
        list_camarones->setGeometry(QRect(0, 40, 1011, 261));
        list_camarones->setFont(font1);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        label_7 = new QLabel(tab_5);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 10, 331, 20));
        label_7->setFont(font3);
        list_pescado = new QListWidget(tab_5);
        list_pescado->setObjectName("list_pescado");
        list_pescado->setGeometry(QRect(0, 40, 1011, 261));
        list_pescado->setFont(font1);
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        list_mixtos = new QListWidget(tab_6);
        list_mixtos->setObjectName("list_mixtos");
        list_mixtos->setGeometry(QRect(0, 40, 1011, 261));
        list_mixtos->setFont(font1);
        label_17 = new QLabel(tab_6);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 10, 331, 20));
        label_17->setFont(font3);
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        list_tipicos = new QListWidget(tab_7);
        list_tipicos->setObjectName("list_tipicos");
        list_tipicos->setGeometry(QRect(0, 40, 1011, 261));
        list_tipicos->setFont(font1);
        label_18 = new QLabel(tab_7);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 10, 331, 20));
        label_18->setFont(font3);
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        label_19 = new QLabel(tab_8);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 10, 331, 20));
        label_19->setFont(font3);
        list_extras = new QListWidget(tab_8);
        list_extras->setObjectName("list_extras");
        list_extras->setGeometry(QRect(0, 40, 1011, 261));
        list_extras->setFont(font1);
        tabWidget->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        label_20 = new QLabel(tab_9);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(10, 10, 331, 20));
        label_20->setFont(font3);
        list_bebidas = new QListWidget(tab_9);
        list_bebidas->setObjectName("list_bebidas");
        list_bebidas->setGeometry(QRect(0, 40, 1011, 261));
        list_bebidas->setFont(font1);
        tabWidget->addTab(tab_9, QString());
        label_15 = new QLabel(agregarProductos);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(26, 85, 41, 20));
        label_15->setFont(font);
        label_12 = new QLabel(agregarProductos);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(18, 35, 51, 20));
        label_12->setFont(font);
        butt_agregar = new QPushButton(agregarProductos);
        butt_agregar->setObjectName("butt_agregar");
        butt_agregar->setGeometry(QRect(10, 500, 35, 35));
        QFont font4;
        font4.setPointSize(9);
        butt_agregar->setFont(font4);
        butt_agregar->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        butt_agregar->setIconSize(QSize(26, 26));
        txt_cliente = new QLabel(agregarProductos);
        txt_cliente->setObjectName("txt_cliente");
        txt_cliente->setGeometry(QRect(73, 35, 101, 20));
        txt_cliente->setFont(font);
        butt_view_order = new QPushButton(agregarProductos);
        butt_view_order->setObjectName("butt_view_order");
        butt_view_order->setGeometry(QRect(950, 10, 60, 60));
        butt_view_order->setIconSize(QSize(50, 50));
        txt_fecha = new QLabel(agregarProductos);
        txt_fecha->setObjectName("txt_fecha");
        txt_fecha->setGeometry(QRect(73, 85, 101, 20));
        txt_fecha->setFont(font);
        label_13 = new QLabel(agregarProductos);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 60, 51, 20));
        label_13->setFont(font);
        butt_cancel = new QPushButton(agregarProductos);
        butt_cancel->setObjectName("butt_cancel");
        butt_cancel->setGeometry(QRect(970, 480, 50, 50));
        QFont font5;
        font5.setPointSize(12);
        butt_cancel->setFont(font5);
        butt_cancel->setIconSize(QSize(40, 40));

        retranslateUi(agregarProductos);
        QObject::connect(list_res, &QListWidget::itemClicked, butt_agregar, qOverload<>(&QPushButton::click));
        QObject::connect(list_pollo, &QListWidget::itemClicked, butt_agregar, qOverload<>(&QPushButton::click));
        QObject::connect(list_cerdo, &QListWidget::itemClicked, butt_agregar, qOverload<>(&QPushButton::click));
        QObject::connect(list_camarones, &QListWidget::itemClicked, butt_agregar, qOverload<>(&QPushButton::click));
        QObject::connect(list_mixtos, &QListWidget::itemClicked, butt_agregar, qOverload<>(&QPushButton::click));
        QObject::connect(list_tipicos, &QListWidget::itemClicked, butt_agregar, qOverload<>(&QPushButton::click));
        QObject::connect(list_pescado, &QListWidget::itemClicked, butt_agregar, qOverload<>(&QPushButton::click));
        QObject::connect(list_extras, &QListWidget::itemClicked, butt_agregar, qOverload<>(&QPushButton::click));
        QObject::connect(list_bebidas, &QListWidget::itemClicked, butt_agregar, qOverload<>(&QPushButton::click));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(agregarProductos);
    } // setupUi

    void retranslateUi(QDialog *agregarProductos)
    {
        agregarProductos->setWindowTitle(QCoreApplication::translate("agregarProductos", "Agregar Producto", nullptr));
        label_11->setText(QCoreApplication::translate("agregarProductos", "Orden:", nullptr));
        txt_estado->setText(QString());
        txt_orden->setText(QString());
        label_3->setText(QCoreApplication::translate("agregarProductos", "Res", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("agregarProductos", "Res", nullptr));
        label_6->setText(QCoreApplication::translate("agregarProductos", "Pollo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("agregarProductos", "Pollo", nullptr));
        label_4->setText(QCoreApplication::translate("agregarProductos", "Cerdo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("agregarProductos", "Cerdo", nullptr));
        label_5->setText(QCoreApplication::translate("agregarProductos", "Camarones", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("agregarProductos", "Camarones", nullptr));
        label_7->setText(QCoreApplication::translate("agregarProductos", "Pescado", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("agregarProductos", "Pescado", nullptr));
        label_17->setText(QCoreApplication::translate("agregarProductos", "Platos Mixtos", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("agregarProductos", "Platos Mixtos", nullptr));
        label_18->setText(QCoreApplication::translate("agregarProductos", "Platos T\303\255picos", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("agregarProductos", "Platos T\303\255picos", nullptr));
        label_19->setText(QCoreApplication::translate("agregarProductos", "Extras", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("agregarProductos", "Extras", nullptr));
        label_20->setText(QCoreApplication::translate("agregarProductos", "Bebidas", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("agregarProductos", "Bebidas", nullptr));
        label_15->setText(QCoreApplication::translate("agregarProductos", "Fecha:", nullptr));
        label_12->setText(QCoreApplication::translate("agregarProductos", "Cliente:", nullptr));
        butt_agregar->setText(QString());
        txt_cliente->setText(QString());
        butt_view_order->setText(QString());
        txt_fecha->setText(QString());
        label_13->setText(QCoreApplication::translate("agregarProductos", "Estado:", nullptr));
        butt_cancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class agregarProductos: public Ui_agregarProductos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARPRODUCTOS_H

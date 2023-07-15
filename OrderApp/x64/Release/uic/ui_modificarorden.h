/********************************************************************************
** Form generated from reading UI file 'modificarorden.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICARORDEN_H
#define UI_MODIFICARORDEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ModificarOrden
{
public:
    QListWidget *list_ordenes;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_estado;
    QLabel *label_15;
    QLabel *label_hora;
    QLabel *label_12;
    QLabel *label_orden;
    QLabel *label_cliente;
    QLabel *label_16;
    QLabel *label_fecha;
    QLabel *label_17;
    QLabel *label_total;
    QPushButton *butt_seleccionar;
    QPushButton *butt_mod_prods;
    QPushButton *butt_eliminar;
    QPushButton *butt_pagar;
    QPushButton *butt_cancelar;
    QPushButton *butt_end;
    QListWidget *list_productos;
    QLabel *label_14;
    QLabel *label_18;

    void setupUi(QDialog *ModificarOrden)
    {
        if (ModificarOrden->objectName().isEmpty())
            ModificarOrden->setObjectName("ModificarOrden");
        ModificarOrden->resize(679, 509);
        list_ordenes = new QListWidget(ModificarOrden);
        list_ordenes->setObjectName("list_ordenes");
        list_ordenes->setGeometry(QRect(10, 49, 321, 341));
        QFont font;
        font.setPointSize(11);
        list_ordenes->setFont(font);
        label_13 = new QLabel(ModificarOrden);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(456, 110, 61, 16));
        label_13->setFont(font);
        label_11 = new QLabel(ModificarOrden);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(379, 50, 127, 16));
        label_11->setFont(font);
        label_estado = new QLabel(ModificarOrden);
        label_estado->setObjectName("label_estado");
        label_estado->setGeometry(QRect(510, 110, 161, 20));
        label_estado->setFont(font);
        label_15 = new QLabel(ModificarOrden);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(468, 140, 41, 16));
        label_15->setFont(font);
        label_hora = new QLabel(ModificarOrden);
        label_hora->setObjectName("label_hora");
        label_hora->setGeometry(QRect(510, 140, 161, 20));
        label_hora->setFont(font);
        label_12 = new QLabel(ModificarOrden);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(375, 80, 131, 16));
        label_12->setFont(font);
        label_orden = new QLabel(ModificarOrden);
        label_orden->setObjectName("label_orden");
        label_orden->setGeometry(QRect(510, 50, 161, 20));
        label_orden->setFont(font);
        label_cliente = new QLabel(ModificarOrden);
        label_cliente->setObjectName("label_cliente");
        label_cliente->setGeometry(QRect(510, 80, 161, 20));
        label_cliente->setFont(font);
        label_16 = new QLabel(ModificarOrden);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(462, 170, 41, 16));
        label_16->setFont(font);
        label_fecha = new QLabel(ModificarOrden);
        label_fecha->setObjectName("label_fecha");
        label_fecha->setGeometry(QRect(510, 170, 161, 20));
        label_fecha->setFont(font);
        label_17 = new QLabel(ModificarOrden);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(560, 400, 51, 16));
        label_17->setFont(font);
        label_total = new QLabel(ModificarOrden);
        label_total->setObjectName("label_total");
        label_total->setGeometry(QRect(620, 400, 51, 16));
        label_total->setFont(font);
        butt_seleccionar = new QPushButton(ModificarOrden);
        butt_seleccionar->setObjectName("butt_seleccionar");
        butt_seleccionar->setGeometry(QRect(10, 390, 50, 50));
        QFont font1;
        font1.setPointSize(12);
        butt_seleccionar->setFont(font1);
        butt_seleccionar->setIconSize(QSize(40, 40));
        butt_mod_prods = new QPushButton(ModificarOrden);
        butt_mod_prods->setObjectName("butt_mod_prods");
        butt_mod_prods->setGeometry(QRect(70, 30, 16, 16));
        butt_eliminar = new QPushButton(ModificarOrden);
        butt_eliminar->setObjectName("butt_eliminar");
        butt_eliminar->setGeometry(QRect(62, 390, 50, 50));
        butt_eliminar->setFont(font1);
        butt_eliminar->setIconSize(QSize(40, 40));
        butt_pagar = new QPushButton(ModificarOrden);
        butt_pagar->setObjectName("butt_pagar");
        butt_pagar->setGeometry(QRect(114, 390, 50, 50));
        butt_pagar->setFont(font1);
        butt_pagar->setIconSize(QSize(40, 40));
        butt_cancelar = new QPushButton(ModificarOrden);
        butt_cancelar->setObjectName("butt_cancelar");
        butt_cancelar->setGeometry(QRect(620, 450, 50, 50));
        butt_cancelar->setFont(font1);
        butt_cancelar->setIconSize(QSize(40, 40));
        butt_end = new QPushButton(ModificarOrden);
        butt_end->setObjectName("butt_end");
        butt_end->setGeometry(QRect(166, 390, 50, 50));
        butt_end->setFont(font1);
        butt_end->setIconSize(QSize(40, 40));
        list_productos = new QListWidget(ModificarOrden);
        list_productos->setObjectName("list_productos");
        list_productos->setGeometry(QRect(350, 220, 321, 171));
        list_productos->setFont(font);
        label_14 = new QLabel(ModificarOrden);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 30, 127, 16));
        label_14->setFont(font);
        label_18 = new QLabel(ModificarOrden);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(350, 200, 141, 16));
        label_18->setFont(font);

        retranslateUi(ModificarOrden);
        QObject::connect(list_ordenes, &QListWidget::itemClicked, butt_mod_prods, qOverload<>(&QPushButton::click));

        QMetaObject::connectSlotsByName(ModificarOrden);
    } // setupUi

    void retranslateUi(QDialog *ModificarOrden)
    {
        ModificarOrden->setWindowTitle(QCoreApplication::translate("ModificarOrden", "Ordenes", nullptr));
        label_13->setText(QCoreApplication::translate("ModificarOrden", "Estado:", nullptr));
        label_11->setText(QCoreApplication::translate("ModificarOrden", "Numero de Orden:", nullptr));
        label_estado->setText(QString());
        label_15->setText(QCoreApplication::translate("ModificarOrden", "Hora:", nullptr));
        label_hora->setText(QString());
        label_12->setText(QCoreApplication::translate("ModificarOrden", "Nombre de Cliente:", nullptr));
        label_orden->setText(QString());
        label_cliente->setText(QString());
        label_16->setText(QCoreApplication::translate("ModificarOrden", "Fecha:", nullptr));
        label_fecha->setText(QString());
        label_17->setText(QCoreApplication::translate("ModificarOrden", "Total:  L", nullptr));
        label_total->setText(QString());
        butt_seleccionar->setText(QString());
        butt_mod_prods->setText(QString());
        butt_eliminar->setText(QString());
        butt_pagar->setText(QString());
        butt_cancelar->setText(QString());
        butt_end->setText(QString());
        label_14->setText(QCoreApplication::translate("ModificarOrden", "Ordenes", nullptr));
        label_18->setText(QCoreApplication::translate("ModificarOrden", "Productos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModificarOrden: public Ui_ModificarOrden {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICARORDEN_H

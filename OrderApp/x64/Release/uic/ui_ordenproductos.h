/********************************************************************************
** Form generated from reading UI file 'ordenproductos.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDENPRODUCTOS_H
#define UI_ORDENPRODUCTOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_OrdenProductos
{
public:
    QLabel *label_orden;
    QLabel *label_cliente;
    QPushButton *butt_eliminar;
    QLabel *label_5;
    QLabel *label_total;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *butt_send;
    QPushButton *butt_back;
    QTableWidget *table_orden;
    QPushButton *butt_edit;

    void setupUi(QDialog *OrdenProductos)
    {
        if (OrdenProductos->objectName().isEmpty())
            OrdenProductos->setObjectName("OrdenProductos");
        OrdenProductos->resize(810, 406);
        label_orden = new QLabel(OrdenProductos);
        label_orden->setObjectName("label_orden");
        label_orden->setGeometry(QRect(82, 14, 110, 20));
        QFont font;
        font.setPointSize(11);
        label_orden->setFont(font);
        label_cliente = new QLabel(OrdenProductos);
        label_cliente->setObjectName("label_cliente");
        label_cliente->setGeometry(QRect(82, 36, 110, 20));
        label_cliente->setFont(font);
        butt_eliminar = new QPushButton(OrdenProductos);
        butt_eliminar->setObjectName("butt_eliminar");
        butt_eliminar->setGeometry(QRect(60, 290, 50, 50));
        QFont font1;
        font1.setPointSize(9);
        butt_eliminar->setFont(font1);
        butt_eliminar->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        butt_eliminar->setIconSize(QSize(40, 40));
        label_5 = new QLabel(OrdenProductos);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(680, 298, 49, 16));
        QFont font2;
        font2.setPointSize(12);
        label_5->setFont(font2);
        label_total = new QLabel(OrdenProductos);
        label_total->setObjectName("label_total");
        label_total->setGeometry(QRect(740, 298, 61, 16));
        label_total->setFont(font2);
        label_11 = new QLabel(OrdenProductos);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(27, 14, 51, 20));
        label_11->setFont(font);
        label_12 = new QLabel(OrdenProductos);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(22, 36, 51, 20));
        label_12->setFont(font);
        butt_send = new QPushButton(OrdenProductos);
        butt_send->setObjectName("butt_send");
        butt_send->setGeometry(QRect(752, 348, 50, 50));
        butt_send->setIconSize(QSize(40, 40));
        butt_back = new QPushButton(OrdenProductos);
        butt_back->setObjectName("butt_back");
        butt_back->setGeometry(QRect(700, 348, 50, 50));
        butt_back->setIconSize(QSize(40, 40));
        table_orden = new QTableWidget(OrdenProductos);
        if (table_orden->columnCount() < 6)
            table_orden->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_orden->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_orden->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_orden->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_orden->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_orden->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_orden->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        table_orden->setObjectName("table_orden");
        table_orden->setGeometry(QRect(10, 58, 791, 231));
        table_orden->setFont(font);
        table_orden->setShowGrid(false);
        table_orden->horizontalHeader()->setDefaultSectionSize(128);
        butt_edit = new QPushButton(OrdenProductos);
        butt_edit->setObjectName("butt_edit");
        butt_edit->setGeometry(QRect(8, 290, 50, 50));
        butt_edit->setIconSize(QSize(40, 40));
        label_orden->raise();
        label_cliente->raise();
        label_5->raise();
        label_total->raise();
        label_11->raise();
        label_12->raise();
        butt_send->raise();
        butt_back->raise();
        butt_eliminar->raise();
        table_orden->raise();
        butt_edit->raise();

        retranslateUi(OrdenProductos);

        QMetaObject::connectSlotsByName(OrdenProductos);
    } // setupUi

    void retranslateUi(QDialog *OrdenProductos)
    {
        OrdenProductos->setWindowTitle(QCoreApplication::translate("OrdenProductos", "Resumen de Orden", nullptr));
        label_orden->setText(QString());
        label_cliente->setText(QString());
        butt_eliminar->setText(QString());
        label_5->setText(QCoreApplication::translate("OrdenProductos", "Total: L", nullptr));
        label_total->setText(QCoreApplication::translate("OrdenProductos", "0.00", nullptr));
        label_11->setText(QCoreApplication::translate("OrdenProductos", "Orden:", nullptr));
        label_12->setText(QCoreApplication::translate("OrdenProductos", "Cliente:", nullptr));
        butt_send->setText(QString());
        butt_back->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_orden->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("OrdenProductos", "Cantidad", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_orden->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("OrdenProductos", "Descripcion", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_orden->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("OrdenProductos", "Complemento 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_orden->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("OrdenProductos", "Complemento 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_orden->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("OrdenProductos", "Comentario", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_orden->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("OrdenProductos", "Precio", nullptr));
        butt_edit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OrdenProductos: public Ui_OrdenProductos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDENPRODUCTOS_H

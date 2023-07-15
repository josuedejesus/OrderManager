/********************************************************************************
** Form generated from reading UI file 'estadistica.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESTADISTICA_H
#define UI_ESTADISTICA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Estadistica
{
public:
    QTableWidget *table_products;

    void setupUi(QDialog *Estadistica)
    {
        if (Estadistica->objectName().isEmpty())
            Estadistica->setObjectName("Estadistica");
        Estadistica->resize(427, 348);
        table_products = new QTableWidget(Estadistica);
        if (table_products->columnCount() < 2)
            table_products->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_products->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_products->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table_products->setObjectName("table_products");
        table_products->setGeometry(QRect(80, 80, 256, 192));

        retranslateUi(Estadistica);

        QMetaObject::connectSlotsByName(Estadistica);
    } // setupUi

    void retranslateUi(QDialog *Estadistica)
    {
        Estadistica->setWindowTitle(QCoreApplication::translate("Estadistica", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_products->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Estadistica", "Descripcion", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_products->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Estadistica", "Cantidad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Estadistica: public Ui_Estadistica {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTADISTICA_H

/********************************************************************************
** Form generated from reading UI file 'opcionesproducto.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPCIONESPRODUCTO_H
#define UI_OPCIONESPRODUCTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_opcionesProducto
{
public:
    QTextEdit *txt_comment;
    QLabel *label_comp2;
    QComboBox *combo_comp1;
    QPushButton *butt_cancel;
    QLabel *label_comment;
    QLabel *label_comp1;
    QComboBox *combo_comp2;
    QPushButton *butt_ok;
    QLabel *label_producto;
    QComboBox *combo_base;
    QLabel *label_base;
    QLabel *label;
    QLabel *label_valor;
    QPushButton *butt_extra;
    QSpinBox *spin_cantidad;
    QLabel *label_cantidad;
    QPushButton *butt_actions;

    void setupUi(QDialog *opcionesProducto)
    {
        if (opcionesProducto->objectName().isEmpty())
            opcionesProducto->setObjectName("opcionesProducto");
        opcionesProducto->resize(413, 358);
        txt_comment = new QTextEdit(opcionesProducto);
        txt_comment->setObjectName("txt_comment");
        txt_comment->setGeometry(QRect(6, 180, 401, 61));
        label_comp2 = new QLabel(opcionesProducto);
        label_comp2->setObjectName("label_comp2");
        label_comp2->setGeometry(QRect(16, 130, 111, 16));
        QFont font;
        font.setPointSize(11);
        label_comp2->setFont(font);
        combo_comp1 = new QComboBox(opcionesProducto);
        combo_comp1->addItem(QString());
        combo_comp1->addItem(QString());
        combo_comp1->addItem(QString());
        combo_comp1->addItem(QString());
        combo_comp1->addItem(QString());
        combo_comp1->setObjectName("combo_comp1");
        combo_comp1->setGeometry(QRect(146, 98, 172, 25));
        combo_comp1->setFont(font);
        butt_cancel = new QPushButton(opcionesProducto);
        butt_cancel->setObjectName("butt_cancel");
        butt_cancel->setGeometry(QRect(356, 300, 50, 50));
        butt_cancel->setFont(font);
        butt_cancel->setIconSize(QSize(40, 40));
        label_comment = new QLabel(opcionesProducto);
        label_comment->setObjectName("label_comment");
        label_comment->setGeometry(QRect(16, 160, 81, 16));
        label_comment->setFont(font);
        label_comp1 = new QLabel(opcionesProducto);
        label_comp1->setObjectName("label_comp1");
        label_comp1->setGeometry(QRect(16, 100, 111, 16));
        label_comp1->setFont(font);
        combo_comp2 = new QComboBox(opcionesProducto);
        combo_comp2->addItem(QString());
        combo_comp2->addItem(QString());
        combo_comp2->setObjectName("combo_comp2");
        combo_comp2->setGeometry(QRect(146, 128, 172, 25));
        combo_comp2->setFont(font);
        butt_ok = new QPushButton(opcionesProducto);
        butt_ok->setObjectName("butt_ok");
        butt_ok->setGeometry(QRect(304, 300, 50, 50));
        butt_ok->setFont(font);
        butt_ok->setIconSize(QSize(40, 40));
        label_producto = new QLabel(opcionesProducto);
        label_producto->setObjectName("label_producto");
        label_producto->setGeometry(QRect(16, 10, 241, 16));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_producto->setFont(font1);
        combo_base = new QComboBox(opcionesProducto);
        combo_base->addItem(QString());
        combo_base->addItem(QString());
        combo_base->addItem(QString());
        combo_base->setObjectName("combo_base");
        combo_base->setGeometry(QRect(146, 68, 172, 25));
        combo_base->setFont(font);
        label_base = new QLabel(opcionesProducto);
        label_base->setObjectName("label_base");
        label_base->setGeometry(QRect(21, 70, 111, 16));
        label_base->setFont(font);
        label = new QLabel(opcionesProducto);
        label->setObjectName("label");
        label->setGeometry(QRect(287, 250, 41, 16));
        label->setFont(font);
        label_valor = new QLabel(opcionesProducto);
        label_valor->setObjectName("label_valor");
        label_valor->setGeometry(QRect(330, 250, 61, 16));
        label_valor->setFont(font);
        butt_extra = new QPushButton(opcionesProducto);
        butt_extra->setObjectName("butt_extra");
        butt_extra->setGeometry(QRect(6, 244, 50, 50));
        butt_extra->setFont(font);
        butt_extra->setIconSize(QSize(40, 40));
        spin_cantidad = new QSpinBox(opcionesProducto);
        spin_cantidad->setObjectName("spin_cantidad");
        spin_cantidad->setGeometry(QRect(146, 38, 51, 25));
        spin_cantidad->setFont(font);
        spin_cantidad->setReadOnly(false);
        spin_cantidad->setMinimum(1);
        label_cantidad = new QLabel(opcionesProducto);
        label_cantidad->setObjectName("label_cantidad");
        label_cantidad->setGeometry(QRect(60, 40, 61, 16));
        label_cantidad->setFont(font);
        label_cantidad->setLayoutDirection(Qt::LeftToRight);
        butt_actions = new QPushButton(opcionesProducto);
        butt_actions->setObjectName("butt_actions");
        butt_actions->setGeometry(QRect(380, 70, 21, 24));

        retranslateUi(opcionesProducto);
        QObject::connect(spin_cantidad, &QSpinBox::textChanged, butt_actions, qOverload<>(&QPushButton::click));
        QObject::connect(combo_base, &QComboBox::currentIndexChanged, butt_actions, qOverload<>(&QPushButton::click));
        QObject::connect(combo_comp1, &QComboBox::currentTextChanged, butt_actions, qOverload<>(&QPushButton::click));

        QMetaObject::connectSlotsByName(opcionesProducto);
    } // setupUi

    void retranslateUi(QDialog *opcionesProducto)
    {
        opcionesProducto->setWindowTitle(QCoreApplication::translate("opcionesProducto", "Opciones de Plato", nullptr));
        label_comp2->setText(QCoreApplication::translate("opcionesProducto", "Complemento 2", nullptr));
        combo_comp1->setItemText(0, QCoreApplication::translate("opcionesProducto", "Platano Verde", nullptr));
        combo_comp1->setItemText(1, QCoreApplication::translate("opcionesProducto", "Guineo Verde", nullptr));
        combo_comp1->setItemText(2, QCoreApplication::translate("opcionesProducto", "Papas Fritas", nullptr));
        combo_comp1->setItemText(3, QCoreApplication::translate("opcionesProducto", "Totillas de Ma\303\255z", nullptr));
        combo_comp1->setItemText(4, QCoreApplication::translate("opcionesProducto", "Platano Maduro", nullptr));

        butt_cancel->setText(QString());
        label_comment->setText(QCoreApplication::translate("opcionesProducto", "Comentario", nullptr));
        label_comp1->setText(QCoreApplication::translate("opcionesProducto", "Complemento 1", nullptr));
        combo_comp2->setItemText(0, QCoreApplication::translate("opcionesProducto", "Frijoles Fritos", nullptr));
        combo_comp2->setItemText(1, QCoreApplication::translate("opcionesProducto", "Rice and Beans", nullptr));

        butt_ok->setText(QString());
        label_producto->setText(QString());
        combo_base->setItemText(0, QCoreApplication::translate("opcionesProducto", "Res - Pollo", nullptr));
        combo_base->setItemText(1, QCoreApplication::translate("opcionesProducto", "Res - Chuleta", nullptr));
        combo_base->setItemText(2, QCoreApplication::translate("opcionesProducto", "Res - Costilla", nullptr));

        label_base->setText(QCoreApplication::translate("opcionesProducto", "Tipo de Carnes", nullptr));
        label->setText(QCoreApplication::translate("opcionesProducto", "Valor:", nullptr));
        label_valor->setText(QString());
        butt_extra->setText(QString());
        label_cantidad->setText(QCoreApplication::translate("opcionesProducto", "Cantidad", nullptr));
        butt_actions->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class opcionesProducto: public Ui_opcionesProducto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPCIONESPRODUCTO_H

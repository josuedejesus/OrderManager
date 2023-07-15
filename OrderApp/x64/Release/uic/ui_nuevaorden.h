/********************************************************************************
** Form generated from reading UI file 'nuevaorden.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVAORDEN_H
#define UI_NUEVAORDEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NuevaOrden
{
public:
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_15;
    QPushButton *butt_ok;
    QPushButton *butt_cancel;
    QLineEdit *txt_id;
    QLineEdit *txt_nombre;
    QLabel *txt_estado;
    QLabel *txt_fecha;
    QComboBox *comboBox;
    QLabel *label_14;

    void setupUi(QDialog *NuevaOrden)
    {
        if (NuevaOrden->objectName().isEmpty())
            NuevaOrden->setObjectName("NuevaOrden");
        NuevaOrden->resize(400, 300);
        label_11 = new QLabel(NuevaOrden);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(46, 80, 131, 16));
        QFont font;
        font.setPointSize(11);
        label_11->setFont(font);
        label_12 = new QLabel(NuevaOrden);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(42, 110, 141, 16));
        label_12->setFont(font);
        label_13 = new QLabel(NuevaOrden);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(123, 170, 51, 16));
        label_13->setFont(font);
        label_15 = new QLabel(NuevaOrden);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(130, 200, 41, 16));
        label_15->setFont(font);
        butt_ok = new QPushButton(NuevaOrden);
        butt_ok->setObjectName("butt_ok");
        butt_ok->setGeometry(QRect(288, 240, 50, 50));
        butt_ok->setIconSize(QSize(40, 40));
        butt_cancel = new QPushButton(NuevaOrden);
        butt_cancel->setObjectName("butt_cancel");
        butt_cancel->setGeometry(QRect(340, 240, 50, 50));
        butt_cancel->setIconSize(QSize(40, 40));
        txt_id = new QLineEdit(NuevaOrden);
        txt_id->setObjectName("txt_id");
        txt_id->setGeometry(QRect(182, 80, 161, 21));
        txt_id->setFont(font);
        txt_id->setReadOnly(true);
        txt_nombre = new QLineEdit(NuevaOrden);
        txt_nombre->setObjectName("txt_nombre");
        txt_nombre->setGeometry(QRect(182, 110, 161, 21));
        txt_nombre->setFont(font);
        txt_estado = new QLabel(NuevaOrden);
        txt_estado->setObjectName("txt_estado");
        txt_estado->setGeometry(QRect(182, 170, 81, 16));
        txt_estado->setFont(font);
        txt_fecha = new QLabel(NuevaOrden);
        txt_fecha->setObjectName("txt_fecha");
        txt_fecha->setGeometry(QRect(182, 200, 81, 16));
        txt_fecha->setFont(font);
        comboBox = new QComboBox(NuevaOrden);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(182, 140, 68, 22));
        comboBox->setFont(font);
        label_14 = new QLabel(NuevaOrden);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(130, 140, 41, 16));
        label_14->setFont(font);

        retranslateUi(NuevaOrden);

        QMetaObject::connectSlotsByName(NuevaOrden);
    } // setupUi

    void retranslateUi(QDialog *NuevaOrden)
    {
        NuevaOrden->setWindowTitle(QCoreApplication::translate("NuevaOrden", "Nueva Orden", nullptr));
        label_11->setText(QCoreApplication::translate("NuevaOrden", "Numero de Orden:", nullptr));
        label_12->setText(QCoreApplication::translate("NuevaOrden", "Nombre de Cliente:", nullptr));
        label_13->setText(QCoreApplication::translate("NuevaOrden", "Estado:", nullptr));
        label_15->setText(QCoreApplication::translate("NuevaOrden", "Fecha:", nullptr));
        butt_ok->setText(QString());
        butt_cancel->setText(QString());
        txt_estado->setText(QCoreApplication::translate("NuevaOrden", "pendiente", nullptr));
        txt_fecha->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("NuevaOrden", "Llevar", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("NuevaOrden", "Mesa", nullptr));

        label_14->setText(QCoreApplication::translate("NuevaOrden", "Lugar:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NuevaOrden: public Ui_NuevaOrden {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVAORDEN_H

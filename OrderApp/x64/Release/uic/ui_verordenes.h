/********************************************************************************
** Form generated from reading UI file 'verordenes.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERORDENES_H
#define UI_VERORDENES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerOrdenes
{
public:
    QGroupBox *groupBox;
    QFrame *frame;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *VerOrdenes)
    {
        if (VerOrdenes->objectName().isEmpty())
            VerOrdenes->setObjectName("VerOrdenes");
        VerOrdenes->resize(800, 500);
        groupBox = new QGroupBox(VerOrdenes);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 10, 791, 371));
        frame = new QFrame(groupBox);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 20, 771, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 771, 341));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 769, 339));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(140, 10, 491, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(VerOrdenes);

        QMetaObject::connectSlotsByName(VerOrdenes);
    } // setupUi

    void retranslateUi(QDialog *VerOrdenes)
    {
        VerOrdenes->setWindowTitle(QCoreApplication::translate("VerOrdenes", "Ordenes", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VerOrdenes", "Orden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VerOrdenes: public Ui_VerOrdenes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERORDENES_H

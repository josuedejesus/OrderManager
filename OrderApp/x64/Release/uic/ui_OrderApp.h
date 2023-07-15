/********************************************************************************
** Form generated from reading UI file 'OrderApp.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERAPP_H
#define UI_ORDERAPP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderAppClass
{
public:
    QAction *actionAdd;
    QAction *actionModify;
    QAction *actionDelete;
    QAction *actionOrdenes;
    QAction *actionCrear_Orden;
    QAction *actionEditar_Orden;
    QWidget *centralWidget;
    QPushButton *butt_new;
    QPushButton *butt_mod;
    QPushButton *butt_estadistics;
    QMenuBar *menuBar;
    QMenu *menuOpciones;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OrderAppClass)
    {
        if (OrderAppClass->objectName().isEmpty())
            OrderAppClass->setObjectName("OrderAppClass");
        OrderAppClass->resize(364, 350);
        actionAdd = new QAction(OrderAppClass);
        actionAdd->setObjectName("actionAdd");
        actionModify = new QAction(OrderAppClass);
        actionModify->setObjectName("actionModify");
        actionDelete = new QAction(OrderAppClass);
        actionDelete->setObjectName("actionDelete");
        actionOrdenes = new QAction(OrderAppClass);
        actionOrdenes->setObjectName("actionOrdenes");
        actionCrear_Orden = new QAction(OrderAppClass);
        actionCrear_Orden->setObjectName("actionCrear_Orden");
        actionEditar_Orden = new QAction(OrderAppClass);
        actionEditar_Orden->setObjectName("actionEditar_Orden");
        centralWidget = new QWidget(OrderAppClass);
        centralWidget->setObjectName("centralWidget");
        butt_new = new QPushButton(centralWidget);
        butt_new->setObjectName("butt_new");
        butt_new->setGeometry(QRect(110, 70, 131, 51));
        QFont font;
        font.setPointSize(12);
        butt_new->setFont(font);
        butt_new->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        butt_mod = new QPushButton(centralWidget);
        butt_mod->setObjectName("butt_mod");
        butt_mod->setGeometry(QRect(110, 130, 131, 51));
        butt_mod->setFont(font);
        butt_mod->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        butt_estadistics = new QPushButton(centralWidget);
        butt_estadistics->setObjectName("butt_estadistics");
        butt_estadistics->setGeometry(QRect(110, 190, 131, 51));
        butt_estadistics->setFont(font);
        butt_estadistics->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        OrderAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OrderAppClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 364, 22));
        menuOpciones = new QMenu(menuBar);
        menuOpciones->setObjectName("menuOpciones");
        OrderAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OrderAppClass);
        mainToolBar->setObjectName("mainToolBar");
        OrderAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OrderAppClass);
        statusBar->setObjectName("statusBar");
        OrderAppClass->setStatusBar(statusBar);

        menuBar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionAdd);
        menuOpciones->addAction(actionOrdenes);

        retranslateUi(OrderAppClass);

        QMetaObject::connectSlotsByName(OrderAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *OrderAppClass)
    {
        OrderAppClass->setWindowTitle(QCoreApplication::translate("OrderAppClass", "Menu Principal", nullptr));
        actionAdd->setText(QCoreApplication::translate("OrderAppClass", "Productos", nullptr));
        actionModify->setText(QCoreApplication::translate("OrderAppClass", "Modificar Producto", nullptr));
        actionDelete->setText(QCoreApplication::translate("OrderAppClass", "Eliminar Producto", nullptr));
        actionOrdenes->setText(QCoreApplication::translate("OrderAppClass", "Ordenes", nullptr));
        actionCrear_Orden->setText(QCoreApplication::translate("OrderAppClass", "Crear Orden", nullptr));
        actionEditar_Orden->setText(QCoreApplication::translate("OrderAppClass", "Modificar Orden", nullptr));
        butt_new->setText(QCoreApplication::translate("OrderAppClass", "Nueva Orden", nullptr));
        butt_mod->setText(QCoreApplication::translate("OrderAppClass", "Ver Orden", nullptr));
        butt_estadistics->setText(QCoreApplication::translate("OrderAppClass", "Estadistica", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("OrderAppClass", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrderAppClass: public Ui_OrderAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERAPP_H

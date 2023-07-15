#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OrderApp.h"

class OrderApp : public QMainWindow
{
    Q_OBJECT

public:
    OrderApp(QWidget *parent = nullptr);
    ~OrderApp();

private slots:
    void on_actionAdd_triggered();
    void on_actionOrdenes_triggered();
    void on_butt_new_clicked();
    void on_butt_mod_clicked();
    void on_butt_estadistics_clicked();

private:
    Ui::OrderAppClass ui;
};

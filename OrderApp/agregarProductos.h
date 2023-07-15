#ifndef AGREGARPRODUCTOS_H
#define AGREGARPRODUCTOS_H

#include <QDialog>

namespace Ui {
class agregarProductos;
}

class agregarProductos : public QDialog
{
    Q_OBJECT

public:
    explicit agregarProductos(QWidget *parent = nullptr);
    ~agregarProductos();
    void getProducts();

private slots:
    void on_butt_agregar_clicked();
    void on_actionAdd_triggered();
    void on_butt_view_order_clicked();
    void on_butt_cancel_clicked();

private:
    Ui::agregarProductos *ui;
};

#endif // AGREGARPRODUCTOS_H

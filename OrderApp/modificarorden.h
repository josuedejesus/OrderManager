#ifndef MODIFICARORDEN_H
#define MODIFICARORDEN_H

#include <QDialog>

namespace Ui {
class ModificarOrden;
}

class ModificarOrden : public QDialog
{
    Q_OBJECT

public:
    explicit ModificarOrden(QWidget *parent = nullptr);
    ~ModificarOrden();
    void refreshOrders();

private slots:
    void on_butt_seleccionar_clicked();
    void on_butt_mod_prods_clicked();
    void on_butt_eliminar_clicked();
    void on_butt_cancelar_clicked();
    void on_butt_pagar_clicked();
    void on_butt_end_clicked();
    void updateFile();

private:
    Ui::ModificarOrden *ui;
};

#endif // MODIFICARORDEN_H

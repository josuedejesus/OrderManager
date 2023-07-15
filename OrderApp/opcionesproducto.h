#ifndef OPCIONESPRODUCTO_H
#define OPCIONESPRODUCTO_H

#include <QDialog>

namespace Ui {
class opcionesProducto;
}

class opcionesProducto : public QDialog
{
    Q_OBJECT

public:
    explicit opcionesProducto(QWidget *parent = nullptr);
    ~opcionesProducto();
private slots:
    void on_butt_ok_clicked();
    void on_butt_cancel_clicked();
    void on_butt_actions_clicked();
    void enableOptions();
    
private:
    Ui::opcionesProducto *ui;
};

#endif // OPCIONESPRODUCTO_H

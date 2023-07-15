#ifndef NUEVAORDEN_H
#define NUEVAORDEN_H

#include <QDialog>

namespace Ui {
class NuevaOrden;
}

class NuevaOrden : public QDialog
{
    Q_OBJECT

public:
    explicit NuevaOrden(QWidget *parent = nullptr);
    ~NuevaOrden();

private slots:
    void on_butt_ok_clicked();
    void on_butt_cancel_clicked();
private:
    Ui::NuevaOrden *ui;
};

#endif // NUEVAORDEN_H

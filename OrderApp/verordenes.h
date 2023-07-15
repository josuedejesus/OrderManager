#ifndef VERORDENES_H
#define VERORDENES_H

#include <QDialog>

namespace Ui {
class VerOrdenes;
}

class VerOrdenes : public QDialog
{
    Q_OBJECT

public:
    explicit VerOrdenes(QWidget *parent = nullptr);
    ~VerOrdenes();
    void refreshOrders();

private:
    Ui::VerOrdenes *ui;
};

#endif // VERORDENES_H

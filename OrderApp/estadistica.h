#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <QDialog>

namespace Ui {
class Estadistica;
}

class Estadistica : public QDialog
{
    Q_OBJECT

public:
    explicit Estadistica(QWidget *parent = nullptr);
    ~Estadistica();

private:
    Ui::Estadistica *ui;
};

#endif // ESTADISTICA_H

#include "verordenes.h"
#include "ui_verordenes.h"
#include "Orden.h"
#include "global.h"
#include <QLabel>
#include <QListWidget>
using std::to_string;

VerOrdenes::VerOrdenes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VerOrdenes)
{
    ui->setupUi(this);
    refreshOrders();
}

VerOrdenes::~VerOrdenes()
{
    delete ui;
}

void VerOrdenes::refreshOrders() {
    double total = 0;
    int row = 0;
    int cantidad = 1;    
    string styling = "QLabel { background-color : white; color : black; border-radius: 5px; font-size : 15px;}";
    for (Orden* o : ordenes) {
        string orden_encab;
        string productos = "";
        QLabel* orden = new QLabel();
        orden->setWordWrap(true);
        orden_encab = "  Nombre: " + o->getNombre() + "\n  Hora: " + o->getHora() + "\n";
        for (Producto* p : o->getProductos()) {
            productos = productos + "      " + to_string(p->getCantidad()) + " " + p->getName() + " " + p->getComplemento2() + "\n" + "          - " + p->getComplemento1() + "\n";
            if (p->getComentario() != "") {
                productos = productos + "          - " + p->getComentario() + "\n";
            }
        }
        orden->setText(QString::fromStdString(orden_encab + productos));
        orden->setStyleSheet(QString::fromStdString(styling));
        ui->verticalLayout->insertWidget(0, orden);
        ui->scrollAreaWidgetContents->setLayout(ui->verticalLayout);
    }
    
}

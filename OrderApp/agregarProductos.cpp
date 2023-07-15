#include "agregarProductos.h"
#include "ui_agregarProductos.h"
#include "OrdenProductos.h"
#include "modificarorden.h"
#include "opcionesproducto.h"
#include "Orden.h"
#include "global.h"
#include <QMessageBox>
#include <fstream>
#include <sstream>
#include "verordenes.h"
#include "nuevaorden.h"

vector<Orden*> ordenes;
vector<Producto*> productos_orden;
Producto* productoSeleccionado = new Producto();
int id_prod;
string cliente;
bool resClicked = false, polloClicked = false;

agregarProductos::agregarProductos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregarProductos)
{
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    ui->setupUi(this);
    getProducts();
    ui->butt_agregar->hide();
    ui->butt_view_order->setIcon(QIcon("shopping-cart.png"));
    ui->butt_cancel->setIcon(QIcon("exit.png"));
    ui->txt_orden->setText(QString::number(orden_temp->getId()));
    ui->txt_cliente->setText(QString::fromStdString(orden_temp->getNombre()));
    if (orden_temp->getEstado() == 0) {
        ui->txt_estado->setText("Pendiente");
    }
    else if (orden_temp->getEstado() == 1) {
        ui->txt_estado->setText("Pagado");
    }
    else if (orden_temp->getEstado() == 2) {
        ui->txt_estado->setText("Entregado");
    }
    ui->txt_fecha->setText(QString::fromStdString(orden_temp->getFecha()));
}

agregarProductos::~agregarProductos()
{
    delete ui;
}

void agregarProductos::getProducts() {
    int widgetIndex = ui->tabWidget->currentIndex();
    for (Producto* p : productos) {
        if (p->getCategoria() == 0) {
            ui->list_res->addItem(QString::fromStdString(p->getName()));
        }
        else if (p->getCategoria() == 1) {
            ui->list_pollo->addItem(QString::fromStdString(p->getName()));
        }
        else if (p->getCategoria() == 2) {
            ui->list_cerdo->addItem(QString::fromStdString(p->getName()));
        }
        else if (p->getCategoria() == 3) {
            ui->list_camarones->addItem(QString::fromStdString(p->getName()));
        }
        else if (p->getCategoria() == 4) {
            ui->list_pescado->addItem(QString::fromStdString(p->getName()));
        }
        else if (p->getCategoria() == 5) {
            ui->list_mixtos->addItem(QString::fromStdString(p->getName()));
        }
        else if (p->getCategoria() == 6) {
            ui->list_tipicos->addItem(QString::fromStdString(p->getName()));
        }
        else if (p->getCategoria() == 7) {
            ui->list_extras->addItem(QString::fromStdString(p->getName()));
        }
        else if (p->getCategoria() == 8) {
            ui->list_bebidas->addItem(QString::fromStdString(p->getName()));
        }
    }

    ui->txt_orden->setText(QString::number(orden_temp->getId()));
    ui->txt_cliente->setText(QString::fromStdString(orden_temp->getNombre()));
    ui->txt_estado->setText(QString::number(orden_temp->getEstado()));
    ui->txt_fecha->setText(QString::fromStdString(orden_temp->getFecha()));
}

void agregarProductos::on_butt_agregar_clicked() {
    string producto;
    string nombre;
    string categoria;
    double precio;
    int indexCategoria = ui->tabWidget->currentIndex();
    int indexProducto = -1;
    switch (indexCategoria) {
    case 0:
        producto = ui->list_res->currentItem()->text().toStdString();
        ui->list_res->selectionModel()->clear();
        break;
    case 1:
        producto = ui->list_pollo->currentItem()->text().toStdString();
        ui->list_pollo->selectionModel()->clear();
        break;
    case 2:
        producto = ui->list_cerdo->currentItem()->text().toStdString();
        ui->list_cerdo->selectionModel()->clear();
        break;
    case 3:
        producto = ui->list_camarones->currentItem()->text().toStdString();
        ui->list_camarones->selectionModel()->clear();
        break;
    case 4:
        producto = ui->list_pescado->currentItem()->text().toStdString();
        ui->list_pescado->selectionModel()->clear();
        break;
    case 5:
        producto = ui->list_mixtos->currentItem()->text().toStdString();
        ui->list_mixtos->selectionModel()->clear();
        break;
    case 6:
        producto = ui->list_tipicos->currentItem()->text().toStdString();
        ui->list_tipicos->selectionModel()->clear();
        break;
    case 7:
        producto = ui->list_extras->currentItem()->text().toStdString();
        ui->list_extras->selectionModel()->clear();
        break;
    case 8:
        producto = ui->list_bebidas->currentItem()->text().toStdString();
        ui->list_bebidas->selectionModel()->clear();
        break;
    }

    for (Producto* p : productos) {
        if (p->getName() == producto) {
            id_prod = p->getIdProducto();
            productoSeleccionado = p;
        }
    }
    opcionesProducto opcionesUI;
    opcionesUI.setModal(true);
    opcionesUI.exec();
}

void agregarProductos::on_butt_cancel_clicked() {
    orden_temp = new Orden();
    productoSeleccionado = new Producto();
    productos_temp.clear();
    this->reject();
    ModificarOrden modificarOrden;
    modificarOrden.setModal(true);
    modificarOrden.exec();
}

void agregarProductos::on_actionAdd_triggered() {

}

void agregarProductos::on_butt_view_order_clicked() {
    this->accept();
    OrdenProductos ordenProductos;
    ordenProductos.setModal(true);
    ordenProductos.exec();
}

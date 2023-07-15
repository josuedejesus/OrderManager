#include "modificarorden.h"
#include "ui_modificarorden.h"
#include "global.h"
#include "agregarProductos.h"
#include <QMessageBox>
#include <qdatetime.h>
#include <fstream>
#include <string>

using std::ofstream;
using std::string;

ModificarOrden::ModificarOrden(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarOrden)
{
    ui->setupUi(this);
    refreshOrders();
    ui->butt_mod_prods->hide();
    ui->butt_seleccionar->setIcon(QIcon("pencil.png"));
    ui->butt_eliminar->setIcon(QIcon("minus.png"));
    ui->butt_pagar->setIcon(QIcon("pay.png"));
    ui->butt_end->setIcon(QIcon("delivered.png"));
    ui->butt_cancelar->setIcon(QIcon("exit.png"));
}

ModificarOrden::~ModificarOrden()
{
    delete ui;    
}

void ModificarOrden::refreshOrders() {
    vector<Orden*> ordenesSorted;
    ordenesSorted = ordenes;
    std::sort(ordenesSorted.begin(), ordenesSorted.end(), [](Orden* a, Orden* b) {return a->getNombre() < b->getNombre(); });
    string estado;
    ui->list_ordenes->clear();
    ui->list_productos->clear();
    for (Orden* o : ordenesSorted) {
        if (o->getEstado() == 0) {
            estado = "Pendiente";
        }
        else if (o->getEstado() == 1) {
            estado = "Pagado";
        }
        else if (o->getEstado() == 2) {
            estado = "Entregado";
        }
        if (o->getEstado() != 2) {
            ui->list_ordenes->addItem(QString::number(o->getId()) + " " + QString::fromStdString(o->getNombre()) + " - " + QString::fromStdString(estado));
        }
        
    }
    ui->label_orden->setText("");
    ui->label_cliente->setText("");
    ui->label_estado->setText("");
    ui->label_fecha->setText("");
    ui->label_hora->setText("");
    ui->label_total->setText("");
}

void ModificarOrden::on_butt_seleccionar_clicked() {
    for (Orden* o : ordenes) {
        if (o->getId() == id_orden) {
            orden_temp = o;
            break;
        }
    }
    this->accept();
    productos_temp = orden_temp->getProductos();
    agregarProductos agregarProductos;
    agregarProductos.setModal(true);
    agregarProductos.exec();
}

void ModificarOrden::on_butt_eliminar_clicked() {
    int index = ui->list_ordenes->currentRow();
    int id = 1;
    QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Eliminar", "Esta seguro que desea eliminar la orden?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ordenes.erase(std::remove_if(ordenes.begin(), ordenes.end(), [&](Orden* ord) {return ord->getId() == id_orden; }), ordenes.end());
	}
    string fileNameOrders = QDate::currentDate().toString("dd-MM-yy").toStdString() + "O" + ".csv";
    string fileNameProducts = QDate::currentDate().toString("dd-MM-yy").toStdString() + "P" ".csv";
    ofstream outputFileOrd(fileNameOrders);
    ofstream outputFileProd(fileNameProducts);
    for (Orden* o : ordenes) {
        o->setId(id);
        outputFileOrd << o->getId() << ';' << o->getNombre() << ';' << o->getEstado() << ';' << o->getHora() << ';' << o->getFecha() << ';' << o->getTotal() << "\n";
        for (Producto* p : o->getProductos()) {
            p->setIdOrden(id);
            outputFileProd << p->getIdProducto() << ';' << p->getIdOrden() << ';' << p->getCantidad() << ';' << p->getName() << ';' << p->getCategoria() << ';' << p->getCategoriaOpciones() << ';' << p->getCategoriaCocina() << ';' << p->getComplemento1() << ';' << p->getComplemento2() << ';' << p->getComentario() << ';' << p->getPrice() << '\n';
        }
        id++;
    }
    refreshOrders();
}

void ModificarOrden::on_butt_mod_prods_clicked() {
    vector<Producto*> productosLista;
    id_orden = ui->list_ordenes->currentItem()->text().split(" ")[0].toInt();
    Orden* orderInfo = new Orden();
    for (Orden* o : ordenes) {
        if (o->getId() == id_orden) {
            orderInfo = o;
            productosLista = o->getProductos();
            break;
        }
    }
    ui->list_productos->clear();
    for (Producto* p : productosLista) {
        ui->list_productos->addItem(QString::number(p->getCantidad()) + " " + QString::fromStdString(p->getName()) + " " + QString::number(p->getPrice()));
    }
    ui->label_orden->setText(QString::number(orderInfo->getId()));
    ui->label_cliente->setText(QString::fromStdString(orderInfo->getNombre()));
    if (orderInfo->getEstado() == 0) {
        ui->label_estado->setText("Pendiente");
    }
    else if (orderInfo->getEstado() == 1) {
        ui->label_estado->setText("Pagado");
    }
    else if (orderInfo->getEstado() == 2) {
        ui->label_estado->setText("Entregado");
    }
    ui->label_hora->setText(QString::fromStdString(orderInfo->getHora()));
    ui->label_fecha->setText(QString::fromStdString(orderInfo->getFecha()));
    ui->label_total->setText(QString::number(orderInfo->getTotal()) + ".00");
}

void ModificarOrden::on_butt_pagar_clicked() {
    for (Orden* o : ordenes) {
        if (o->getId() == id_orden) {
            o->setEstado(1);
            break;
        }
    }
    refreshOrders();
    updateFile();
}

void ModificarOrden::on_butt_end_clicked() {
    for (Orden* o : ordenes) {
        if (o->getId() == id_orden) {
            o->setEstado(2);
            break;
        }
    }
    refreshOrders();
    updateFile();
}

void ModificarOrden::updateFile() {
    string fileNameOrders = QDate::currentDate().toString("dd-MM-yy").toStdString() + "O" + ".csv";
    ofstream outputFile(fileNameOrders);
    for (Orden* o : ordenes) {
        outputFile << o->getId() << ';' << o->getNombre() << ';' << o->getEstado() << ';' << o->getHora() << ';' << o->getFecha() << ';' << o->getTotal() << "\n";
    }
}

void ModificarOrden::on_butt_cancelar_clicked() {
    this->reject();
}

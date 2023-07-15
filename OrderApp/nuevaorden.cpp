#include "nuevaorden.h"
#include "ui_nuevaorden.h"
#include "global.h"
#include <QMessageBox>
#include <qdatetime.h>
#include "agregarProductos.h"

Orden* orden_temp = new Orden();
int id_orden;

NuevaOrden::NuevaOrden(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NuevaOrden)
{
    ui->setupUi(this);
    ui->butt_ok->setIcon(QIcon("check.png"));
    ui->butt_cancel->setIcon(QIcon("cancel.png"));
    QDate fecha = QDate::currentDate();
    ui->txt_fecha->setText(fecha.toString("d/M/yy"));
    if (ordenes.size() == 0) {
        id_orden = 1;
    }
    else {
        id_orden = ordenes[ordenes.size() - 1]->getId() + 1;
    }
    ui->txt_id->setText(QString::number(id_orden));
}

NuevaOrden::~NuevaOrden()
{
    delete ui;
}

void NuevaOrden::on_butt_ok_clicked() {
    if (ui->txt_nombre->text() == "") {
        QMessageBox::warning(this, "Error", "No puede haber campos vacios.");
		return;
    }
    else {
        id_orden = ui->txt_id->text().toInt();
        cliente = ui->txt_nombre->text().toStdString();
        int estado = ui->txt_estado->text().toInt();
        string fecha = ui->txt_fecha->text().toStdString();
        double total = 0;
        if (id_orden == NULL || cliente == "" || ui->txt_estado->text() == "") {
            QMessageBox::warning(this, "Error", "No puede haber campos vacios.");
            return;
        }
        else {
            orden_temp->setId(id_orden);
            orden_temp->setNombre(cliente);
            orden_temp->setEstado(estado);
            orden_temp->setFecha(fecha);
            orden_temp->setTotal(total);
            this->accept();
            QMessageBox::information(this, "Informacion", "Se creo nueva orden.");
        }
        agregarProductos agregarProductos;
        agregarProductos.setModal(true);
        agregarProductos.exec();
    }
}

void NuevaOrden::on_butt_cancel_clicked() {
    this->close();
}

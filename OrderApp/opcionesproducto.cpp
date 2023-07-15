#include "opcionesproducto.h"
#include "ui_opcionesproducto.h"
#include "global.h"
#include <fstream>
#include <sstream>
#include <QMessageBox>
#include "Producto.h"

vector<Producto*> productos_temp;
double price = 0.00;
bool isModified = false;

void opcionesProducto::enableOptions() {
    ui->label_comp1->show();
    ui->label_comp2->show();
    ui->combo_comp1->show();
    ui->combo_comp2->show();

}

opcionesProducto::opcionesProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::opcionesProducto)
{
    ui->setupUi(this);
    ui->butt_ok->setIcon(QIcon("check.png"));
    ui->butt_cancel->setIcon(QIcon("cancel.png"));
    ui->butt_extra->setIcon(QIcon("plus.png"));
    ui->label_producto->setText(QString::fromStdString(productoSeleccionado->getName()));
    ui->label_valor->setText("L " + QString::number(productoSeleccionado->getPrice()) + ".00");
    ui->butt_actions->hide();
    ui->label_base->hide();
    ui->combo_base->hide();
    ui->label_comp1->hide();
    ui->combo_comp1->hide();
    ui->label_comp2->hide();
    ui->combo_comp2->hide();
    ui->combo_base->clear();
    ui->combo_comp1->clear();
    ui->combo_comp2->clear();

    int categoriaOpciones = productoSeleccionado->getCategoriaOpciones();
    switch (categoriaOpciones) {
    case 0: 
        enableOptions();
        ui->combo_comp1->addItem("Platano Verde");
        ui->combo_comp1->addItem("Guineo Verde");
        ui->combo_comp1->addItem("Papas Fritas");
        ui->combo_comp1->addItem("Tortillas");
        ui->combo_comp1->addItem("Platano Maduro");
        ui->combo_comp2->addItem("Frijoles Fritos");
        ui->combo_comp2->addItem("Rice and Beans");
        break;
    case 1: 
        enableOptions();
        ui->label_base->show();
        ui->label_base->setText("Salsa");
        ui->combo_base->show();
        ui->combo_base->addItem("Normal");
        ui->combo_base->addItem("BBQ");
        ui->combo_comp1->addItem("Normal");
        ui->combo_comp1->addItem("Platano Verde");
        ui->combo_comp1->addItem("Guineo Verde");
        ui->combo_comp1->addItem("Papas Fritas");
        ui->combo_comp1->addItem("Tortillas");
        ui->combo_comp1->addItem("Platano Maduro");
        ui->combo_comp2->addItem("Normal");
        ui->combo_comp2->addItem("Frijoles Fritos");
        ui->combo_comp2->addItem("Rice and Beans");
        break;
    case 2: 
        enableOptions();
        ui->label_base->show();
        ui->label_base->setText("Tipo de Carnes");
        ui->combo_base->show();
        ui->combo_base->addItem("Res - Pollo");
        ui->combo_base->addItem("Res - Chuleta");
        ui->combo_base->addItem("Res - Costilla");
        ui->combo_base->addItem("Res - Chorizo");
        ui->combo_comp1->addItem("Platano Verde");
        ui->combo_comp1->addItem("Guineo Verde");
        ui->combo_comp1->addItem("Papas Fritas");
        ui->combo_comp1->addItem("Tortillas");
        ui->combo_comp1->addItem("Platano Maduro");
        ui->combo_comp2->addItem("Frijoles Fritos");
        ui->combo_comp2->addItem("Rice and Beans");
        break;
    case 3: 
        enableOptions();
        ui->label_base->show();
        ui->label_base->setText("Tipo de Carnes");
        ui->combo_base->show();
        ui->combo_base->addItem("Res - Pollo - Chuleta");
        ui->combo_base->addItem("Res - Pollo - Costilla");
        ui->combo_base->addItem("Res - Pollo - Chorizo");
        ui->combo_comp1->addItem("Platano Verde");
        ui->combo_comp1->addItem("Guineo Verde");
        ui->combo_comp1->addItem("Papas Fritas");
        ui->combo_comp1->addItem("Tortillas");
        ui->combo_comp1->addItem("Platano Maduro");
        ui->combo_comp2->addItem("Frijoles Fritos");
        ui->combo_comp2->addItem("Rice and Beans");
        break;
    case 4: 
        enableOptions();
        ui->label_base->show();
        ui->label_base->setText("Tipo de Carnes");
        ui->combo_base->show();
        ui->combo_base->addItem("Res - Camaron Plancha");
        ui->combo_base->addItem("Res - Camaron Ajillo");
        ui->combo_base->addItem("Res - Camaron Empanizado");
        ui->combo_comp1->addItem("Platano Verde");
        ui->combo_comp1->addItem("Guineo Verde");
        ui->combo_comp1->addItem("Papas Fritas");
        ui->combo_comp1->addItem("Tortillas");
        ui->combo_comp1->addItem("Platano Maduro");
        ui->combo_comp2->addItem("Frijoles Fritos");
        ui->combo_comp2->addItem("Rice and Beans");
        break;
    case 5:
        ui->label_comment->show();
        break;
    case 6:
        enableOptions();
        ui->label_base->show();
        ui->label_base->setText("Tipo de huevos");
        ui->combo_base->show();
        ui->combo_base->addItem("Huevo Estrellado");
        ui->combo_base->addItem("Huevo Revuelto");
        ui->combo_base->addItem("Torta");
        ui->combo_base->addItem("Omelette");
        ui->combo_comp1->addItem("Normal");
        ui->combo_comp1->addItem("Platano Verde");
        ui->combo_comp1->addItem("Guineo Verde");
        ui->combo_comp1->addItem("Papas Fritas");
        ui->combo_comp1->addItem("Tortillas");
        ui->combo_comp1->addItem("Platano Maduro");
        ui->combo_comp2->addItem("Normal");
        ui->combo_comp2->addItem("Frijoles Fritos");
        ui->combo_comp2->addItem("Rice and Beans");
        break;
    case 7:
        ui->label_comp2->hide();
        ui->combo_comp1->hide();
        ui->combo_comp2->hide();
        break;
    case 8:
        ui->label_base->show();
        ui->label_base->setText("Tipo");
        ui->combo_base->show();
        ui->combo_base->addItem("Solo");
        ui->combo_base->addItem("Frijoles - Queso - Mantequilla");
        ui->combo_comp1->hide();
        ui->combo_comp2->hide();
        break;
    case 9:
        ui->label_base->show();
        ui->label_base->setText("Base");
        ui->combo_base->show();
        ui->combo_base->addItem("Agua");
        ui->combo_base->addItem("Leche");

        ui->combo_comp1->show();
        ui->label_comp1->show();
        ui->label_comp1->setText("Fruta Adicional");
        ui->combo_comp1->addItem("Normal");
        ui->combo_comp1->addItem("Avena");
        ui->combo_comp1->addItem("Banano");
        ui->combo_comp1->addItem("Cacahuate");
        ui->combo_comp1->addItem("Cereal");
        ui->combo_comp1->addItem("Granola");
        ui->combo_comp1->addItem("Limon");
        ui->combo_comp1->addItem("Mango");
        ui->combo_comp1->addItem("Melon");
        ui->combo_comp1->addItem("Narjanja Agria");
        ui->combo_comp1->addItem("Naranaja Dulce");
        ui->combo_comp1->addItem("Papaya");
        ui->combo_comp1->addItem("Pina");
        ui->combo_comp1->addItem("Sandia");
        ui->combo_comp1->addItem("Toronja");
        break;
    case 10:
        ui->combo_comp1->show();
        ui->label_comp1->show();
        ui->label_comp1->setText("Fruta Adicional");
        ui->combo_comp1->addItem("Normal");
        ui->combo_comp1->addItem("Avena");
        ui->combo_comp1->addItem("Banano");
        ui->combo_comp1->addItem("Cacahuate");
        ui->combo_comp1->addItem("Cereal");
        ui->combo_comp1->addItem("Granola");
        ui->combo_comp1->addItem("Mango");
        ui->combo_comp1->addItem("Melon");
        ui->combo_comp1->addItem("Papaya");
        ui->combo_comp1->addItem("Pina");
        ui->combo_comp1->addItem("Sandia");
        break;
    case 11:
        break;
    case 12:
        ui->label_base->show();
        ui->label_base->setText("Base");
        ui->combo_base->show();
        ui->combo_base->addItem("Agua");
        ui->combo_base->addItem("Soda");

        ui->combo_comp1->show();
        ui->label_comp1->show();
        ui->label_comp1->setText("Fruta Adicional");
        ui->combo_comp1->addItem("Normal");
        ui->combo_comp1->addItem("Mango");
        ui->combo_comp1->addItem("Melon");
        ui->combo_comp1->addItem("Papaya");
        ui->combo_comp1->addItem("Pina");
        ui->combo_comp1->addItem("Sandia");
        break;
    }
}

opcionesProducto::~opcionesProducto()
{
    delete ui;
}

void opcionesProducto::on_butt_actions_clicked()
{
    int quantity = ui->spin_cantidad->value();
    price = productoSeleccionado->getPrice();
    int categoria = productoSeleccionado->getCategoria();
    int categoriaOpciones = productoSeleccionado->getCategoriaOpciones();
    int index = ui->combo_base->currentIndex();
    int indexExtra = ui->combo_comp1->currentIndex();
    if (categoria == 8) {
        if (index == 1) {
            price = price + 10;
        }
        if (indexExtra == 0) {
            price = price;
        }
        else {
            price = price + 20;
        }
        if (categoriaOpciones == 11) {
            price = 50;
        }
        else if (categoriaOpciones == 13) {
            price = 25;
        }
    }
    if (categoriaOpciones == 8) {
        if (index == 1) {
            price = price + 20;
        }
    }
    price = price * quantity;
    ui->label_valor->setText("L " + (QString::number(price)) + ".00");
}

void opcionesProducto::on_butt_ok_clicked() {
    string nombre, categoria, base, fruta;
    int id, quantity = ui->spin_cantidad->value(), indexFruta;
    string complemento1 = "", complemento2 = "", comentario = "", tipoPrincipal = "";
    
    for (Producto* p : productos) {
        if (p->getIdProducto() == id_prod) {
            productoSeleccionado = p;
        }
    } 
    int categoriaOpciones = productoSeleccionado->getCategoriaOpciones();
    switch (categoriaOpciones) {
    case 0: {
        int currentIndex = ui->combo_comp2->currentIndex();
        if (currentIndex == 0)
            complemento2 = "FF";
        else if (currentIndex == 1)
            complemento2 = "RB";
        complemento1 = ui->combo_comp1->currentText().toStdString();
        break;
    }
    case 1: {
        int currentIndex1 = ui->combo_comp1->currentIndex();
        int currentIndex2 = ui->combo_comp2->currentIndex();
        int currentIndexTipo = ui->combo_base->currentIndex();

        if (currentIndexTipo == 0)
            tipoPrincipal = "";
        else if (currentIndexTipo == 1)
            tipoPrincipal = "BBQ";
        
        if (currentIndex2 == 0)
            complemento2 = "";
        else if (currentIndex2 == 1)
            complemento2 = "FF";
        else if (currentIndex1 == 2)
            complemento2 = "RB";


        if (currentIndex1 == 0)
            complemento1 = "";
        else if (currentIndex1 == 1)
            complemento1 = "Platano Verde";
        else if (currentIndex1 == 2)
            complemento1 = "Guineo Verde";
        else if (currentIndex1 == 1)
            complemento1 = "Platano Maduro";
        break;
    }
    case 2: {
        int currentIndex = ui->combo_comp2->currentIndex();
        if (currentIndex == 0)
            complemento2 = "FF";
        else if (currentIndex == 1)
            complemento2 = "RB";
        complemento1 = ui->combo_comp1->currentText().toStdString();
        tipoPrincipal = " (" + ui->combo_base->currentText().toStdString() + ")";
        break;
    }
    case 3: {
        int currentIndex = ui->combo_comp2->currentIndex();
        if (currentIndex == 0)
            complemento2 = "FF";
        else if (currentIndex == 1)
            complemento2 = "RB";
        complemento1 = ui->combo_comp1->currentText().toStdString();
        tipoPrincipal = " (" + ui->combo_base->currentText().toStdString() + ")";
        break;
    }
    case 4: {
        int currentIndex = ui->combo_comp2->currentIndex();
        if (currentIndex == 0)
            complemento2 = "FF";
        else if (currentIndex == 1)
            complemento2 = "RB";
        complemento1 = ui->combo_comp1->currentText().toStdString();
        tipoPrincipal = " (" + ui->combo_base->currentText().toStdString() + ")";
        break;
    }
    case 5:
        complemento1 = "";
        complemento2 = "";
        break;
    case 6: {
        int currentIndex1 = ui->combo_comp1->currentIndex();
        int currentIndex2 = ui->combo_comp2->currentIndex();
        if (currentIndex2 == 0)
            complemento2 = "";
        else if (currentIndex2 == 1)
            complemento2 = "RB";
        if (currentIndex1 == 0)
            complemento2 = "";
        else if (currentIndex1 == 1)
            complemento1 = "Platano Verde";
        else if (currentIndex1 == 2)
            complemento1 = "Guineo Verde";
        tipoPrincipal = " (" + ui->combo_base->currentText().toStdString() + ")";
        break;
    }
        
    case 7:
        tipoPrincipal = "";
        complemento1 = "";
        complemento2 = "";
        break;
    case 8: {
        int currentIndex = ui->combo_base->currentIndex();
        tipoPrincipal = ui->combo_base->currentText().toStdString();
        if (currentIndex == 0) {
            price = 20;
        }
        else if (currentIndex == 1)
            price = 40;
        break;
    }
    case 9:
        indexFruta = ui->combo_comp1->currentIndex();
        base = ui->combo_base->currentText().toStdString();
        if (indexFruta == 0) {
            fruta = "";
        }
        else {
            fruta = ui->combo_comp1->currentText().toStdString();
        }
        tipoPrincipal = fruta + " " + base;
        break;
    case 10:
        indexFruta = ui->combo_comp1->currentIndex();
        base = ui->combo_base->currentText().toStdString();
        if (indexFruta == 0) {
            fruta = "";
        }
        else {
            fruta = ui->combo_comp1->currentText().toStdString();
        }
        tipoPrincipal = fruta + " " + base;
        break;
    case 11:
        break;
    case 12:
        indexFruta = ui->combo_comp1->currentIndex();
        base = ui->combo_base->currentText().toStdString();
        if (indexFruta == 0) {
            fruta = "";
        }
        else {
            fruta = ui->combo_comp1->currentText().toStdString();
        }
        tipoPrincipal = fruta + " " + base;
        break;
    }
    if (ui->txt_comment->toPlainText() != "") {
		comentario = ui->txt_comment->toPlainText().toStdString();
		productoSeleccionado->setComentario(comentario);
	}
    Producto* newProduct = new Producto(productoSeleccionado->getIdProducto(), productoSeleccionado->getName(), productoSeleccionado->getCategoria(), productoSeleccionado->getCategoriaOpciones(), productoSeleccionado->getCategoriaCocina(), productoSeleccionado->getPrice());
    newProduct->setIdOrden(id_orden);
    newProduct->setCantidad(quantity);
    newProduct->setName(productoSeleccionado->getName() + " " + tipoPrincipal);
    newProduct->setComplemento1(complemento1);
    newProduct->setComplemento2(complemento2);
    newProduct->setComentario(comentario);
    newProduct->setPrice(round(price));
    //productos_temp.push_back(newProduct);
    isModified = true;
    orden_temp->pushProduct(newProduct);
    this->accept();
}

void opcionesProducto::on_butt_cancel_clicked() {
    isModified = false;
    productos_temp.clear();
    this->close();
}

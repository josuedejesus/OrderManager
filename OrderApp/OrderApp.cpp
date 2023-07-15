#include "OrderApp.h"
#include "OrdenProductos.h"
#include "opcionesproducto.h"
#include "Orden.h"
#include "global.h"
#include <QMessageBox>
#include <fstream>
#include <sstream>
#include "verordenes.h"
#include "nuevaorden.h"
#include "agregarProductos.h"
#include "modificarorden.h"
#include <QDate>;
#include "estadistica.h"
using std::string;
using std::ifstream;
using std::stringstream;
using std::getline;

int existente = 1;
vector<Producto*> productos;
//global globalVariables;
//vector<Producto*> productList = globalVariables.getProducts();

OrderApp::OrderApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //Obtiene los productos para crear una lista
    ifstream inProductos;
    string linea;
    inProductos.open("productos.csv");
    while (getline(inProductos, linea)) {
        stringstream ss(linea);
        string id,nombre, categoria, categoriaOpciones, categoriaCocina, precio;
        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, categoria, ';');
        getline(ss, categoriaOpciones, ';');
        getline(ss, categoriaCocina, ';');
        getline(ss, precio, ';');
        productos.push_back(new Producto(stoi(id), nombre, stoi(categoria), stoi(categoriaOpciones), stoi(categoriaCocina), stod(precio)));
    }
    //Si ya hay un archivo creado, obtiene los datos de las ordenes y sus productos, si no, crea un archivo nuevo
    string fileNameOrders = QDate::currentDate().toString("dd-MM-yy").toStdString() + "O" + ".csv";
    ifstream inputOrders(fileNameOrders);
    string fileNameProducts = QDate::currentDate().toString("dd-MM-yy").toStdString() + "P" + ".csv";
    ifstream inputProducts(fileNameProducts);
    string id, line, nombre, estado, hora, fecha, total;
    Orden* orderTemp;
    Producto* productTemp;
    vector<Producto*> productsList;
    if (!inputOrders.fail()) {
        while (getline(inputOrders, line, '\n')) {
            stringstream ssLine(line);
            getline(ssLine, id, ';');
            getline(ssLine, nombre, ';');
            getline(ssLine, estado, ';');
            getline(ssLine, hora, ';');
            getline(ssLine, fecha, ';');
            getline(ssLine, total, '\n');
            orderTemp = new Orden(stoi(id), nombre, stoi(estado), hora, fecha, stod(total));  
            ordenes.push_back(orderTemp);
        }
        string idProd, idOrder, cantidad, description, category, categoryOptions, categoriaCocina, comp1, comp2, comment, price;
        while (getline(inputProducts, line, '\n')) {
            stringstream ssLine(line);
            getline(ssLine, idProd, ';');
            getline(ssLine, idOrder, ';');
            getline(ssLine, cantidad, ';');
            getline(ssLine, description, ';');
            getline(ssLine, category, ';');
            getline(ssLine, categoryOptions, ';');
            getline(ssLine, categoriaCocina, ';');
            getline(ssLine, comp1, ';');
            getline(ssLine, comp2, ';');
            getline(ssLine, comment, ';');
            getline(ssLine, price, '\n');
            productTemp = new Producto(stoi(idProd), description, stoi(category), stoi(categoryOptions), stoi(categoriaCocina), stod(price));
            productTemp->setIdOrden(stoi(idOrder));
            productTemp->setCantidad(stoi(cantidad));
            productTemp->setComplemento1(comp1);
            productTemp->setComplemento2(comp2);
            productTemp->setComentario(comment);
            ordenes[stoi(idOrder) - 1]->pushProduct(productTemp);
        }
    }
    else {
        return;
    }
    inputProducts.close();
    inputOrders.close();
}

OrderApp::~OrderApp()
{}

void OrderApp::on_butt_new_clicked() {
    existente = 1;
    NuevaOrden nuevaOrden;;
    nuevaOrden.setModal(true);
    nuevaOrden.exec();
}

void OrderApp::on_butt_mod_clicked() {
    existente = 2;
    ModificarOrden modificarOrden;
    modificarOrden.setModal(true);
    modificarOrden.exec();
}

void OrderApp::on_actionAdd_triggered() {

}

void OrderApp::on_actionOrdenes_triggered() {
    VerOrdenes verOrdenes;;
    verOrdenes.setModal(true);
    verOrdenes.exec();
}

void OrderApp::on_butt_estadistics_clicked() {
    Estadistica estadistica;
    estadistica.setModal(true);
    estadistica.exec();
}


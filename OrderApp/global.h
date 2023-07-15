#pragma once
#include <vector>
#include "Orden.h"
#include "Producto.h"

#include <fstream>
#include <sstream>
using std::string;
using std::ifstream;
using std::stringstream;
using std::getline;



extern vector<Orden*> ordenes;
extern vector<Producto*> productos;
extern vector<Producto*> productos_temp;
extern Orden* orden_temp;
extern Producto* productoSeleccionado;
extern int id_orden;
extern int id_prod;
extern string cliente;
extern int existente;
extern int isMod;
extern int indexToMod;
extern bool isModified;

/*class global {
	private:
		vector<Orden*> orderList;
        vector<Producto*> productList;
	public:
		global();
		~global();
        vector<Producto*> getProducts();
        vector<Orden*> getOrders();
};

global::global() {
    ifstream inProductos;
    string linea;
    inProductos.open("productos.csv");
    while (getline(inProductos, linea)) {
        stringstream ss(linea);
        string id, nombre, categoria, categoriaOpciones, categoriaCocina, precio;
        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, categoria, ';');
        getline(ss, categoriaOpciones, ';');
        getline(ss, categoriaCocina, ';');
        getline(ss, precio, ';');
        productList.push_back(new Producto(stoi(id), nombre, stoi(categoria), stoi(categoriaOpciones), stoi(categoriaCocina), stod(precio)));
    }
}

global::~global() {

}

vector<Producto*> global::getProducts() {
	return productList;
}

vector<Orden*> global::getOrders() {
    return orderList;
}*/


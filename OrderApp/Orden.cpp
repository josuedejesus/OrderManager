#include "Orden.h"

Orden::Orden() {

}

Orden::Orden(int id_orden, string nombre_cliente, int estado, string hora, string fecha, double total) {
	this->id_orden = id_orden;
	this->nombre_cliente = nombre_cliente;
	this->estado = estado;
	this->hora = hora;
	this->fecha = fecha;
	this->total = total;
}

Orden::~Orden() {
}

void Orden::setId(int id_orden) {
	this->id_orden = id_orden;
}

int Orden::getId() {
	return this->id_orden;
}

void Orden::setNombre(string nombre_cliente) {
	this->nombre_cliente = nombre_cliente;
}

string Orden::getNombre() {
	return this->nombre_cliente;
}

void Orden::setHora(string hora) {
	this->hora = hora;
}

string Orden::getHora() {
	return this->hora;
}

void Orden::setFecha(string fecha) {
	this->fecha = fecha;
}

string Orden::getFecha() {
	return this->fecha;
}

void Orden::setEstado(int estado) {
	this->estado = estado;
}

int Orden::getEstado() {
	return this->estado;
}

void Orden::setTotal(double total) {
	this->total = total;
}

double Orden::getTotal() {
	return this->total;
}

void Orden::setProductos(vector<Producto*> productos) {
	this->productos = productos;
}

vector<Producto*> Orden::getProductos() {
	return this->productos;
}

void Orden::pushProduct(Producto* product) {
	this->productos.push_back(product);
}

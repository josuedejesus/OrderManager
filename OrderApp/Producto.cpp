#include "Producto.h"

Producto::Producto() {
}

Producto::Producto(int idProducto, string name, int categoria, int categoriaOpciones, int categoriaCocina, double price) {
	this->idProducto = idProducto;
	this->name = name;
	this->categoria = categoria;
	this->categoriaOpciones = categoriaOpciones;
	this->categoriaCocina = categoriaCocina;
	this->price = price;
}

Producto::~Producto() {
}

void Producto::setIdOrden(int idOrden) {
	this->idOrden = idOrden;
}

int Producto::getIdOrden() {
	return this->idOrden;
}

void Producto::setIdProducto(int idProducto) {
	this->idProducto = idProducto;
}

int Producto::getIdProducto() {
	return this->idProducto;
}

void Producto::setCantidad(int cantidad) {
	this->cantidad = cantidad;
}

int Producto::getCantidad() {
	return this->cantidad;
}

void Producto::setName(string name) {
	this->name = name;
}

string Producto::getName() {
	return this->name;
}

void Producto::setCategoria(int categoria) {
	this->categoria = categoria;
}

int Producto::getCategoria() {
	return this->categoria;
}

void Producto::setCategoriaOpciones(int categoriaOpciones) {
	this->categoriaOpciones = categoriaOpciones;
}

int Producto::getCategoriaOpciones() {
	return this->categoriaOpciones;
}

void Producto::setCategoriaCocina(int categoriaCocina) {
	this->categoriaCocina = categoriaCocina;
}

int Producto::getCategoriaCocina() {
	return this->categoriaCocina;
}

void Producto::setComentario(string comentario) {
	this->comentario = comentario;
}

string Producto::getComentario() {
	return this->comentario;
}

void Producto::setComplemento1(string complemento1) {
	this->complemento1 = complemento1;
}

string Producto::getComplemento1() {
	return this->complemento1;
}

void Producto::setComplemento2(string complemento2) {
	this->complemento2 = complemento2;
}

string Producto::getComplemento2() {
	return this->complemento2;
}

void Producto::setPrice(double price) {
	this->price = price;
}

double Producto::getPrice() {
	return this->price;
}


#pragma once
#include <string>
#include <vector>
#include "Producto.h"
using std::string;
using std::vector;

class Orden
{
private:
	int id_orden;
	string nombre_cliente;
	string hora;
	string fecha;
	vector<Producto*> productos;
	int estado;
	double total;
public:
	Orden();
	Orden(int id, string nombre, int estado, std::string hora, std::string fecha, double total);
	~Orden();
	void setId(int id);
	int getId();
	void setNombre(string nomber);
	string getNombre();
	void setHora(string hora);
	std::string getHora();
	void setFecha(string fecha);
	std::string getFecha();
	void setProductos(vector<Producto*> productos);
	std::vector<Producto*> getProductos();
	void setEstado(int estado);
	int getEstado();
	void setTotal(double total);
	double getTotal();
	void pushProduct(Producto* product);
};


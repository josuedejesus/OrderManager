#pragma once
#include <string>
using std::string;

class Producto
{
private:
	int idProducto;
	int idOrden;
	int cantidad;
	string name;
	int categoria;
	int categoriaOpciones;
	int categoriaCocina;
	string complemento1;
	string complemento2;
	string comentario;
	double price;
public:
	Producto();
	Producto(int idProducto, string nombre, int categoria, int categoriaOPciones, int categoriaCocina,double price);
	~Producto();
	void setIdProducto(int idProducto);
	int getIdProducto();
	void setIdOrden(int idOrden);
	int getIdOrden();
	void setCantidad(int cantidad);
	int getCantidad();
	void setName(string nombre);
	string getName();
	void setCategoria(int categoria);
	int getCategoria();
	void setCategoriaOpciones(int categoriaOpciones);
	int getCategoriaOpciones();
	void setCategoriaCocina(int categoriaCocina);
	int getCategoriaCocina();
	void setComplemento1(string complemento1);
	string getComplemento1();
	void setComplemento2(string complemento2);
	string getComplemento2();
	void setComentario(string comentario);
	string getComentario();
	void setPrice(double precio);
	double getPrice();
};


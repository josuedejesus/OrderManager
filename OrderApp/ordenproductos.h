#ifndef ORDENPRODUCTOS_H
#define ORDENPRODUCTOS_H

#include <QDialog>
#include "Producto.h"
#include "Orden.h"
#include <vector>
using std::vector;

namespace Ui {
class OrdenProductos;
}

class OrdenProductos : public QDialog
{
    Q_OBJECT

public:
    explicit OrdenProductos(QWidget *parent = nullptr);
    ~OrdenProductos();
    void refreshOrders();
    void clearProducts(QLayout* layout);
    std::string mostrarDecimales(double valor);
    void Print(vector<Producto*> productsToPrint, int cocinas, int ordenPrincipal);
    vector<Producto*> getTypeList(int i, int ordenPrincipal, vector<Producto*> productosSorted);
    vector<Producto*> sortProducts(vector<Producto*> productList, int cantidadCocinas);
    int getCantidadCocinas(vector<Producto*> productList);
    int getOrdenPrincipal(vector<Producto*> productList);
    Orden* printSectionedOrder(vector<Producto*> productList);
    string addSpaces(const string& text, int width);
private slots:
    void on_butt_send_clicked();
    void on_butt_back_clicked();
    void on_butt_eliminar_clicked();    
    void on_butt_edit_clicked();

private:
    Ui::OrdenProductos *ui;
};

#endif // ORDENPRODUCTOS_H

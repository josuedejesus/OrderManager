#include "ordenproductos.h"
#include "ui_ordenproductos.h"
#include "Orden.h"
#include "global.h"
#include "qlayout.h"
#include "qdatetime.h"
#include "agregarProductos.h"
#include "opcionesproducto.h"
#include <QMessageBox>
#include <libusb.h>
#include <thread> 
#include <sstream>
#include <fstream>
#include <iomanip>

using std::string;
using std::to_string;
using std::ifstream;
using std::stringstream;

bool isDelete = false;
int ordersNumber = 1;
double total;
int isMod = 0;
int indexToMod = 0;
vector<Producto*> productsToPrint;

OrdenProductos::OrdenProductos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrdenProductos)
{
    ui->setupUi(this);

    refreshOrders();
    ui->butt_eliminar->setIcon(QIcon("minus.png"));
    ui->butt_edit->setIcon(QIcon("pencil.png"));
    ui->butt_send->setIcon(QIcon("check.png"));
    ui->butt_back->setIcon(QIcon("exit.png"));
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
}

OrdenProductos::~OrdenProductos()
{
    delete ui;
}

vector<Producto*> OrdenProductos::getTypeList(int i, int ordenPrincipal, vector<Producto*> productosSorted) {
    vector<Producto*> list;
    if (i == ordenPrincipal) {
        for (Producto* p : productosSorted) {
            list.push_back(p);
        }
    }
    else {
        for (Producto* p : productosSorted) {
            if (i == p->getCategoriaCocina()) {
                list.push_back(p);
            }
        }
    }
	return list;
}

vector<Producto*> OrdenProductos::sortProducts(vector<Producto*> productList, int cantidadCocinas) {
    bool push = false;
    vector<Producto*> productosSorted;
    for (int i = 0; i <= 3; i++) {
        for (Producto* p : productList) {
            if (p->getCategoriaCocina() == i) {
                Producto* newProduct = new Producto();
                newProduct = p;
                productosSorted.push_back(newProduct);
                push = true;
            }
        }
    }
    return productosSorted;
}

int OrdenProductos::getCantidadCocinas(vector<Producto*> productList) {
    int cantidadCocinas = 0;
    for (Producto* p : productList) {
        if (p->getCategoriaCocina() >= cantidadCocinas) {
			cantidadCocinas = p->getCategoriaCocina();
		}
	}
	return cantidadCocinas;
}

int OrdenProductos::getOrdenPrincipal(vector<Producto*> productList) {
    int ordenPrincipal = productList[0]->getCategoriaCocina();
	return ordenPrincipal;
}

void OrdenProductos::on_butt_send_clicked() {
    int cantidadCocinas = 0;
    int ordenPrincipal = 0;
    string filenameOrders = QDate::currentDate().toString("dd-MM-yy").toStdString() + "O" + ".csv";
    string filenameProducts = QDate::currentDate().toString("dd-MM-yy").toStdString() + "P" ".csv";
    std::ofstream outputFileOrd(filenameOrders, std::ios::app);
    std::ofstream outputFileProd(filenameProducts, std::ios::app);
    QTime hora = QTime::currentTime();
    orden_temp->setHora(hora.toString("h:mm").toStdString());
    orden_temp->setTotal(total);
    if (existente == 1) {
        orden_temp = printSectionedOrder(orden_temp->getProductos());
        ordenes.push_back(orden_temp);
        //Guardar orden dentro de archivo
        outputFileOrd << orden_temp->getId() << ';' << orden_temp->getNombre() << ';' << orden_temp->getEstado() << ';' << orden_temp->getHora() << ';' << orden_temp->getFecha() << ';' << orden_temp->getTotal() << '\n';
        for (Producto* p : orden_temp->getProductos()) {
            ordersNumber++;
            outputFileProd << p->getIdProducto() << ';' << p->getIdOrden() << ';' << p->getCantidad() << ';' << p->getName() << ';' << p->getCategoria() << ';' << p->getCategoriaOpciones() << ';' << p->getCategoriaCocina() << ';' << p->getComplemento1() << ';' << p->getComplemento2() << ';' << p->getComentario() << ';' << p->getPrice() << '\n';
        }
        orden_temp = new Orden();
        productoSeleccionado = new Producto();
        productos_temp.clear();
        this->accept();
    }
    else if (existente == 2){
        orden_temp = printSectionedOrder(orden_temp->getProductos());
        for (Orden* o : ordenes) {
            if (o->getId() == id_orden) {
                o = orden_temp;
            }
        }
        //Actualiza el arhivo de ordenes
        std::ofstream outputFileOrdEdit(filenameOrders);
        std::ofstream outputFileProdEdit(filenameProducts);
        for (Orden* o : ordenes) {
            outputFileOrdEdit << o->getId() << ';' << o->getNombre() << ';' << o->getEstado() << ';' << o->getHora() << ';' << o->getFecha() << ';' << o->getTotal() << '\n';
            for (Producto* p : o->getProductos()) {
                ordersNumber++;
                outputFileProdEdit << p->getIdProducto() << ';' << p->getIdOrden() << ';' << p->getCantidad() << ';' << p->getName() << ';' << p->getCategoria() << ';' << p->getCategoriaOpciones() << ';' << p->getCategoriaCocina() << ';' << p->getComplemento1() << ';' << p->getComplemento2() << ';' << p->getComentario() << ';' << p->getPrice() << '\n';
            }
        }
        orden_temp = new Orden();
        productoSeleccionado = new Producto();
        productos_temp.clear();
        this->accept();
    }
}

void OrdenProductos::on_butt_edit_clicked() {
    int index = ui->table_orden->currentRow();
    if (index >= 0) {
        
	}
    else {
		QMessageBox::warning(this, "Error", "Seleccione una orden para editar.");
	}
}

string OrdenProductos::addSpaces(const std::string& text, int width) {
    std::ostringstream oss;
    oss << std::setw(width) << std::left << text;
    return oss.str();
}

void OrdenProductos::Print(vector<Producto*> productsToPrint, int cocina, int ordenPrincipal) {
    // Inicializar libusb
    libusb_device_handle* printerHandle = nullptr;

    int result = libusb_init(nullptr);
    if (result != LIBUSB_SUCCESS)
    {
        QMessageBox::warning(this, "Error", "No se pudo inicializar libusb.");
        return;
    }

    // Brir impresora
    printerHandle = libusb_open_device_with_vid_pid(nullptr, 0x1FC9, 0x2016);
    if (printerHandle == nullptr)
    {
        QMessageBox::warning(this, "Error", "No se pudo abrir la interfaz usb.");
        libusb_exit(nullptr);
        return;
    }

    // Reclamar impresora
    result = libusb_claim_interface(printerHandle, 0);
    if (result != LIBUSB_SUCCESS)
    {
        QMessageBox::warning(this, "Error", "No se pudo reclamar la interfaz usb.");
        libusb_close(printerHandle);
        libusb_exit(nullptr);
        return;
    }

    // Inicializar impresora
    unsigned char initCommands[] = { 0x1B, 0x27 };
    int bytesWritten = 0;
    result = libusb_bulk_transfer(printerHandle, 0x01, (unsigned char*)initCommands, sizeof(initCommands), &bytesWritten, 1000);

    // Ajustar tamano de font
    unsigned char styleCommands[] = {0x1B, 0x21, 0x10};
    result = libusb_bulk_transfer(printerHandle, 0x01, (unsigned char*)styleCommands, sizeof(styleCommands), &bytesWritten, 1000);

    //Imprimir datos de orden
    
    string nombreCliente = to_string(orden_temp->getId()) + " " + orden_temp->getNombre();
    string formatedName = addSpaces(nombreCliente, 42);
    string horaOrden = orden_temp->getHora();
    string datosOrder = formatedName + horaOrden + "\n\n";
    unsigned char* dataOrder = reinterpret_cast<unsigned char*>(const_cast<char*>(datosOrder.c_str()));
    int dataOrderSize = static_cast<int>(datosOrder.length());
    result = libusb_bulk_transfer(printerHandle, 0x01, (unsigned char*)dataOrder, dataOrderSize, &bytesWritten, 5000);
    if (result != LIBUSB_SUCCESS)
    {
        QMessageBox::warning(this, "Error", "No se pudo enviar datos a la impresora.");
        libusb_release_interface(printerHandle, 0);
        libusb_close(printerHandle);
        libusb_exit(nullptr);
        return;
    }

    for (Producto* p : productsToPrint) {
        string NombreFormated = "";
        string nombreTemp = "";
        string nombre = p->getName();
        string cantidad = to_string(p->getCantidad());
        string complemento1 = p->getComplemento1();
        string complemento2 = p->getComplemento2();
        string comentario = p->getComentario();
        string datosProducto = "";
        string price = mostrarDecimales(p->getPrice());
        int categoriaOpciones = p->getCategoriaOpciones();
        int categoriaCocina = p->getCategoriaCocina();
        nombreTemp = cantidad + " " + nombre + " " + complemento2;
        NombreFormated = addSpaces(nombreTemp, 40);
        switch (categoriaOpciones)
        {
        case 0:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n   - " + complemento1 + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n   - " + complemento1 + "\n   - " + comentario + "\n";
            }
            break;
        case 1:
            if (complemento1 == "" || complemento2 == "") {
                datosProducto = NombreFormated + " " + price + " " + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n   - " + complemento1 + "\n";
            }
            if (comentario != "") {
                datosProducto = datosProducto + "\n" + "   - " + comentario + "\n";
            }
            break;
        case 2:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n   - " + complemento1 + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + " " + complemento2 + "\n   - " + complemento1 + "\n   - " + comentario + "\n";
            }
            break;
        case 3:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n   - " + complemento1 + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n   - " + complemento1 + "\n   - " + comentario + "\n";
            }
            break;
        case 4:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n   - " + complemento1 + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n   - " + complemento1 + "\n   - " + comentario + "\n";
            }
            break;
        case 5:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n   - " + comentario + "\n";
            }
            break;
        case 6:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n   - " + comentario + "\n";
            }
            break;
        case 7:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n   -" + comentario + "\n";
            }
            break;
        case 8:
            nombreTemp = cantidad + " " + nombre + " " + complemento2;
            NombreFormated = addSpaces(nombreTemp, 40);
            if (comentario == "") {
                datosProducto = cantidad + " " + nombre + "\n";
            }
            else {
                datosProducto = cantidad + " " + nombre + "\n";
            }
            break;
        case 9:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n  -" + comentario + "\n";
            }
            break;
        case 10:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n";
            }
            else {
                datosProducto = cantidad + " " + nombre + "\n   -" + comentario + "\n";
            }
            break;
        case 11:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n   -" + comentario + "\n";
            }
            break;
        case 12:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n  -" + comentario + "\n";
            }
            break;
        case 13:
            if (comentario == "") {
                datosProducto = NombreFormated + " " + price + "\n";
            }
            else {
                datosProducto = NombreFormated + " " + price + "\n  -" + comentario + "\n";
            }
            break;
        }

        // Imprimir Productos
        unsigned char* data = reinterpret_cast<unsigned char*>(const_cast<char*>(datosProducto.c_str()));
        int dataSize = static_cast<int>(datosProducto.length());
        result = libusb_bulk_transfer(printerHandle, 0x01, (unsigned char*)data, dataSize, &bytesWritten, 5000);
    }

    if (cocina == ordenPrincipal) {
        // Imprimir Total
        string inicio = addSpaces("", 30);
        string totalCorregido = mostrarDecimales(orden_temp->getTotal());
        string total = inicio + "Total: L " + totalCorregido + "\n";
        unsigned char* dataTotal = reinterpret_cast<unsigned char*>(const_cast<char*>(total.c_str()));
        int totalDataSize = static_cast<int>(total.length());
        result = libusb_bulk_transfer(printerHandle, 0x01, (unsigned char*)dataTotal, totalDataSize, &bytesWritten, 5000);
        if (result != LIBUSB_SUCCESS)
        {
            QMessageBox::warning(this, "Error", "No se pudo enviar datos a la impresora.");
            libusb_release_interface(printerHandle, 0);
            libusb_close(printerHandle);
            libusb_exit(nullptr);
            return;
        }
    }

    if (cocina != ordenPrincipal) {
        // Imprimir Flecha
        string flecha = "------------>>> va con algo mas ------------>>>\n";
        unsigned char* dataFlecha = reinterpret_cast<unsigned char*>(const_cast<char*>(flecha.c_str()));
        int totalDataSize = static_cast<int>(flecha.length());
        result = libusb_bulk_transfer(printerHandle, 0x01, (unsigned char*)dataFlecha, totalDataSize, &bytesWritten, 5000);
        if (result != LIBUSB_SUCCESS)
        {
            QMessageBox::warning(this, "Error", "No se pudo enviar datos a la impresora.");
            libusb_release_interface(printerHandle, 0);
            libusb_close(printerHandle);
            libusb_exit(nullptr);
            return;
        }
    }

    

    //Calcular el tamano del papel para cortar
    for (int i = 0; i < productsToPrint.size(); ++i) {
        std::string lineWithBreak = "\n";
        unsigned char* data = reinterpret_cast<unsigned char*>(const_cast<char*>(lineWithBreak.c_str()));
        int breakSize = static_cast<int>(lineWithBreak.length());

        int result = libusb_bulk_transfer(printerHandle, 0x01, data, breakSize, &bytesWritten, 1000);
        if (result != LIBUSB_SUCCESS) {
            // error
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Adjust the delay time as needed

        if (i == productsToPrint.size() - 1) {
            int paperFeedLines = (productsToPrint.size() * 3 + 3) * 500;

            unsigned char paperFeedCommand[] = { 0x1B, 0x4A, static_cast<unsigned char>(paperFeedLines) };
            int paperFeedCommandSize = sizeof(paperFeedCommand);

            result = libusb_bulk_transfer(printerHandle, 0x01, paperFeedCommand, paperFeedCommandSize, &bytesWritten, 1000);
            if (result != LIBUSB_SUCCESS) {
                // error
            }
        }
    }

    // Cortar papel
    unsigned char cutCommands[] = { 0x1D, 0x56, 0x01 };
    result = libusb_bulk_transfer(printerHandle, 0x01, (unsigned char*)cutCommands, sizeof(cutCommands), &bytesWritten, 5000);
    if (result != LIBUSB_SUCCESS)
    {
        QMessageBox::warning(this, "Error 7", "No se pudo cortar el papel a la impresora.");
        libusb_release_interface(printerHandle, 0);
        libusb_close(printerHandle);
        libusb_exit(nullptr);
        return;
    }

    libusb_release_interface(printerHandle, 0);
    libusb_close(printerHandle);
    libusb_exit(nullptr);
}

Orden* OrdenProductos::printSectionedOrder(vector<Producto*> productList) {
    int cantidadCocinas = 0;
    int ordenPrincipal = 0;
    //Sort los productos dependiendo del id de cocina
    vector<Producto*> productosSorted;
    productosSorted = sortProducts(productList, cantidadCocinas);
    cantidadCocinas = getCantidadCocinas(productosSorted);
    ordenPrincipal = getOrdenPrincipal(productosSorted);
    orden_temp->setProductos(productosSorted);
    //Obtiene cada tipo de producto y crea nuevas listas para dividir la orden al momento de imprimir
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Imprimir", "Desea imprimir la orden?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        for (int i = 0; i <= cantidadCocinas; i++) {
            productsToPrint = getTypeList(i, ordenPrincipal, productosSorted);
            if (productsToPrint.empty()) {
                continue;
            }
            else if (i == productsToPrint[0]->getCategoriaCocina()) {
                Print(productsToPrint, i, ordenPrincipal);
            }
        }
    }
    return orden_temp;
}

void OrdenProductos::on_butt_eliminar_clicked() {
    vector<Producto*> productList;
    isDelete = true;
    int index = ui->table_orden->currentRow();
    productList = orden_temp->getProductos();
    productList.erase(productList.begin() + index);
    orden_temp->setProductos(productList);
    refreshOrders();
}

void OrdenProductos::refreshOrders() {
    ui->table_orden->clear();
    int row = 0;
    int cantidad = 1;
    total = 0;
    ui->label_orden->setText(QString::fromStdString(to_string(orden_temp->getId())));
    ui->label_cliente->setText(QString::fromStdString((orden_temp->getNombre())));
    QTableWidgetItem* itemNombre = new QTableWidgetItem;
    QTableWidgetItem* itemComp1 = new QTableWidgetItem;
    QTableWidgetItem* itemComp2 = new QTableWidgetItem;
    QTableWidgetItem* itemComentario = new QTableWidgetItem;
    QTableWidgetItem* itemCant = new QTableWidgetItem;
    QTableWidgetItem* itemPrecio = new QTableWidgetItem;
    ui->table_orden->setColumnCount(6);
    ui->table_orden->setHorizontalHeaderItem(0, new QTableWidgetItem("Cantidad"));
    ui->table_orden->setHorizontalHeaderItem(1, new QTableWidgetItem("Nombre"));
    ui->table_orden->setHorizontalHeaderItem(2, new QTableWidgetItem("Complemento 1"));
    ui->table_orden->setHorizontalHeaderItem(3, new QTableWidgetItem("Complemento 2"));
    ui->table_orden->setHorizontalHeaderItem(4, new QTableWidgetItem("Comentario"));
    ui->table_orden->setHorizontalHeaderItem(5, new QTableWidgetItem("Precio"));
    ui->table_orden->setRowCount(20);
    for (Producto* p : orden_temp->getProductos()) {
        itemNombre = new QTableWidgetItem(QString::fromStdString(p->getName()));
        itemComp1 = new QTableWidgetItem(QString::fromStdString(p->getComplemento1()));
        itemComp2 = new QTableWidgetItem(QString::fromStdString(p->getComplemento2()));
        itemComentario = new QTableWidgetItem(QString::fromStdString(p->getComentario()));
        itemCant = new QTableWidgetItem(QString::number(p->getCantidad()));
        string price = mostrarDecimales(p->getPrice());
        itemPrecio = new QTableWidgetItem(QString::fromStdString(price));
        ui->table_orden->setItem(row, 0, itemCant);
        ui->table_orden->setItem(row, 1, itemNombre);
        ui->table_orden->setItem(row, 2, itemComp1);
        ui->table_orden->setItem(row, 3, itemComp2);
        ui->table_orden->setItem(row, 4, itemComentario);
        ui->table_orden->setItem(row, 5, itemPrecio);
        total = p->getPrice() + total;
        row++;
    }
    ui->label_total->setText(QString::number(total) + ".00");
}

string OrdenProductos::mostrarDecimales(double valor) {
    std::ostringstream oss;
    oss << std::fixed;
    oss.precision(2);
    oss << valor;
    std::string result = oss.str();
    return result;
}

void OrdenProductos::clearProducts(QLayout* layout) {
    if (layout == NULL)
        return;
    QLayoutItem* item;
    while ((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearProducts(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void OrdenProductos::on_butt_back_clicked() {
    this->accept();
    agregarProductos agregarProductos;
    agregarProductos.setModal(true);
    agregarProductos.exec();
}

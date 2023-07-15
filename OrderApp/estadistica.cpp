#include "estadistica.h"
#include "ui_estadistica.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Orden.h"
#include "global.h"
using std::string;
using std::ifstream;

Estadistica::Estadistica(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Estadistica)
{
    ui->setupUi(this);
    ui->table_products->setColumnCount(2);
    for (Orden* o : ordenes) {

    }
}

Estadistica::~Estadistica()
{
    delete ui;

}

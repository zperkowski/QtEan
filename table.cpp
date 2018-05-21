#include "table.h"
#include "ui_table.h"
#include <iostream>

Table::Table(QWidget *parent, Matrix matrix) :
    QMainWindow(parent), ui(new Ui::Table) {
        ui->setupUi(this);

    this->matrix = matrix;
    std::cout << "Table: " << matrix.getHeight() << "x" << matrix.getWidth() << std::endl;
    ui->tableWidget->setRowCount(matrix.getWidth());
    ui->tableWidget->setColumnCount(matrix.getHeight());

    for(unsigned long int y = 0; y < matrix.getHeight(); y++)
        for(unsigned long int x = 0; x < matrix.getWidth(); x++)
            ui->tableWidget->setItem(x, y, new QTableWidgetItem(QString::number((double) matrix.getCell(x, y))));
}

Table::Table(QWidget *parent, std::vector<long double> x) :
    QMainWindow(parent), ui(new Ui::Table) {
        ui->setupUi(this);

    this->x = x;
    std::cout << "x.size(): " << x.size() << std::endl;
    ui->tableWidget->setRowCount(x.size());
    ui->tableWidget->setColumnCount(1);

    for(unsigned long int i = 0; i < x.size(); i++)
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::number((double) x[i])));
}

Table::~Table() {
    delete ui;
}

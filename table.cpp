#include "table.h"
#include "ui_table.h"
#include <iostream>

Table::Table(QWidget *parent, Matrix matrix) :
    QMainWindow(parent), ui(new Ui::Table) {
        ui->setupUi(this);

    this->matrix = matrix;
    std::cout << "Table: " << matrix.getHeight() << "x" << matrix.getWidth() << std::endl;
    ui->tableWidget->setRowCount(matrix.getHeight());
    ui->tableWidget->setColumnCount(matrix.getWidth());

    for(unsigned long int y = 0; y < matrix.getHeight(); y++)
        for(unsigned long int x = 0; x < matrix.getWidth(); x++)
            ui->tableWidget->setItem(y, x, new QTableWidgetItem(QString::number((double) matrix.getCell(y, x))));
}

Table::~Table() {
    delete ui;
}

#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.h"
#include "equation.h"
#include "matrix.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

void MainWindow::buttonRandomResultClicked() {
    //Matrix
    Matrix matrixRandom(
                ui->lineEdit_matrix_x->text().toInt(),
                ui->lineEdit_matrix_y->text().toInt()
                );
    matrixRandom.generateRandom();

    long double x = ui->lineEdit_x->text().toDouble();

    Matrix matrixB(matrixRandom.getHeight(), matrixRandom.getWidth());
    matrixB.generateZeros();

    std::cout << "matrixRandom.getHeight(): "
              << matrixRandom.getHeight()
              << " matrixRandom.getWidth(): "
              << matrixRandom.getWidth()
              << " x: "
              << x
              << " matrixB.getHeight(): "
              << matrixB.getHeight()
              << " matrixB.getWidth(): "
              << matrixB.getWidth()
              << std::endl;

    std::vector<Equation> equationsVector;

    Equation eq(matrixRandom, x);

    Table *tableA = new Table(this, eq.getA());
    tableA->setWindowTitle("Matrix A");
    tableA->show();

    Table *tableB = new Table(this, eq.getB());
    tableB->setWindowTitle("Matrix B");
    tableB->show();
}

void MainWindow::buttonRandomBigResultClicked() {
    Matrix matrixBig(
                ui->lineEdit_matrix_x_big->text().toInt(),
                ui->lineEdit_matrix_y_big->text().toInt());
    matrixBig.generateRandom(
                ui->lineEdit_min_exp_big->text().toDouble(),
                ui->lineEdit_max_exp_big->text().toDouble());

    std::cout << matrixBig.getCell(0, 0) << std::endl;
//    std::cout << matrixBig.getCell(
//                      ui->lineEdit_matrix_x_big->text().toInt() - 1,
//                      ui->lineEdit_matrix_y_big->text().toInt() - 1)
//               << std::endl;

}

void MainWindow::buttonRandomHilbertResultClicked() {

}


MainWindow::~MainWindow() {
    delete ui;
}

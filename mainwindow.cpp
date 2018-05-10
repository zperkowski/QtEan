#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include "equation.h"
#include "matrix.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

void MainWindow::buttonRandomResultClicked() {
    //Matrix
    Matrix *matrixRandom = new Matrix(
                ui->lineEdit_matrix_x->text().toInt(),
                ui->lineEdit_matrix_y->text().toInt()
                );

    std::cout << matrixRandom->getHeight()
              << std::endl
              << matrixRandom->getWidth()
              << std::endl;

    std::vector<Equation> equationsVector;

    //First equation
    long double x = ui->lineEdit_matrix_x->text().toDouble();
    long double y = ui->lineEdit_matrix_y->text().toDouble();
    long double b = ui->lineEdit_x->text().toDouble();

//    Equation *eq = new Equation(x, y, b);

//    equationsVector.push_back(*eq);

    //Second equation
    x = ui->lineEdit_matrix_x->text().toDouble();
    y = ui->lineEdit_matrix_y->text().toDouble();
    b = ui->lineEdit_x->text().toDouble();

//    eq = new Equation(x, y, b);

//    equationsVector.push_back(*eq);

//    Canvas *canvas = new Canvas(this, equationsVector);
//    canvas->show();
}

void MainWindow::buttonRandomBigResultClicked() {

}

void MainWindow::buttonRandomHilbertResultClicked() {

}


MainWindow::~MainWindow() {
    delete ui;
}

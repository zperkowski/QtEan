#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.h"
#include "equation.h"
#include "matrix.h"
#include <sstream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

void MainWindow::buttonRandomResultClicked() {
    //Matrix
    Matrix matrixRandom(
                ui->lineEdit_matrix_y->text().toInt(),
                ui->lineEdit_matrix_x->text().toInt()
                );
    matrixRandom.generateRandom();

    std::string x_tmp = ui->lineEdit_x->text().toStdString();
    std::vector<long double> x;
    x = parseX(x_tmp);

    std::vector<Equation> equationsVector;

    Equation eq(matrixRandom, x);
    eq.mulAX();
    eq.mulAB();
    showTables(eq);
    std::cout << "det: " << eq.det(eq.getA()) << std::endl;

}

void MainWindow::buttonRandomBigResultClicked() {
    Matrix matrixBig(
                ui->lineEdit_matrix_y_big->text().toInt(),
                ui->lineEdit_matrix_x_big->text().toInt());
    matrixBig.generateRandom(
                ui->lineEdit_min_exp_big->text().toDouble(),
                ui->lineEdit_max_exp_big->text().toDouble());

    std::string x_tmp = ui->lineEdit_x_big->text().toStdString();
    std::vector<long double> x;
    x = parseX(x_tmp);

    Equation eq(matrixBig, x);
    eq.mulAX();
    showTables(eq);
}

void MainWindow::buttonRandomHilbertResultClicked() {
    Matrix matrixHilbert(
                ui->lineEdit_matrix_y_hilbert->text().toInt(),
                ui->lineEdit_matrix_x_hilbert->text().toInt());
    matrixHilbert.generateHilbert();

    std::string x_tmp = ui->lineEdit_x_hilbert->text().toStdString();
    std::vector<long double> x;
    x = parseX(x_tmp);

    Equation eq(matrixHilbert, x);
    eq.mulAX();
    showTables(eq);
}

std::vector<long double> MainWindow::parseX(std::string input) {
    long double tmp;
    std::vector<long double> vector;
    std::string::size_type position = 0, nextPosition = 0;
    while(position < input.size()) {
        tmp = std::stod(input.substr(position), &nextPosition);
        vector.push_back(tmp);
        position += nextPosition;
    }
    return vector;
}

void MainWindow::showTables(Equation eq) {
    Table *tableA = new Table(this, eq.getA());
    tableA->setWindowTitle("Matrix A");
    tableA->show();
    Table *tableX = new Table(this, eq.getX());
    tableX->setWindowTitle("X");
    tableX->show();
    Table *tableX2 = new Table(this, eq.getX2());
    tableX2->setWindowTitle("X2");
    tableX2->show();
    Table *tableB = new Table(this, eq.getB());
    tableB->setWindowTitle("Matrix B");
    tableB->show();

}

MainWindow::~MainWindow() {
    delete ui;
}

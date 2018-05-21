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

    // TODO: Seperate all numbers in the text
    std::string x_tmp = ui->lineEdit_x->text().toStdString();
    std::vector<long double> x;
    x = parseX(x_tmp);

    Matrix matrixB(matrixRandom.getHeight(), matrixRandom.getWidth());
    matrixB.generateZeros();

    std::cout << "matrixRandom.getHeight(): "
              << matrixRandom.getHeight()
              << " matrixRandom.getWidth(): "
              << matrixRandom.getWidth()
              << " x.size(): "
              << x.size()
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
    std::cout << "det: " << eq.det(eq.getA()) << std::endl;
}

void MainWindow::buttonRandomBigResultClicked() {
    Matrix matrixBig(
                ui->lineEdit_matrix_y_big->text().toInt(),
                ui->lineEdit_matrix_x_big->text().toInt());
    matrixBig.generateRandom(
                ui->lineEdit_min_exp_big->text().toDouble(),
                ui->lineEdit_max_exp_big->text().toDouble());

    // TODO: Seperate all numbers in the text
    long double x_tmp = ui->lineEdit_x_big->text().toDouble();
    std::vector<long double> x;
    x.push_back(x_tmp);

    Equation eq(matrixBig, x);

    Table *tableA = new Table(this, eq.getA());
    tableA->setWindowTitle("Matrix A");
    tableA->show();

    Table *tableB = new Table(this, eq.getB());
    tableB->setWindowTitle("Matrix B");
    tableB->show();
}

void MainWindow::buttonRandomHilbertResultClicked() {
    Matrix matrixHilbert(
                ui->lineEdit_matrix_y_hilbert->text().toInt(),
                ui->lineEdit_matrix_x_hilbert->text().toInt());
    matrixHilbert.generateHilbert();

    // TODO: Seperate all numbers in the text
    long double x_tmp = ui->lineEdit_x_hilbert->text().toInt();
    std::vector<long double> x;
    x.push_back(x_tmp);

    Equation eq(matrixHilbert, x);

    Table *tableA = new Table(this, eq.getA());
    tableA->setWindowTitle("Matrix A");
    tableA->show();

    Table *tableB = new Table(this, eq.getB());
    tableB->setWindowTitle("Matrix B");
    tableB->show();
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

MainWindow::~MainWindow() {
    delete ui;
}

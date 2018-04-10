#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include "equation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

void MainWindow::buttonResultClicked() {
    std::vector<Equation> equationsVector;

    //First equation
    long double x = ui->lineEdit_x1->text().toDouble();
    long double y = ui->lineEdit_y1->text().toDouble();
    long double c = ui->lineEdit_c1->text().toDouble();

    Equation *eq = new Equation(x, y, c);

    equationsVector.push_back(*eq);

    //Second equation
    x = ui->lineEdit_x2->text().toDouble();
    y = ui->lineEdit_y2->text().toDouble();
    c = ui->lineEdit_c2->text().toDouble();

    eq = new Equation(x, y, c);

    equationsVector.push_back(*eq);

    Canvas *canvas = new Canvas(this, equationsVector);
    canvas->show();
}

MainWindow::~MainWindow() {
    delete ui;
}

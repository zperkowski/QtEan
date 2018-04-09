#include "canvas.h"
#include "ui_canvas.h"
#include <iostream>

Canvas::Canvas(QWidget *parent, std::vector<Equation> eqVector) :
    QMainWindow(parent), ui(new Ui::Canvas) {
    ui->setupUi(this);
    foreach (Equation eq, eqVector) {
        std::cout << eq.getX() << " " << eq.getY() << " " << eq.getC() << std::endl;
    }
}

Canvas::~Canvas()
{
    delete ui;
}

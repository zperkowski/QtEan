#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

void MainWindow::buttonResultClicked() {
    Canvas *canvas = new Canvas(this);
    canvas->show();
}

MainWindow::~MainWindow() {
    delete ui;
}

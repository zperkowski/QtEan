#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equation.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void buttonRandomResultClicked();
    void buttonRandomBigResultClicked();
    void buttonRandomHilbertResultClicked();

private:
    Ui::MainWindow *ui;
    std::vector<long double> parseX(std::string input);
    void showTables(Equation eq);
};

#endif // MAINWINDOW_H

#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include "matrix.h"

namespace Ui {
class Table;
}

class Table : public QMainWindow
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0, Matrix matrix = Matrix(0,0));
    ~Table();

private:
    Matrix matrix;
    Ui::Table *ui;
};

#endif // TABLE_H

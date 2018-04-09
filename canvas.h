#ifndef CANVAS_H
#define CANVAS_H

#include <QMainWindow>
#include <vector>
#include "equation.h"

namespace Ui {
class Canvas;
}

class Canvas : public QMainWindow
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = 0, std::vector<Equation> eqVector = {});
    ~Canvas();

private:
    Ui::Canvas *ui;
};

#endif // CANVAS_H

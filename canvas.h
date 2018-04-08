#ifndef CANVAS_H
#define CANVAS_H

#include <QMainWindow>

namespace Ui {
class Canvas;
}

class Canvas : public QMainWindow
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();

private:
    Ui::Canvas *ui;
};

#endif // CANVAS_H

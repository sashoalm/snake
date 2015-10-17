#include "widget.h"

#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    x=5;
    y=5;
    dir = Qt::Key_Up;
    field.setCell(x, y, Field::Snake);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(moveSnake()));
    timer->start(333);
}

void Widget::moveSnake()
{
    field.setCell(x, y, Field::Empty);

    switch (dir) {
    case Qt::Key_Right: x++; break;
    case Qt::Key_Left: x--; break;
    case Qt::Key_Down: y++; break;
    case Qt::Key_Up: y--; break;
    }

    if (field.getCell(x, y) == Field::Wall) {
        endGame();
    }
    field.setCell(x, y, Field::Snake);
    update();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    Qt::GlobalColor cols[] = { Qt::blue, Qt::red, Qt::yellow, Qt::green };
    for (int xx = 0; xx < field.width(); ++xx) {
        for (int yy = 0; yy < field.height(); ++yy) {
            painter.fillRect(xx*cellSize(), yy*cellSize(), cellSize(), cellSize(), cols[field.getCell(xx, yy)]);
        }
    }
}

void Widget::endGame()
{
    delete timer;
    close();
}


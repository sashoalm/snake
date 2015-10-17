#include "widget.h"

#include <QPainter>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    cells.resize(fieldWidth()*fieldHeight());
    cells.fill(Empty);

    // Draw the wall around the field.
    for (int ii = 0; ii < fieldWidth(); ++ii) {
        setCell(ii, 0, Wall);
        setCell(ii, fieldHeight()-1, Wall);
    }
    for (int ii = 0; ii < fieldHeight(); ++ii) {
        setCell(0, ii, Wall);
        setCell(fieldWidth()-1, ii, Wall);
    }
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    Qt::GlobalColor cols[] = { Qt::blue, Qt::red, Qt::yellow, Qt::green };
    for (int xx = 0; xx < fieldWidth(); ++xx) {
        for (int yy = 0; yy < fieldHeight(); ++yy) {
            painter.fillRect(xx*cellSize(), yy*cellSize(), cellSize(), cellSize(), cols[getCell(xx, yy)]);
        }
    }
}


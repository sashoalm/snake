#include "widget.h"

#include <QPainter>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
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


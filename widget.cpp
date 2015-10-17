#include "widget.h"

#include <QKeyEvent>
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QPoint p(1, 1);
    snake.enqueue(p);
    length = 1;
    dir = Qt::Key_Right;
    field.setCell(p.x(), p.y(), Field::Snake);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(moveSnake()));
    timer->start(333);
    setFocusPolicy(Qt::WheelFocus);
}

void Widget::moveSnake()
{
    if (snake.size() <= length) {
        QPoint p = snake.back();
        switch (dir) {
        case Qt::Key_Right: p.rx()++; break;
        case Qt::Key_Left: p.rx()--; break;
        case Qt::Key_Down: p.ry()++; break;
        case Qt::Key_Up: p.ry()--; break;
        }

        switch(field.getCell(p.x(), p.y())) {
        case Field::Snake:
        case Field::Wall:
            endGame();
            return;
        case Field::Food:
            length++;
            break;
        }

        snake.enqueue(p);
        field.setCell(p.x(), p.y(), Field::Snake);
    }

    if (snake.size() > length) {
        QPoint p = snake.dequeue();
        field.setCell(p.x(), p.y(), Field::Empty);
    }

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

void Widget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Right:
    case Qt::Key_Left:
    case Qt::Key_Down:
    case Qt::Key_Up:
        dir = e->key();
        break;
    }

    QWidget::keyPressEvent(e);
}

void Widget::endGame()
{
    delete timer;
    close();
}


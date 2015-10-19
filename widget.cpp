#include "widget.h"

#include <QKeyEvent>
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent) : QWidget(parent), snake(QPoint(1,1), Snake::Right)
{
    field.setCell(QPoint(1,1), Field::Snake);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(moveSnake()));
    timer->start(111);
    setFocusPolicy(Qt::WheelFocus);
    setFixedSize(field.width()*cellSize(), field.height()*cellSize());
}

void Widget::moveSnake()
{
    if (!snake.isGrowing()) {
        field.setCell(snake.tail(), Field::Empty);
    }

    snake.move();

    // See if the snake hit anything.
    switch(field.getCell(snake.head())) {
    case Field::Snake:
    case Field::Wall:
        endGame();
        return;
    case Field::Food:
        snake.grow();
        break;
    }

    field.setCell(snake.head(), Field::Snake);

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
    case Qt::Key_Right: snake.setDirection(Snake::Right); break;
    case Qt::Key_Left: snake.setDirection(Snake::Left); break;
    case Qt::Key_Down: snake.setDirection(Snake::Down); break;
    case Qt::Key_Up: snake.setDirection(Snake::Up); break;
    }

    QWidget::keyPressEvent(e);
}

void Widget::endGame()
{
    delete timer;
    close();
}


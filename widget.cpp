#include "widget.h"

#include <QApplication>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent) : QWidget(parent), snake(QPoint(1,1), Snake::Right)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(moveSnake()));
    timer->setInterval(111);
    setFocusPolicy(Qt::WheelFocus);
    setFixedSize(field.width()*cellSize(), field.height()*cellSize());
    field.setCell(QPoint(1,1), Field::Snake);
    timer->start();
}

void Widget::moveSnake()
{
    if (!snake.isGrowing()) {
        field.setCell(snake.tail(), Field::Empty);
        updateCell(snake.tail());
    }

    snake.move();

    // See if the snake hit anything.
    switch(field.getCell(snake.head())) {
    case Field::Snake:
    case Field::Wall:
        endGame("You lost.");
        return;
    case Field::Food:
        snake.grow();
        break;
    }

    field.setCell(snake.head(), Field::Snake);
    updateCell(snake.head());

    if (!field.foodLeft()) {
        endGame("You won!");
    }
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    Qt::GlobalColor cols[] = { Qt::blue, Qt::red, Qt::yellow, Qt::green };

    foreach (const QRect &r, e->region().rects()) {
        int ll = r.left() / cellSize();
        int tt = r.top() / cellSize();
        int rr = (r.left() + r.width()) / cellSize();
        int bb = (r.top() + r.height()) / cellSize();

        for (int xx = ll; xx < rr; ++xx) {
            for (int yy = tt; yy < bb; ++yy) {
                painter.fillRect(xx*cellSize(), yy*cellSize(), cellSize(), cellSize(), cols[field.getCell(xx, yy)]);
            }
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

void Widget::focusInEvent(QFocusEvent *)
{
    timer->start();
}

void Widget::focusOutEvent(QFocusEvent *)
{
    timer->stop();
}

void Widget::updateCell(const QPoint &p)
{
    update(p.x() * cellSize(), p.y() * cellSize(), cellSize(), cellSize());
}

void Widget::endGame(const QString &text)
{
    timer->stop();
    if (QMessageBox::Yes == QMessageBox::question(this, "Game over.", text + " New game?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes)) {
        newGame();
    } else {
        QApplication::instance()->quit();
    }
}

void Widget::newGame()
{
    snake.reset(QPoint(1,1), Snake::Right);
    field.reset();
    field.setCell(QPoint(1,1), Field::Snake);
    timer->start();
    update();
}


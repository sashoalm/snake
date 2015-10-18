#include "snake.h"

Snake::Snake(const QPoint &startPos, int direction)
{
    body.enqueue(startPos);
    this->direction = direction;
    targetLength = 1;
}

Snake::~Snake()
{

}

void Snake::move()
{
    // Move head.
    QPoint p = head();
    switch (direction) {
    case Qt::Key_Right: p.rx()++; break;
    case Qt::Key_Left: p.rx()--; break;
    case Qt::Key_Down: p.ry()++; break;
    case Qt::Key_Up: p.ry()--; break;
    }
    body.enqueue(p);

    // Move tail (if not growing).
    if (body.size() > targetLength) {
        body.dequeue();
    }
}

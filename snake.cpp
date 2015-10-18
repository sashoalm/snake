#include "snake.h"

Snake::Snake(const QPoint &startPos, Direction direction)
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
    case Right: p.rx()++; break;
    case Left: p.rx()--; break;
    case Down: p.ry()++; break;
    case Up: p.ry()--; break;
    }
    body.enqueue(p);

    // Move tail (if not growing).
    if (body.size() > targetLength) {
        body.dequeue();
    }
}

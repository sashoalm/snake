#include "snake.h"

Snake::Snake(const QPoint &startPos, Direction direction)
{
    reset(startPos, direction);
}

Snake::~Snake()
{

}

void Snake::reset(const QPoint &startPos, Snake::Direction direction)
{
    body.clear();
    directions.clear();
    body.enqueue(startPos);
    directions.enqueue(direction);
    targetLength = 1;
}

void Snake::move()
{
    if (directions.size() > 1) {
        directions.dequeue();
    }

    // Move head.
    QPoint p = head();
    switch (directions.head()) {
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

void Snake::setDirection(Snake::Direction direction)
{
    static const Snake::Direction oppositeOf[] = { Right, Left, Down, Up };
    if (direction != directions.back() && direction != oppositeOf[directions.back()]) {
        directions.enqueue(direction);
    }
}

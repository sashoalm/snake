#ifndef SNAKE_H
#define SNAKE_H

#include <QQueue>
#include <QPoint>

class Snake
{
public:
    enum Direction { Left, Right, Up, Down };

    Snake(const QPoint &startPos, Direction direction);
    ~Snake();

    QPoint tail() { return body.front(); }
    QPoint head() { return body.back(); }
    bool isGrowing() { return targetLength > body.size(); }
    void grow() { targetLength++; }
    void move();
    void setDirection(Direction direction);

private:
    QQueue<QPoint> body;
    QQueue<Direction> directions;
    int targetLength;
};

#endif // SNAKE_H

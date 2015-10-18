#ifndef SNAKE_H
#define SNAKE_H

#include <QQueue>
#include <QPoint>

class Snake
{
public:
    Snake(const QPoint &startPos, int direction);
    ~Snake();

    QPoint tail() { return body.front(); }
    QPoint head() { return body.back(); }
    bool isGrowing() { return targetLength > body.size(); }
    void grow() { targetLength++; }
    void move();
    void setDirection(int direction) { this->direction = direction; }

private:
    int direction;
    QQueue<QPoint> body;
    int targetLength;
};

#endif // SNAKE_H

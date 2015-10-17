#ifndef FIELD_H
#define FIELD_H

#include <QVector>

class Field
{
public:
    Field();
    ~Field();

    int width();
    int height();

    enum Cell { Empty, Wall, Food, Snake };
    Cell getCell(int x, int y);
    void setCell(int x, int y, Cell val);

private:
    void placeFood();
    QVector<Cell> cells;
};

#endif // FIELD_H

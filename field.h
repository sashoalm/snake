#ifndef FIELD_H
#define FIELD_H

#include <QPoint>
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
    Cell getCell(const QPoint &p) { return getCell(p.x(), p.y()); }
    void setCell(const QPoint &p, Cell val) { setCell(p.x(), p.y(), val); }

private:
    void placeFood();
    QVector<Cell> cells;
};

#endif // FIELD_H

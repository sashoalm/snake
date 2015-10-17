#include "field.h"

Field::Field()
{
    cells.resize(width()*height());
    cells.fill(Empty);

    // Draw the wall around the field.
    for (int ii = 0; ii < width(); ++ii) {
        setCell(ii, 0, Wall);
        setCell(ii, height()-1, Wall);
    }
    for (int ii = 0; ii < height(); ++ii) {
        setCell(0, ii, Wall);
        setCell(width()-1, ii, Wall);
    }

    for (int ii = 0; ii < 10; ++ii) {
        placeFood();
    }
}

Field::~Field()
{

}

int Field::width()
{
    return 20;
}

int Field::height()
{
    return 20;
}

Field::Cell Field::getCell(int x, int y)
{
    return cells[x+y*width()];
}

void Field::setCell(int x, int y, Field::Cell val)
{
    cells[x+y*width()] = val;
}

void Field::placeFood()
{
    while (1) {
        int x = qrand()%width();
        int y = qrand()%height();
        if (getCell(x, y) == Empty) {
            setCell(x, y, Food);
            break;
        }
    }
}


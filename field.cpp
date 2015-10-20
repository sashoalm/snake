#include "field.h"

#include <QTime>

Field::Field()
{
    reset();
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

void Field::reset()
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

    mFoodLeft = 0;
    for (int ii = 0; ii < 10; ++ii) {
        placeFood();
    }
}

Field::Cell Field::getCell(int x, int y)
{
    return cells[x+y*width()];
}

void Field::setCell(int x, int y, Field::Cell val)
{
    Cell &cell = cells[x+y*width()];
    if (cell == Food && val != Food) {
        mFoodLeft--;
    }
    cell = val;
}

void Field::placeFood()
{
    static bool seeded = false;
    if (!seeded) {
        qsrand(QTime::currentTime().msecsSinceStartOfDay());
        seeded = true;
    }

    while (1) {
        int x = qrand()%width();
        int y = qrand()%height();
        if (getCell(x, y) == Empty) {
            setCell(x, y, Food);
            break;
        }
    }

    mFoodLeft++;
}


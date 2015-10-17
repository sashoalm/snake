#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);

signals:

public slots:

private:
    virtual void paintEvent(QPaintEvent *);

    int fieldWidth() { return 20; }
    int fieldHeight() { return 20; }
    int cellSize() { return 10; }

    enum Cell { Empty, Wall, Food, Snake };
    Cell getCell(int x, int y) { return cells[x+y*fieldWidth()]; }
    void setCell(int x, int y, Cell val) { cells[x+y*fieldWidth()] = val; }
    QVector<Cell> cells;
};

#endif // WIDGET_H

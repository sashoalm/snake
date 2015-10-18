#ifndef WIDGET_H
#define WIDGET_H

#include "field.h"
#include "snake.h"

#include <QQueue>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);

signals:

private slots:
    void moveSnake();

private:
    virtual void paintEvent(QPaintEvent *);
    virtual void keyPressEvent(QKeyEvent *e);

    QTimer *timer;
    void endGame();

    int cellSize() { return 10; }
    Field field;
    Snake snake;
};

#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include "field.h"

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

    int dir;
    QQueue<QPoint> snake;
    int length;

    QTimer *timer;
    void endGame();

    int cellSize() { return 10; }
    Field field;
};

#endif // WIDGET_H

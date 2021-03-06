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

public slots:
    void newGame();

private slots:
    void moveSnake();

private:
    virtual void paintEvent(QPaintEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void focusInEvent(QFocusEvent *);
    virtual void focusOutEvent(QFocusEvent *);

    void updateCell(const QPoint &p);

    QTimer *timer;
    void endGame(const QString &text);

    int cellSize() { return 10; }
    Field field;
    Snake snake;
};

#endif // WIDGET_H

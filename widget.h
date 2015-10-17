#ifndef WIDGET_H
#define WIDGET_H

#include "field.h"

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

    int cellSize() { return 10; }
    Field field;
};

#endif // WIDGET_H

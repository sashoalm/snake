#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(minimumSize());
    ui->actionNew_Game->setShortcut(QKeySequence(Qt::Key_F2));
    connect(ui->actionNew_Game, SIGNAL(triggered(bool)), ui->widget, SLOT(newGame()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

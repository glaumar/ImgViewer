#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view_ = new IGraphicsView(this);
    setCentralWidget(view_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImg(const QString &fileName){
    view_->load(fileName);
}


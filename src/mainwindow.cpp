#include "mainwindow.h"
#include "ui_mainwindow.h"

// TODO: delete begin
#include <QDebug>
// TODO: delete end
#include <QDesktopWidget>
#include <QFileDialog>
#include <QIcon>
#include <QScreen>
#include <QSize>
#include <QStandardPaths>
#include <QtGlobal>

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view_ = new IGraphicsView(this);
    setCentralWidget(view_);

    // context Menu
    context_.addAction(QIcon::fromTheme("document-open"), "open", [this]() {
        QString fileName = QFileDialog::getOpenFileName(
          this,
          tr("Open File"),
          QStandardPaths::writableLocation(QStandardPaths::PicturesLocation),
          tr("Images (*.png *.xpm *.jpg)"));
        if (!fileName.isEmpty())
            openImg(fileName);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::openImg(const QString& fileName)
{
    view_->load(fileName);
    QSize psize = view_->pixmapSize();
    // TODO: get the current screen if has multi screen
    QSize availableSize = qApp->screens().first()->size() * 0.7;
    psize.scale(availableSize, Qt::KeepAspectRatio);
    resize(psize);
}

void
MainWindow::resizeEvent(QResizeEvent* event)
{
    QSize psize = view_->pixmapSize();
    QSize psize_bak = psize;

    psize.scale(event->size(), Qt::KeepAspectRatio);
    double ratio = double(psize.height()) / psize_bak.height();

    view_->resetTransform();
    view_->scale(ratio, ratio);
}

void
MainWindow::contextMenuEvent(QContextMenuEvent* event)
{
    context_.exec(QCursor::pos());
}

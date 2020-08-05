#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "IGraphicsView.h"
#include <QMainWindow>
#include <QPainter>
#include <QResizeEvent>
#include <QContextMenuEvent>
#include <QMenu>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void openImg(const QString &fileName);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;
  private:
    Ui::MainWindow* ui;
    IGraphicsView *view_;
    QMenu context_;
    qreal original_zoom_ratio_ = 1;

};
#endif // MAINWINDOW_H

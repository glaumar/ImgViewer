#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "IGraphicsView.h"
#include <QMainWindow>
#include <QPainter>
#include <QResizeEvent>

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
  private:
    Ui::MainWindow* ui;
    IGraphicsView *view_;
};
#endif // MAINWINDOW_H

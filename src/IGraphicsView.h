#ifndef IGRAPHICSVIEW_H
#define IGRAPHICSVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QSize>


class IGraphicsView : public QGraphicsView
{
  public:
    IGraphicsView(QWidget* parent = nullptr);
    void load(const QString &fileName);
    QSize pixmapSize();
  private:
    QGraphicsPixmapItem* pixmap_item_;
};

#endif // IGRAPHICSVIEW_H

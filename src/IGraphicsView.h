#ifndef IGRAPHICSVIEW_H
#define IGRAPHICSVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>


class IGraphicsView : public QGraphicsView
{
  public:
    IGraphicsView(QWidget* parent = nullptr);
    void load(const QString &fileName);

  private:
    QGraphicsPixmapItem* pixmap_item_;
};

#endif // IGRAPHICSVIEW_H

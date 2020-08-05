#include "IGraphicsView.h"
#include <QGraphicsScene>

IGraphicsView::IGraphicsView(QWidget* parent)
  : QGraphicsView(parent)
{
    // set scene
    auto* scene = new QGraphicsScene(this);
    setScene(scene);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setFrameShape(QFrame::NoFrame);
    setTransformationAnchor(QGraphicsView::NoAnchor);

    pixmap_item_ = new QGraphicsPixmapItem();
    scene->addItem(pixmap_item_);
}

void
IGraphicsView::load(const QString& fileName)
{
    QPixmap pic(fileName);
    pixmap_item_->setPixmap(pic);
    scene()->setSceneRect(0, 0, pic.width(), pic.height());
}

QSize
IGraphicsView::pixmapSize()
{
    return pixmap_item_->pixmap().size();
}

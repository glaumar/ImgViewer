#include "IGraphicsView.h"
#include <QGraphicsScene>

IGraphicsView::IGraphicsView(QWidget* parent)
  : QGraphicsView(parent)
{
    // set scene
    auto* scene = new QGraphicsScene(this);
    setScene(scene);

    // TODO: delete some unnecesarry
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setFrameShape(QFrame::NoFrame);
    setTransformationAnchor(QGraphicsView::NoAnchor);

    pixmap_item_ = new QGraphicsPixmapItem();
    scene->addItem(pixmap_item_);
}

void IGraphicsView::load(const QString &fileName) {
    //TODO: check file usability
    QPixmap pic(fileName);
    pixmap_item_->setPixmap(pic);
}

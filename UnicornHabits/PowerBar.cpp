#include "PowerBar.h"

#include <QPainter>
#include <QPaintEvent>
#include <QPainterPath>

PowerBar::PowerBar(QWidget *parent) :
    QProgressBar(parent)
{

}

void PowerBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QSize adjustedSize = this->size() - QSize(2, 2);
    QRect rect(QPoint(0,0), adjustedSize);
    painter.drawRect(rect);

    QPainterPath path;
    rect.setWidth(rect.width()*value()/maximum());
    path.addRect(rect);

    QPen pen(Qt::black, 1);
    painter.setPen(pen);
    painter.fillPath(path, QColor(255-value(), value()+120, 128));
    painter.drawPath(path);
}

#ifndef SVGWIDGET_H
#define SVGWIDGET_H

#include <QSvgWidget>

class SvgWidget : public QSvgWidget
{
    Q_OBJECT
public:
    SvgWidget(QWidget *parent = nullptr);
};

#endif // SVGWIDGET_H

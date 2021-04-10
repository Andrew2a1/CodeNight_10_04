#include "HabitWidgetContainer.h"
#include "ui_HabitWidgetContainer.h"

#include <QMenu>
#include <QContextMenuEvent>

HabitWidgetContainer::HabitWidgetContainer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HabitWidgetContainer)
{
    ui->setupUi(this);
}

HabitWidgetContainer::~HabitWidgetContainer()
{
    delete ui;
}

void HabitWidgetContainer::addHabit(std::shared_ptr<Habit> habit)
{
    HabitWidget *habitWidget = new HabitWidget(habit, this);

    connect(habitWidget, &HabitWidget::habitDone,
            this, &HabitWidgetContainer::habitFinished);

    ui->gridLayout->addWidget(habitWidget, 0, ui->gridLayout->columnCount());
    widgets.append(habitWidget);
}

void HabitWidgetContainer::clear()
{
    std::for_each(widgets.begin(), widgets.end(),
                  [](HabitWidget* widget)
    {
        widget->deleteLater();
    });

    widgets.clear();
}

void HabitWidgetContainer::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *contextMenu = new QMenu(this);
    HabitWidget* habitWidget = qobject_cast<HabitWidget*>(this->childAt(event->pos()));

    if(habitWidget)
    {
        contextMenu->addAction("Remove", this,
                               [=](){
            emit requestRemove(habitWidget->getHabit());
        });
    }

    contextMenu->popup(event->globalPos());
    QWidget::contextMenuEvent(event);
}

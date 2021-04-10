#include "HabitWidgetContainer.h"
#include "ui_HabitWidgetContainer.h"

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
            this, &HabitWidgetContainer::powerPointsAdded);

    ui->gridLayout->addWidget(habitWidget);
    widgets.append(habitWidget);
}

void HabitWidgetContainer::clear()
{
    for(const auto& widget: widgets)
        widget->deleteLater();

    widgets.clear();
}

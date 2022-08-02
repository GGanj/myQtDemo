#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->widgetBtn, &Form::getValueSignal, this, [=](){
        qDebug() << ui->widgetCustom->getValue();
    });
    connect(ui->widgetBtn, &Form::setHalfSignal, this, [=](){
       ui->widgetCustom->setHalf(50);
    });

    ui->widgetCustom->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *obj, QEvent *event) {
    if(obj == ui->widgetCustom) {
        if(event->type() == QEvent::Type::MouseButtonRelease) {
            QMouseEvent * myMouseEvent = static_cast<QMouseEvent *>(event);
            if(myMouseEvent->button() == Qt::MouseButton::RightButton) {
                qDebug() << "Event Filter for Mouse Right Button Release";
                return true;
            }
        }
    }

    return QWidget::eventFilter(obj, event);
}


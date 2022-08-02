#include "customlabel.h"
#include "ui_customlabel.h"

CustomLabel::CustomLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomLabel)
{
    ui->setupUi(this);
    void(QSpinBox::* pValueChange)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, pValueChange, ui->horizontalSlider, &QSlider::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

CustomLabel::~CustomLabel()
{
    delete ui;
}

int CustomLabel::getValue() {
    return ui->spinBox->value();
}

void CustomLabel::setHalf(int val) {
    ui->spinBox->setValue(val);
}

bool CustomLabel::event(QEvent *event) {
    if(event->type() == QEvent::Type::MouseButtonPress) {
        QMouseEvent * myMouseEvent = static_cast<QMouseEvent*>(event);
        if(myMouseEvent->button() == Qt::MouseButton::LeftButton) {
            qDebug() << "Event of Mouse Left Button Press";
            return true;
        }
    }
    return QWidget::event(event);
}

void CustomLabel::enterEvent(QEvent *event) {
    qDebug() << "Enter custome label";
}

void CustomLabel::leaveEvent(QEvent *event) {
    qDebug() << "Leave custome label";
}

void CustomLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        qDebug() << "left button pressed";
    }
    if (event->button() == Qt::MouseButton::RightButton) {
        qDebug() << "Right button pressed";
    }
    if (event->button() == Qt::MouseButton::MidButton) {
        qDebug() << "Mid button pressed";
    }
}

void CustomLabel::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        qDebug() << "left button release";
    }
    if (event->button() == Qt::MouseButton::RightButton) {
        qDebug() << "Right button release";
    }
    if (event->button() == Qt::MouseButton::MidButton) {
        qDebug() << "Mid button release";
    }
}

void CustomLabel::mouseMoveEvent(QMouseEvent *event) {
    if(event->buttons() & (Qt::MouseButton::LeftButton | Qt::MouseButton::RightButton)) {
        qDebug() << "Mouse movie x = %1 y = %2" << event->x() << event->y();
    }
}

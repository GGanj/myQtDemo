#include "custompushbtn.h"

CustomPushBtn::CustomPushBtn(QString normalImg, QString pressedImg)
{
    this->normalImgPath = normalImg;
    this->pressedImgPath = pressedImg;

    QPixmap pix;
    bool ret = pix.load(this->normalImgPath);
    if(!ret) {
        return;
    }

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton { border : 0px }");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

bool CustomPushBtn::event(QEvent *event) {
    if(this->pressedImgPath != "") {
        if(event->type() == QEvent::MouseButtonPress) {
            QMouseEvent * mEvent = static_cast<QMouseEvent*>(event);
            if(mEvent->button() == Qt::LeftButton) {
                QPixmap pix(this->pressedImgPath);
                this->setIcon(pix);
            }
        }
        if(event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent * mEvent = static_cast<QMouseEvent*>(event);
            if(mEvent->button() == Qt::LeftButton) {
                QPixmap pix(this->normalImgPath);
                this->setIcon(pix);
            }
        }
    }
    return QPushButton::event(event);
}

void CustomPushBtn::customeAnimation(bool down) {
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    if (down) {
        animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
        animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    } else {
        animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
        animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    }
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}



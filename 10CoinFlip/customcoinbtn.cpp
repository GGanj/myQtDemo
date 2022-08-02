#include "customcoinbtn.h"

CustomCoinBtn::CustomCoinBtn(bool isFront) {
    QPixmap pix;
    bool ret = false;
    this->currFrontStatus = isFront;
    if(isFront) {
        this->currIndex = 1;

    } else {
        this->currIndex = 8;
    }
    ret = pix.load(QString(":/res/Coin000%1.png").arg(this->currIndex));
    if(!ret) {
        return;
    }

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton { border : 0px }");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

CustomCoinBtn::~CustomCoinBtn()
{

}

void CustomCoinBtn::mousePressEvent(QMouseEvent *event) {
    this->coinFlip();
    QPushButton::mousePressEvent(event);
}

bool CustomCoinBtn::getCurrFrontStatus() {
    return this->currFrontStatus;
}

void CustomCoinBtn::coinFlip() {
    QTimer * qTimer = new QTimer();
    if(this->currFrontStatus) {
        connect(qTimer, &QTimer::timeout, this, [=](){
           if(this->currIndex == 8) {
               qTimer->stop();
           } else {
               this->setIcon(QPixmap(QString(":/res/Coin000%1.png").arg(++this->currIndex)));
           }
        });
        qTimer->start(50);
    } else {
        connect(qTimer, &QTimer::timeout, this, [=](){
            if(this->currIndex == 1) {
                qTimer->stop();
            } else {
                this->setIcon(QPixmap(QString(":/res/Coin000%1.png").arg(--this->currIndex)));
            }
        });
        qTimer->start(50);
    }
    this->currFrontStatus = !this->currFrontStatus;
}


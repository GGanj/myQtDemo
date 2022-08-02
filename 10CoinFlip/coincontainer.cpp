#include "coincontainer.h"

#include <QDebug>

CoinContainer::CoinContainer(int level)
{
    this->setFixedSize(200, 200);
    dataConfig data(this);
    data.mData[level];
    QSound * coinFlipSound = new QSound(":/res/ConFlipSound.wav");
    for(int i = 0; i < 16; ++i) {
       bool isFront = data.mData[level + 1][i / 4][i % 4] == 1 ? true : false;
       btnArr[i] = new CustomCoinBtn(isFront);
       btnArr[i]->setParent(this);
       btnArr[i]->setFixedSize(50, 50);
       btnArr[i]->move( (i % 4) * 50, (i / 4) * 50);
       if(btnArr[i]->getCurrFrontStatus()) {
           ++result;
       }
       connect(btnArr[i], &QPushButton::clicked, this, [=](){
           flipSurrondCoin(i);
           coinFlipSound->play();
           if(btnArr[i]->getCurrFrontStatus()) {
               ++result;
           } else {
               --result;
           }
           if(result == 16) {
               disableAllCoin();
           }
       });
    }

}

void CoinContainer::paintEvent(QPaintEvent * event) {
    QPainter painter(this);
    for(int i = 0; i < 16; ++i) {
        painter.drawPixmap((i % 4) * 50, (i / 4) * 50, 50, 50, QPixmap(":/res/BoardNode.png"));
    }
}

void CoinContainer::flipSurrondCoin(int i) {
    if(i - 4 >= 0) {
        btnArr[i - 4]->coinFlip();
        if(btnArr[i - 4]->getCurrFrontStatus()) {
            ++result;
        } else {
            --result;
        }
    }
    if(i + 4 < 16) {
        btnArr[i + 4]->coinFlip();
        if(btnArr[i + 4]->getCurrFrontStatus()) {
            ++result;
        } else {
            --result;
        }
    }
    if(i % 4 > 0) {
        btnArr[i - 1]->coinFlip();
        if(btnArr[i - 1]->getCurrFrontStatus()) {
            ++result;
        } else {
            --result;
        }
    }
    if(i % 4  < 3) {
        btnArr[i + 1]->coinFlip();
        if(btnArr[i + 1]->getCurrFrontStatus()) {
            ++result;
        } else {
            --result;
        }
    }
}

void CoinContainer::disableAllCoin() {
    for(int i = 0; i < 16; ++i) {
        btnArr[i]->setDisabled(true);
    }
    emit successedSignal();
}

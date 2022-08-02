#include "thiredwindow.h"

#include <QDebug>

Thiredwindow::Thiredwindow(int myLevel)
{
    this->currLevel = myLevel;
    this->setFixedSize(320, 588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("Second Scense");

    // menu
    QMenuBar * menuBar = new QMenuBar();
    setMenuBar(menuBar);
    QMenu * startMenu = menuBar->addMenu("Start");

    // success label
    QSound * successSound = new QSound(":/res/LevelWinSound.wav");
    QLabel *scLbl = new QLabel();
    scLbl->setParent(this);
    QPixmap pix;
    pix.load(":/res/LevelCompletedDialogBg.png");
    scLbl->setPixmap(pix);
    scLbl->setFixedSize(pix.width(), pix.height());
    scLbl->move(0.5 * (this->width() - pix.width()), -pix.height());

    // coin container
    CoinContainer * cc = new CoinContainer(this->currLevel);
    cc->setParent(this);
    cc->move(0.5 * (this->width() - cc->width()), 0.5 * (this->height() - cc->height()));
    connect(cc, &CoinContainer::successedSignal, this, [=](){
        successSound->play();
        showSuccess(scLbl);
    });

    // level label
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);

    QLabel * levelLabel = new QLabel();
    levelLabel->setParent(this);
    levelLabel->setFixedSize(150, 50);
    levelLabel->setFont(font);
    levelLabel->setText("Level: " + QString::number(this->currLevel + 1));
    levelLabel->move(30, this->height() - levelLabel->height());

    // back btn
    CustomPushBtn * myBackBtn = new CustomPushBtn(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    myBackBtn->setParent(this);
    myBackBtn->move(this->width() - myBackBtn->width(), this->height() - myBackBtn->height());
    QSound * backSound = new QSound(":/res/BackButtonSound.wav");
    connect(myBackBtn, &QPushButton::clicked, this, [=](){
        backSound->play();
        emit this->backSignal();
    });

}

void Thiredwindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPixmap pix(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    QImage img(":/res/Title.png");
    img = img.scaled(img.width() * 0.5, img.height() * 0.5);
    painter.drawImage(10, 30, img);
}

void Thiredwindow::showSuccess(QLabel * scLabel) {
    QPropertyAnimation * pAnimation = new QPropertyAnimation(scLabel, "geometry");
    pAnimation->setStartValue(QRect(scLabel->x(), scLabel->y(), scLabel->width(), scLabel->height()));
    pAnimation->setEndValue(QRect(scLabel->x(), scLabel->y() + 117, scLabel->width(), scLabel->height()));
    pAnimation->setDuration(1000);
    pAnimation->setEasingCurve(QEasingCurve::OutBounce);
    pAnimation->start();
}

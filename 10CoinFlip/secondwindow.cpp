#include "secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(320, 588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("Thired Scense");

    // menu
    QMenuBar * menuBar = new QMenuBar();
    setMenuBar(menuBar);
    QMenu * startMenu = menuBar->addMenu("Start");
    // level btn
    QSound * selectLevelSound = new QSound(":/res/TapButtonSound.wav");
    for(int i = 0; i < 20; ++i) {
        CustomPushBtn * newLevelBtn = new CustomPushBtn(":/res/LevelIcon.png");
        newLevelBtn->setParent(this);
        newLevelBtn->move(25 + 70 * (i % 4), 130 + 70 * (i / 4));
        connect(newLevelBtn, &QPushButton::clicked, this, [=](){
            thiredWindow = new Thiredwindow(i);
            QTimer::singleShot(300, [=](){
                thiredWindow->setGeometry(this->geometry());
                thiredWindow->show();
                this->hide();
            });
            selectLevelSound->play();
//            newLevelBtn->customeAnimation(true);
//            newLevelBtn->customeAnimation(false);
            connect(thiredWindow, &Thiredwindow::backSignal, this, [=](){
                QTimer::singleShot(300, [=](){
                    this->setGeometry(thiredWindow->geometry());
                    this->show();
                    thiredWindow->hide(); // necessary or crash?
                    delete thiredWindow;
                    thiredWindow = nullptr;
                });
            });
        });

        QLabel * newlevelLeb = new QLabel();
        newlevelLeb->setParent(this);
        newlevelLeb->setFixedSize(newLevelBtn->width(), newLevelBtn->height());
        newlevelLeb->setText(QString::number(i + 1));
        newlevelLeb->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        newlevelLeb->move(25 + 70 * (i % 4), 130 + 70 * (i / 4));
        newlevelLeb->setAttribute(Qt::WA_TransparentForMouseEvents);
    }


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


void SecondWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPixmap pix(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width()) * 0.5, 30, pix);
}

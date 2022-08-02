#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(320, 588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("Coin Flip: Main Scense");

    this->secondWindow = new SecondWindow(this);
    CustomPushBtn * startBtn = new CustomPushBtn(":/res/MenuSceneStartButton.png");
    QSound * startSound = new QSound(":/res/TapButtonSound.wav");
    startBtn->setParent(this);
    startBtn->move((this->width() - startBtn->width()) * 0.5, this->height() * 0.7);
    connect(startBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(300, [=](){
            secondWindow->setGeometry(this->geometry());
            this->secondWindow->show();
        });
        QTimer::singleShot(400, [=](){
            this->hide();
        });
        startBtn->customeAnimation(true);
        startBtn->customeAnimation(false);
        startSound->play();
    });

    connect(this->secondWindow, &SecondWindow::backSignal, this, [=](){
        QTimer::singleShot(100, [=](){
            this->setGeometry(secondWindow->geometry());
            this->show();
        });
        QTimer::singleShot(100, [=](){
            this->secondWindow->hide();
        });
    });
}


void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPixmap pix;
    bool ret = pix.load(":/res/PlayLevelSceneBg.png");
    if (!ret) {
        QDialog dlg(this);
        dlg.resize(300, 200);
        dlg.setWindowTitle("Error");
        QLabel lbl(&dlg);
        lbl.setText("Can not load resource");
        connect(&dlg, &QDialog::finished, this, [=](){
            this->close();
        });
        dlg.exec();
        qDebug() << "exit";
        return;
    }
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    QImage img(":/res/Title.png");
    img = img.scaled(img.width() * 0.5, img.height() * 0.5);
    painter.drawImage(10, 30, img);
}

MainWindow::~MainWindow()
{
    delete ui;
}


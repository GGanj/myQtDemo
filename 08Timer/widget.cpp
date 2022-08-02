#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer1 = startTimer(200);
    timer2 = startTimer(400);

    QTimer * qTimer1 = new QTimer();
    connect(qTimer1, &QTimer::timeout, this, [=]() {
       static int num3 = 0;
       ui->label_3->setText(QString::number(++num3));
    });
    qTimer1->start(800);
    QTimer * qTimer2 = new QTimer();
    connect(qTimer2, &QTimer::timeout, this, [=]() {
       static int num4 = 0;
       ui->label_4->setText(QString::number(++num4));
    });
    qTimer2->start(1600);


    connect(ui->btnStart, &QPushButton::clicked, this, [=](){
        timer1 = startTimer(200);
        timer2 = startTimer(400);
        qTimer1->start(800);
        qTimer2->start(1600);
    });
    connect(ui->btnStop, &QPushButton::clicked, this, [=](){
        killTimer(timer1);
        killTimer(timer2);
        qTimer1->stop();
        qTimer2->stop();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent * event) {
    static int num1 = 0, num2 = 0;
    if(event->timerId() == timer1) {
        ui->label->setText(QString::number(++num1));
    }
    if(event->timerId() == timer2) {
        ui->label_2->setText(QString::number(++num2));
    }
}


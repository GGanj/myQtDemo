#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *myPushBtn1 = new QPushButton();
//    myPushBtn1->show(); // as a new window in top layer
    myPushBtn1->setParent(this);
    myPushBtn1->setText("Push Button 1");

    QPushButton *myPushBtn2 = new QPushButton("Push Button 2", this);
    myPushBtn2->move(100, 100);
    myPushBtn2->resize(200, 100);
    setWindowTitle("my Widget 1");
    resize(600, 400);
    setFixedSize(500, 500);
    connect(myPushBtn2, &QPushButton::clicked, this, &myWidget::close);
}

myWidget::~myWidget()
{
}


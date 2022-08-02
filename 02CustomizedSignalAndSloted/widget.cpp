#include <QPushButton>
#include <QDebug>

#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton *qBtn1 = new QPushButton("Click Button 1", this);
    QPushButton *qBtn2 = new QPushButton("Click Button 2", this);
    QPushButton *qBtn3 = new QPushButton("Click Button 3", this);
    qBtn2->move(100, 0);
    qBtn3->move(200, 0);
    tch = new Teacher(this);
    stu = new Student(this);
//    connect(tch, SIGNAL(afterClass(QString)), stu, SLOT(goHome(QString)));
    void ( Teacher::*afterClass0)(void) = &Teacher::afterClass;
    void ( Student::*goHome0)(void) = &Student::goHome;
    connect(tch, afterClass0, stu, goHome0);
    connect(qBtn1, &QPushButton::clicked, this, &Widget::noticeAfterClass);

    void ( Teacher::*afterClass1)(QString) = &Teacher::afterClass;
    void ( Student::*goHome1)(QString) = &Student::goHome;
    connect(tch, afterClass1, stu, goHome1);
    connect(qBtn2, &QPushButton::clicked, tch, afterClass0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::noticeAfterClass() {
    emit tch->afterClass("aaa");
}


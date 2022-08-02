#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}



Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent * pE) {
    QPainter painter(this);
    painter.setPen(QColor(255, 0, 0));
    painter.drawLine(0, 0, 200, 200);

    painter.setPen(QColor(0, 255, 0));
    painter.drawEllipse(100, 100, 100, 100);
}


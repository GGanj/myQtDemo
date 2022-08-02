#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    connect(ui->btnGet, &QPushButton::clicked, this, &Form::getValue);
    connect(ui->btnSet, &QPushButton::clicked, this, &Form::setHalf);
}

Form::~Form()
{
    delete ui;
}

void Form::getValue() {
    emit this->getValueSignal();
}
void Form::setHalf() {
    emit this->setHalfSignal();
}

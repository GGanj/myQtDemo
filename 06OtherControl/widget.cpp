#include "widget.h"
#include "ui_widget.h"

void selectAnimal(QString str) {
    qDebug() << "select " << str.toUtf8().data();
}

void selectCheckBox(int i) {
    qDebug() << "select " << i;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initRadioBtn();
    initCheckBox();
    initComboBox();
    initListWidget();
    initTreeWidget();
    initTableWidget();
    initStackWidget();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initRadioBtn() {
    connect(ui->rBtnMan, &QRadioButton::clicked, this, [](){
        qDebug() << "select man";
    });
    connect(ui->rBtnWoman, &QRadioButton::clicked, this, [](){
        qDebug() << "Select woman";
    });
    connect(ui->rBtnCat, &QRadioButton::clicked, this, [=](){
        selectAnimal("cat");
    });
    connect(ui->rBtnDog, &QRadioButton::clicked, this, [=]() {
        selectAnimal("Dog");
    });
}

void Widget::initCheckBox() {
    connect(ui->checkBox1, &QCheckBox::stateChanged, this, [=](int index) {
       selectCheckBox(index);
    });
    connect(ui->checkBox2, &QCheckBox::stateChanged, this, [=](int index) {
       selectCheckBox(index);
    });
    connect(ui->checkBox3, &QCheckBox::stateChanged, this, [=](int index) {
       selectCheckBox(index);
    });
    connect(ui->checkBox4, &QCheckBox::stateChanged, this, [=](int index) {
       selectCheckBox(index);
    });
}

void Widget::initComboBox() {
    QStringList qStrList;
    qStrList << "item1" << "item2" << "item3" << "item4";
    ui->comboBox->addItems(qStrList);
    connect(ui->pushBtn, &QPushButton::clicked, this, [=]() {
        ui->comboBox->setCurrentIndex(1);
    });
    connect(ui->toolBtn, &QPushButton::clicked, this, [=]() {
        ui->comboBox->setCurrentIndex(2);
    });
}

void Widget::initListWidget() {
    QStringList qStrList = {"item1", "item2", "item3" , "item4"};
    ui->listWidget->addItems(qStrList);
}

void Widget::initTreeWidget() {
    QTreeWidgetItem * header = new QTreeWidgetItem();
    header->setText(0, "Parents");
    header->setText(1, "Children");
    ui->treeWidget->setHeaderItem(header);
    QTreeWidgetItem * item1 = new QTreeWidgetItem();
    item1->setText(0, "Parent0");
    QTreeWidgetItem *child00 = new QTreeWidgetItem();
    child00->setText(0, "Child00");
    QTreeWidgetItem *child01 = new QTreeWidgetItem();
    child01->setText(0, "Child01");
    child01->setText(1, "my parent is Parent0");
    QTreeWidgetItem *child02 = new QTreeWidgetItem(QStringList() << "Child02");
    item1->addChild(child00);
    item1->addChild(child01);
    item1->addChild(child02);
    ui->treeWidget->addTopLevelItem(item1);
    QTreeWidgetItem * item2 = new QTreeWidgetItem(QStringList() << "Parent1");
    QList<QTreeWidgetItem *> itemList;
    for(int i = 0; i < 4; ++i) {
        QTreeWidgetItem * newItem = new QTreeWidgetItem();
        QString qStr = "Child1" + QString::number(i);
        newItem->setText(0, qStr);
        itemList.push_back(newItem);
    }
    item2->addChildren(itemList);
    ui->treeWidget->addTopLevelItem(item2);
}

void Widget::initTableWidget() {
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setColumnWidth(0, 25);
    ui->tableWidget->setColumnWidth(1, 25);
    ui->tableWidget->setColumnWidth(2, 25);
    for(int i = 0;i < 5; ++i) {
        for(int j = 0; j < 3; ++j) {
            QTableWidgetItem * item = new QTableWidgetItem(QString(QString::number(i) + QString::number(j)));
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

void Widget::initStackWidget() {
    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->pushButton_2, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->pushButton_3, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
}





#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionNew->setIcon(QIcon(":/img/btn2.jpg"));

    connect(ui->actionNew, &QAction::triggered, this, [=](){
        QDialog * myDlg = new QDialog(this);
        myDlg->resize(300, 200);
        myDlg->exec();
    });
    connect(ui->actionOpen, &QAction::triggered, this, [=](){
        QDialog * myDlg2 = new QDialog(this);
        myDlg2->resize(300, 200);
        myDlg2->setAttribute(Qt::WA_DeleteOnClose);
        myDlg2->show();
    });

    connect(ui->actionMore, &QAction::triggered, this, [=](){
        QMessageBox::critical(this, "Critical","Error");
        QMessageBox::warning(this, "Warning","Warning");
        QMessageBox::information(this, "Information","Info");
        QMessageBox::question(this, "Question","Ques", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


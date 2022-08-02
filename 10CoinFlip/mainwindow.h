#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDialog>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <QSound>

#include "custompushbtn.h"
#include "secondwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    SecondWindow * secondWindow = nullptr;
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QSound>

#include "thiredwindow.h"
#include "custompushbtn.h"

class SecondWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SecondWindow(QWidget *parent = nullptr);

    Thiredwindow * thiredWindow = nullptr;

    void paintEvent(QPaintEvent * event);

signals:

    void backSignal();
};

#endif // SECONDWINDOW_H

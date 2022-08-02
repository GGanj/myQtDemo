#ifndef THIREDWINDOW_H
#define THIREDWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSound>

#include "custompushbtn.h"
#include "coincontainer.h"

class Thiredwindow : public QMainWindow
{
    Q_OBJECT
public:
    Thiredwindow(int myLevel);

    int currLevel;

    void paintEvent(QPaintEvent *);
    void showSuccess(QLabel * scLabel);


signals:
    void backSignal();
};

#endif // THIREDWINDOW_H

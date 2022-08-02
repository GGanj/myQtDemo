#ifndef CUSTOMCOINBTN_H
#define CUSTOMCOINBTN_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QTimer>
#include <QDebug>

namespace Ui {
class CustomCoinBtn;
}

class CustomCoinBtn : public QPushButton
{
    Q_OBJECT

public:
    explicit CustomCoinBtn(QWidget *parent = nullptr);
    CustomCoinBtn(bool isFront);
    ~CustomCoinBtn();

    bool currFrontStatus;
    int currIndex = 0;

    void mousePressEvent(QMouseEvent *event);

    void coinFlip();
    bool getCurrFrontStatus();

private:
    Ui::CustomCoinBtn *ui;
};

#endif // CUSTOMCOINBTN_H

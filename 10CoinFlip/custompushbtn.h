#ifndef CUSTOMPUSHBTN_H
#define CUSTOMPUSHBTN_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QMouseEvent>

class CustomPushBtn : public QPushButton
{
    Q_OBJECT

private:
    QString normalImgPath;
    QString pressedImgPath;
public:
    CustomPushBtn(QString normalImg, QString pressedImg = "");

    bool event(QEvent *event);
    void customeAnimation(bool down = true);
signals:

};

#endif // CUSTOMPUSHBTN_H

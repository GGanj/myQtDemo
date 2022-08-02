#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>

namespace Ui {
class CustomLabel;
}

class CustomLabel : public QWidget
{
    Q_OBJECT

public:
    explicit CustomLabel(QWidget *parent = nullptr);
    ~CustomLabel();

    int getValue();
    void setHalf(int val);

    bool event(QEvent *event);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);



private:
    Ui::CustomLabel *ui;
};

#endif // CUSTOMLABEL_H

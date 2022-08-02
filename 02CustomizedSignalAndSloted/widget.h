#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>

#include "teacher.h"
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void noticeAfterClass();

signals:
    void afterClassSignal();
private:
    Ui::Widget *ui;
    Teacher * tch;
    Student * stu;
};
#endif // WIDGET_H

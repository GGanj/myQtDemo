#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    void initRadioBtn();
    void initCheckBox();
    void initComboBox();
    void initListWidget();
    void initTreeWidget();
    void initTableWidget();
    void initStackWidget();
};
#endif // WIDGET_H

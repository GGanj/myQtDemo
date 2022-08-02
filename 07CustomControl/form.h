#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    void getValue();
    void setHalf();
signals:
    void getValueSignal();
    void setHalfSignal();

private:
    Ui::Form *ui;
};

#endif // FORM_H

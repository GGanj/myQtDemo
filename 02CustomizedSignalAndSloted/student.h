#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QDebug>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

//private slots:
    void goHome();
    void goHome(QString nextClass);

signals:

};

#endif // STUDENT_H

#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QDebug>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);
    void emitAfterClassSignal();

signals:
    void afterClass();
    void afterClass(QString nextClass);

};

#endif // TEACHER_H

#include "student.h"

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::goHome() {
    qDebug() << "student go home";
}

void Student::goHome(QString nextClass) {
    qDebug() << "can't go home, have another class: " << nextClass.toUtf8().data();
}

#include "teacher.h"

Teacher::Teacher(QObject *parent) : QObject(parent)
{

}

void Teacher::emitAfterClassSignal() {
    emit this->afterClass("bbb");
}

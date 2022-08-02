#ifndef COINCONTAINER_H
#define COINCONTAINER_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QSound>

#include "customcoinbtn.h"
#include "dataconfig.h"

class CoinContainer : public QWidget
{
    Q_OBJECT
public:
    explicit CoinContainer(int level);

    int currLevel;
    int result = 0;
    CustomCoinBtn *btnArr[16];

    void paintEvent(QPaintEvent *event);
    void flipSurrondCoin(int i);
    void disableAllCoin();
signals:
    void successedSignal();
};

#endif // COINCONTAINER_H

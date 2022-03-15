#ifndef COINHOLDER_H
#define COINHOLDER_H
#include<QString>
#include<QTimer>

class CoinHolder : public QObject
{
private:
    int balance = 0;
    int regularDelta = 10;
    int interval_ms = 1 * 5 * 1'000;
public:
    QTimer* timer;
    CoinHolder();
    ~CoinHolder();
    bool loadFromJson(QString path);
    bool saveToJson(QString path);
    void add(int val);
    void substract(int val);
    int getBallance();
    static CoinHolder* mainCoinHolder;
public slots:
      void addRegular();
};

#endif // COINHOLDER_H

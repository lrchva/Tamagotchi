#ifndef COINHOLDER_H
#define COINHOLDER_H

#include <QObject>
#include<QString>
#include<QTimer>

class CoinHolder : public QObject
{
    Q_OBJECT
public:
    explicit CoinHolder(QObject *parent = nullptr);
    QTimer* timer;
    ~CoinHolder();
    bool loadFromJson(QString path);
    bool saveToJson(QString path);
    void add(int val);
    void substract(int val);
    int getBallance();
    static CoinHolder* mainCoinHolder;

private:
    int balance = 0;
    int regularDelta = 10;
    int interval_ms = 1 * 5 * 1'000;
private slots:
      void addRegularIncome();

};

#endif // COINHOLDER_H

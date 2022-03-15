#include "coinholder.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

CoinHolder* CoinHolder::mainCoinHolder = nullptr;

CoinHolder::CoinHolder()
{
    if(!loadFromJson("D:\\\\Repos\\Al_Tama\\coinHolder.json")) throw std::exception();

    timer = new QTimer();
    timer->setInterval(this->interval_ms);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(this->addRegular()));
    timer->start();
    mainCoinHolder = this;
}
CoinHolder::~CoinHolder()
{
    saveToJson("D:\\\\Repos\\Al_Tama\\coinHolder.json");
}

bool CoinHolder::loadFromJson(QString path)
{
    QString val;
    QFile fin(path);
    if(!fin.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
    val = fin.readAll();
    fin.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject json = doc.object();
    try
    {
        this->balance = json["balance"].toDouble();
    }
    catch(std::exception e)
    {
        return false;
    }
    return true;
}
bool CoinHolder::saveToJson(QString path)
{
    QJsonObject json;
    json.insert("balance", this->balance);
    QJsonDocument doc(json);
    QFile fout(path);
    if(!fout.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    fout.write(doc.toJson());
    fout.close();
    return true;
}
void CoinHolder::addRegular()
{
    this->balance += regularDelta;
    timer->setInterval(this->interval_ms);
    timer->start();
}
void CoinHolder::add(int val)
{
    if(val < 0) throw std::invalid_argument("Negative balance delta detected!");
    this->balance += val;
}
void CoinHolder::substract(int val)
{
    if(val < 0) throw std::invalid_argument("Negative balance delta detected!");
    if(val > this->balance) throw std::invalid_argument("Too great balance delta!");
    this->balance -= val;
}
int CoinHolder::getBallance()
{
    return this->balance;
}

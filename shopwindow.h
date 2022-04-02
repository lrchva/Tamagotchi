#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QMap>
#include <QString>
#include <QPushButton>
#include "inventory.h"
#include "coinholder.h"

namespace Ui {
class ShopWindow;
}

class ShopWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShopWindow(QWidget *parent = nullptr);
    ~ShopWindow();

    void displayShop();

    Inventory shopInv{"Shop"};
    QMap< QString, QVector< QPair<QPushButton*, QString> > > shopItemButtons;
    QMap< QString, QVector< QPair<QLabel*, QString> > > labels;

private slots:
    void shopItemButtonClicked();   // todo
    void redisplayBalance();
signals:
    void itemPurchased();

private:
    Ui::ShopWindow *ui;
};

#endif // SHOPWINDOW_H

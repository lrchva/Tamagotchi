#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QMap>
#include <QString>
#include <QPushButton>
#include "inventory.h"

namespace Ui {
class ShopWindow;
}

class ShopWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShopWindow(QWidget *parent = nullptr);
    ~ShopWindow();

    void displayInventory();  // todo

    Inventory inv;
    QMap< QString, QVector< QPair<QPushButton*, QString> > > itemButtons;
    QMap< QString, QVector< QPair<QLabel*, QString> > > labels;

private slots:
    void itemButtonClicked();   // todo

private:
    Ui::ShopWindow *ui;
};

#endif // SHOPWINDOW_H

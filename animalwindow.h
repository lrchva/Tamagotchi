#ifndef ANIMALWINDOW_H
#define ANIMALWINDOW_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QString>
#include <QPushButton>
#include "shopwindow.h"
#include "inventory.h"

namespace Ui {
class AnimalWindow;
}

class AnimalWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AnimalWindow(QWidget *parent = nullptr);
    ~AnimalWindow();

    Inventory inv;
    QMap< QString, QVector<QPushButton* > > itemButtons;
    void displayInventory();

private slots:
    void on_goToShopButton_t1_clicked();

private:
    Ui::AnimalWindow *ui;
    ShopWindow* shopWindow;
};

#endif // ANIMALWINDOW_H

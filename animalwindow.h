#ifndef ANIMALWINDOW_H
#define ANIMALWINDOW_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QMap>
#include <QString>
#include <QPushButton>
#include "shopwindow.h"
#include "inventory.h"
#include <QTimer>

namespace Ui {
class AnimalWindow;
}

class AnimalWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AnimalWindow(QWidget *parent = nullptr);
    ~AnimalWindow();

    Inventory inv{"User"};
    Inventory decreaser{"User"};
    /**itemButtons["Cathegory"][index].(button* + slotName)*/
    QMap< QString, QVector< QPair<QPushButton*, QString> > > itemButtons;
    QMap< QString, QVector< QPair<QLabel*, QString> > > labels;
    QVector<QPushButton*> toShopButtons;
    void displayInventory();
    void displayAnimalChars();
    QTimer* timer;

private slots:
    void on_t1_saveButton_clicked();
    void itemButtonClicked();
    void toShopButtonClicked();
    void decreaseByTimer();

private:
    Ui::AnimalWindow *ui;
    ShopWindow* shopWindow;
};

#endif // ANIMALWINDOW_H

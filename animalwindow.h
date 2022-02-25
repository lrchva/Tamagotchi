#ifndef ANIMALWINDOW_H
#define ANIMALWINDOW_H

#include <QWidget>
#include <QVector>
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

    Inventory inv;
    QMap< QString, QVector<QPushButton* > > itemButtons;
    void displayInventory();
    void displayAnimalChars();
    QTimer* timer;

private slots:
    void on_t1_saveButton_clicked();
    void itemButtonClicked();
    void decreaseByTimer();

private:
    Ui::AnimalWindow *ui;
    ShopWindow* shopWindow;
};

#endif // ANIMALWINDOW_H

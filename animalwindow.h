#ifndef ANIMALWINDOW_H
#define ANIMALWINDOW_H

#include <QWidget>
#include "shopwindow.h"

namespace Ui {
class AnimalWindow;
}

class AnimalWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AnimalWindow(QWidget *parent = nullptr);
    ~AnimalWindow();

private slots:
    void on_goToShopButton_t1_clicked();

private:
    Ui::AnimalWindow *ui;
    ShopWindow* shopWindow;
};

#endif // ANIMALWINDOW_H

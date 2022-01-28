#include "animalwindow.h"
#include "ui_animalwindow.h"
#include "inventory.h"
#include <QMessageBox>
#include <QLabel>

AnimalWindow::AnimalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimalWindow)
{
    ui->setupUi(this);
    shopWindow = new ShopWindow();
    Inventory inv;
    if(inv.fillFromJson("D:\\\\Repos\\Qt\\Tamagcji_2_0\\Items.json"))
    {
        QString message = "";
        message += QString::number(inv.atFood("Whiskas").restoringPower) + " ";
        message += QString::number(inv.atFood("Kitekat").restoringPower) + " ";
        message += QString::number(inv.atFood("Purina").restoringPower) + " ";
        QMessageBox::information(this, "Title", "Loading successfull\n" + message);
    }
    else
    {
        QMessageBox::critical(this, "Title", "Loading NOT successfull");
    }
}

AnimalWindow::~AnimalWindow()
{
    delete ui;
}

void AnimalWindow::on_goToShopButton_t1_clicked()
{
    shopWindow->show();
}


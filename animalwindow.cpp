#include "animalwindow.h"
#include "ui_animalwindow.h"
#include <QMessageBox>
#include <QLabel>


void AnimalWindow::displayInventory()
{
    for(size_t i = inv.size("food"); i < itemButtons["food"].size(); i++)
    {
        itemButtons["food"][i]->setEnabled(false);
        itemButtons["food"][i]->setVisible(false);
    }
    size_t k = 0;
    for(size_t i = 0; i < inv.size("all"); i++)
    {
        if(inv[i].item->type == Misc::typeEnum::FOOD)
        {
            itemButtons["food"][k]->setIcon(QIcon(inv[i].pathToSkin));
            k++;
        }
        //Repeat for wash, walk, pet, sleep
    }
}

AnimalWindow::AnimalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimalWindow)
{
    ui->setupUi(this);
    shopWindow = new ShopWindow();
    if(inv.loadFromJson("D:\\\\Repos\\Al_Tama\\Items.json"))
    {
        QMessageBox::information(this, "Title", "Loading successfull");
    }
    else
    {
        QMessageBox::critical(this, "Title", "Loading failed");
    }
    itemButtons["food"] =
    {
            ui->t1_itemButton_0, ui->t1_itemButton_1, ui->t1_itemButton_2, ui->t1_itemButton_3, ui->t1_itemButton_4, ui->t1_itemButton_5,
            ui->t1_itemButton_6, ui->t1_itemButton_7, ui->t1_itemButton_8, ui->t1_itemButton_9, ui->t1_itemButton_10,
            ui->t1_itemButton_11, ui->t1_itemButton_12, ui->t1_itemButton_13, ui->t1_itemButton_14, ui->t1_itemButton_15,
            ui->t1_itemButton_16, ui->t1_itemButton_17, ui->t1_itemButton_18
    };
    //Repeat for wash, walk, pet, sleep
    displayInventory();
}

AnimalWindow::~AnimalWindow()
{
    delete ui;
}

void AnimalWindow::on_goToShopButton_t1_clicked()
{
    shopWindow->show();
}

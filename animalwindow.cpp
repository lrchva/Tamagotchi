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
    for(size_t i = inv.size("wash"); i < itemButtons["wash"].size(); i++)
    {
        itemButtons["wash"][i]->setEnabled(false);
        itemButtons["wash"][i]->setVisible(false);
    }
    for(size_t i = inv.size("walk"); i < itemButtons["walk"].size(); i++)
    {
        itemButtons["walk"][i]->setEnabled(false);
        itemButtons["walk"][i]->setVisible(false);
    }
    for(size_t i = inv.size("sleep"); i < itemButtons["sleep"].size(); i++)
    {
        itemButtons["sleep"][i]->setEnabled(false);
        itemButtons["sleep"][i]->setVisible(false);
    }
    for(size_t i = inv.size("pet"); i < itemButtons["pet"].size(); i++)
    {
        itemButtons["pet"][i]->setEnabled(false);
        itemButtons["pet"][i]->setVisible(false);
    }
    size_t k1 = 0;
    size_t k2 = 0;
    size_t k3 = 0;
    size_t k4 = 0;
    size_t k5 = 0;
    for(size_t i = 0; i < inv.size("all"); i++)
    {
        if(inv[i].item->type == Misc::typeEnum::FOOD)
        {
            itemButtons["food"][k1]->setIcon(QIcon(inv[i].pathToSkin));
            k1++;
        }
        if(inv[i].item->type == Misc::typeEnum::WASH)
        {
            itemButtons["wash"][k2]->setIcon(QIcon(inv[i].pathToSkin));
            k2++;
        }
        if(inv[i].item->type == Misc::typeEnum::WALK)
        {
            itemButtons["walk"][k3]->setIcon(QIcon(inv[i].pathToSkin));
            k3++;
        }
        if(inv[i].item->type == Misc::typeEnum::SLEEP)
        {
            itemButtons["sleep"][k4]->setIcon(QIcon(inv[i].pathToSkin));
            k4++;
        }
        if(inv[i].item->type == Misc::typeEnum::PET)
        {
            itemButtons["pet"][k5]->setIcon(QIcon(inv[i].pathToSkin));
            k5++;
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
    if(inv.loadFromJson("C:\\Users\\user\\Desktop\\Tamagotchi\\Items.json"))
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
    itemButtons["wash"] =
    {
            ui->t2_itemButton_1, ui->t2_itemButton_2, ui->t2_itemButton_3, ui->t2_itemButton_4, ui->t2_itemButton_9, ui->t2_itemButton_10,
            ui->t2_itemButton_11, ui->t2_itemButton_12, ui->t2_itemButton_13, ui->t2_itemButton_14, ui->t2_itemButton_15, ui->t2_itemButton_16,
            ui->t2_itemButton_17, ui->t2_itemButton_18, ui->t2_itemButton_19, ui->t2_itemButton_20, ui->t2_itemButton_21, ui->t2_itemButton_22,
            ui->t2_itemButton_23
    };
    itemButtons["walk"] =
    {
            ui->t3_itemButton_1, ui->t3_itemButton_2, ui->t3_itemButton_3, ui->t3_itemButton_4, ui->t3_itemButton_5,
            ui->t3_itemButton_6, ui->t3_itemButton_7, ui->t3_itemButton_8, ui->t3_itemButton_9, ui->t3_itemButton_10,
            ui->t3_itemButton_11, ui->t3_itemButton_12, ui->t3_itemButton_13, ui->t3_itemButton_14, ui->t3_itemButton_15,
            ui->t3_itemButton_16, ui->t3_itemButton_17, ui->t3_itemButton_18, ui->t3_itemButton_19
    };
    itemButtons["sleep"] =
    {
            ui->t4_itemButton_1, ui->t4_itemButton_2, ui->t4_itemButton_3, ui->t4_itemButton_4, ui->t4_itemButton_5,
            ui->t4_itemButton_6, ui->t4_itemButton_7, ui->t4_itemButton_8, ui->t4_itemButton_9, ui->t4_itemButton_10,
            ui->t4_itemButton_11, ui->t4_itemButton_12, ui->t4_itemButton_13, ui->t4_itemButton_14, ui->t4_itemButton_15,
            ui->t4_itemButton_16, ui->t4_itemButton_17, ui->t4_itemButton_18, ui->t4_itemButton_19
    };
    itemButtons["pet"] =
    {
            ui->t5_itemButton_1, ui->t5_itemButton_2, ui->t5_itemButton_3, ui->t5_itemButton_4, ui->t5_itemButton_5,
            ui->t5_itemButton_6, ui->t5_itemButton_7, ui->t5_itemButton_8, ui->t5_itemButton_9, ui->t5_itemButton_10,
            ui->t5_itemButton_11, ui->t5_itemButton_12, ui->t5_itemButton_13, ui->t5_itemButton_14, ui->t5_itemButton_15,
            ui->t5_itemButton_16, ui->t5_itemButton_17, ui->t5_itemButton_18, ui->t5_itemButton_19
    };
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

#include "animalwindow.h"
#include "ui_animalwindow.h"
#include "animal.h"
#include <QMessageBox>
#include <QLabel>


void AnimalWindow::displayInventory()
{
    for(size_t i = inv.size("food"); i < itemButtons["food"].size(); i++)
    {
        itemButtons["food"][i].first->setEnabled(false);
        itemButtons["food"][i].first->setVisible(false);
    }
    for(size_t i = inv.size("wash"); i < itemButtons["wash"].size(); i++)
    {
        itemButtons["wash"][i].first->setEnabled(false);
        itemButtons["wash"][i].first->setVisible(false);
    }
    for(size_t i = inv.size("walk"); i < itemButtons["walk"].size(); i++)
    {
        itemButtons["walk"][i].first->setEnabled(false);
        itemButtons["walk"][i].first->setVisible(false);
    }
    for(size_t i = inv.size("sleep"); i < itemButtons["sleep"].size(); i++)
    {
        itemButtons["sleep"][i].first->setEnabled(false);
        itemButtons["sleep"][i].first->setVisible(false);
    }
    for(size_t i = inv.size("pet"); i < itemButtons["pet"].size(); i++)
    {
        itemButtons["pet"][i].first->setEnabled(false);
        itemButtons["pet"][i].first->setVisible(false);
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
            itemButtons["food"][k1].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["food"][k1].second = inv[i].item->name;
            k1++;
        }
        if(inv[i].item->type == Misc::typeEnum::WASH)
        {
            itemButtons["wash"][k2].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["wash"][k2].second = inv[i].item->name;
            k2++;
        }
        if(inv[i].item->type == Misc::typeEnum::WALK)
        {
            itemButtons["walk"][k3].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["walk"][k3].second = inv[i].item->name;
            k3++;
        }
        if(inv[i].item->type == Misc::typeEnum::SLEEP)
        {
            itemButtons["sleep"][k4].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["sleep"][k4].second = inv[i].item->name;
            k4++;
        }
        if(inv[i].item->type == Misc::typeEnum::PET)
        {
            itemButtons["pet"][k5].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["pet"][k5].second = inv[i].item->name;
            k5++;
        }
    }
}
void AnimalWindow::displayAnimalChars()
{
    //REDO
    ui->tabWidget->setTabText(0, Animal::storage[0].name);
    ui->Hunger_PB->setFixedWidth(ui->Hunger_PB->baseSize().width() *
    ((double)Animal::storage[0].chars["hunger_current"]/Animal::storage[0].chars["hunger_max"]));
    ui->Wash_PB->setFixedWidth(ui->Wash_PB->baseSize().width() *
    ((double)Animal::storage[0].chars["wash_current"]/Animal::storage[0].chars["wash_max"]));
    ui->Walk_PB->setFixedWidth(ui->Walk_PB->baseSize().width() *
    ((double)Animal::storage[0].chars["walk_current"]/Animal::storage[0].chars["walk_max"]));
    ui->Pet_PB->setFixedWidth(ui->Pet_PB->baseSize().width() *
    ((double)Animal::storage[0].chars["pet_current"]/Animal::storage[0].chars["pet_max"]));
    ui->Sleep_PB->setFixedWidth(ui->Sleep_PB->baseSize().width() *
    ((double)Animal::storage[0].chars["sleep_current"]/Animal::storage[0].chars["sleep_max"]));
}

void AnimalWindow::itemButtonClicked()
{
    QString cathegory = "";
    if(sender()->objectName().startsWith("t1")) cathegory = "food";
    if(sender()->objectName().startsWith("t2")) cathegory = "wash";
    if(sender()->objectName().startsWith("t3")) cathegory = "walk";
    if(sender()->objectName().startsWith("t4")) cathegory = "pet";
    if(sender()->objectName().startsWith("t5")) cathegory = "sleep";
    if(cathegory == "") return;
    for(auto cur : itemButtons[cathegory])
    {
        if(cur.first->objectName() == sender()->objectName())
        {
            inv.removeItem(cur.second, 1);
            Animal::storage[ui->tabWidget->currentIndex()].takeEffects(*(inv[cur.second].item));
            displayAnimalChars();
            displayInventory();
            return;
        }
    }

}

void AnimalWindow::decreaseByTimer()
{
    for(int i = 0; i < inv.size("all"); i++)
    {
        if(inv[i].item->type == Misc::typeEnum::FOOD)
        {
            Animal::storage[0].takeEffects(*(inv[i].item));
            break;
        }
    }
    displayAnimalChars();

    this->timer->setInterval(5'000);
    this->timer->start();
}

AnimalWindow::AnimalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimalWindow)
{
    ui->setupUi(this);
    shopWindow = new ShopWindow();
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(decreaseByTimer()));
    timer->setInterval(5'000);
    timer->start();

    itemButtons["food"] =
    {
            QPair<QPushButton*, QString>(ui->t1_itemButton_0, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_1, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_2, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_3, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_4, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_5, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_6, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_7, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_8, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_9, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_10, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_11, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_12, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_13, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_14, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_15, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_16, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_17, ""),
            QPair<QPushButton*, QString>(ui->t1_itemButton_18, "")

    };
    itemButtons["wash"] =
    {
            QPair<QPushButton*, QString>(ui->t2_itemButton_1, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_2, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_3, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_4, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_9, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_10, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_11, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_12, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_13, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_14, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_15, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_16, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_17, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_18, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_19, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_20, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_21, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_22, ""),
            QPair<QPushButton*, QString>(ui->t2_itemButton_23, "")

    };
    itemButtons["walk"] =
    {
            QPair<QPushButton*, QString>(ui->t3_itemButton_1, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_2, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_3, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_4, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_5, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_6, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_7, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_8, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_9, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_10, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_11, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_12, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_13, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_14, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_15, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_16, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_17, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_18, ""),
            QPair<QPushButton*, QString>(ui->t3_itemButton_19, "")

    };
    itemButtons["sleep"] =
    {
            QPair<QPushButton*, QString>(ui->t4_itemButton_1, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_2, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_3, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_4, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_5, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_6, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_7, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_8, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_9, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_10, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_11, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_12, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_13, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_14, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_15, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_16, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_17, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_18, ""),
            QPair<QPushButton*, QString>(ui->t4_itemButton_19, "")
    };
    itemButtons["pet"] =
    {
            QPair<QPushButton*, QString>(ui->t5_itemButton_1, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_2, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_3, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_4, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_5, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_6, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_7, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_8, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_9, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_10, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_11, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_12, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_13, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_14, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_15, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_16, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_17, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_18, ""),
            QPair<QPushButton*, QString>(ui->t5_itemButton_19, "")
    };

    for(auto cathegory : itemButtons)
    {
        for(auto cur : cathegory)
        {
            QObject::connect(cur.first, SIGNAL(clicked()), this, SLOT(itemButtonClicked()));
        }
    }

    if(inv.loadFromJson("D:\\\\Repos\\Al_Tama\\Items.json"))
    {
        QMessageBox::information(this, "Title", "Inventory loading successfull");
        displayInventory();
    }
    else
    {
        QMessageBox::critical(this, "Title", "Inventory loading failed");
    }

    if(Animal::loadFromJson("D:\\\\Repos\\Al_Tama\\Animals.json"))
    {
        QMessageBox::information(this, "Title", "Animal loading successfull");
        displayAnimalChars();
    }
    else
    {
         QMessageBox::critical(this, "Title", "Animal loading failed");
    }
}

AnimalWindow::~AnimalWindow()
{
    delete ui;
}

void AnimalWindow::on_t1_saveButton_clicked()
{
    if(inv.saveToJson("Items.json"))
    {
         QMessageBox::information(this, "Title", "Inventory saving successfull");
    }
    else
    {
         QMessageBox::critical(this, "Title", "Inventory saving failed");
    }
    if(Animal::saveToJson("Animals.json"))
    {
         QMessageBox::information(this, "Title", "Animals set saving successfull");
    }
    else
    {
         QMessageBox::critical(this, "Title", "Animals set saving failed");
    }
}


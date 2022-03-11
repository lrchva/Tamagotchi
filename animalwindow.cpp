#include "animalwindow.h"
#include "ui_animalwindow.h"
#include "animal.h"
#include <QMessageBox>
#include <QLabel>
#include <QMap>
#include <QPair>


void AnimalWindow::toShopButtonClicked()
{
    shopWindow = new ShopWindow();
    shopWindow->show();
}

void AnimalWindow::displayInventory()
{
    for(size_t i = inv.size("food"); i < itemButtons["food"].size(); i++)
    {
        itemButtons["food"][i].first->setEnabled(false);
        itemButtons["food"][i].first->setVisible(false);
        labels["food"][i].first->setVisible(false);
    }
    for(size_t i = inv.size("wash"); i < itemButtons["wash"].size(); i++)
    {
        itemButtons["wash"][i].first->setEnabled(false);
        itemButtons["wash"][i].first->setVisible(false);
        labels["wash"][i].first->setVisible(false);
    }
    for(size_t i = inv.size("walk"); i < itemButtons["walk"].size(); i++)
    {
        itemButtons["walk"][i].first->setEnabled(false);
        itemButtons["walk"][i].first->setVisible(false);
        labels["walk"][i].first->setVisible(false);
    }
    for(size_t i = inv.size("sleep"); i < itemButtons["sleep"].size(); i++)
    {
        itemButtons["sleep"][i].first->setEnabled(false);
        itemButtons["sleep"][i].first->setVisible(false);
        labels["sleep"][i].first->setVisible(false);
    }
    for(size_t i = inv.size("pet"); i < itemButtons["pet"].size(); i++)
    {
        itemButtons["pet"][i].first->setEnabled(false);
        itemButtons["pet"][i].first->setVisible(false);
        labels["pet"][i].first->setVisible(false);
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
            //TODO: to the rest
            labels["food"][k1].first->setText(QString::number(inv[i].count));
            k1++;
        }
        if(inv[i].item->type == Misc::typeEnum::WASH)
        {
            itemButtons["wash"][k2].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["wash"][k2].second = inv[i].item->name;
            labels["wash"][k2].first->setText(QString::number(inv[i].count));
            k2++;
        }
        if(inv[i].item->type == Misc::typeEnum::WALK)
        {
            itemButtons["walk"][k3].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["walk"][k3].second = inv[i].item->name;
            labels["walk"][k3].first->setText(QString::number(inv[i].count));
            k3++;
        }
        if(inv[i].item->type == Misc::typeEnum::SLEEP)
        {
            itemButtons["sleep"][k4].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["sleep"][k4].second = inv[i].item->name;
            labels["sleep"][k4].first->setText(QString::number(inv[i].count));
            k4++;
        }
        if(inv[i].item->type == Misc::typeEnum::PET)
        {
            itemButtons["pet"][k5].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["pet"][k5].second = inv[i].item->name;
            labels["pet"][k5].first->setText(QString::number(inv[i].count));
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
    for(int index = 0; index <= itemButtons[cathegory].size(); index++)
    {
        QPair<QPushButton*, QString>& cur = itemButtons[cathegory][index];
        if(cur.first->objectName() == sender()->objectName())
        {
            Animal::storage[ui->tabWidget->currentIndex()].takeEffects(*(inv[cur.second].item));
            if(inv[cur.second].count == 1)
            {
                cur.first->setEnabled(false);
                cur.first->setVisible(false);
                labels[cathegory][index].first->setEnabled(false);
                inv.removeItem(cur.second, 1);
                cur.second = "";
            }
            else inv.removeItem(cur.second, 1);
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

    toShopButtons = {ui->t1_goToShopButton,
                     ui->t2_goToShopButton,
                     ui->t3_goToShopButton,
                     ui->t4_goToShopButton,
                     ui->t5_goToShopButton};

    labels["food"] =
    {
            QPair<QLabel*, QString>(ui->t1_label_1, ""),
            QPair<QLabel*, QString>(ui->t1_label_2, ""),
            QPair<QLabel*, QString>(ui->t1_label_3, ""),
            QPair<QLabel*, QString>(ui->t1_label_4, ""),
            QPair<QLabel*, QString>(ui->t1_label_5, ""),
            QPair<QLabel*, QString>(ui->t1_label_6, ""),
            QPair<QLabel*, QString>(ui->t1_label_7, ""),
            QPair<QLabel*, QString>(ui->t1_label_8, ""),
            QPair<QLabel*, QString>(ui->t1_label_9, ""),
            QPair<QLabel*, QString>(ui->t1_label_10, ""),
            QPair<QLabel*, QString>(ui->t1_label_11, ""),
            QPair<QLabel*, QString>(ui->t1_label_12, ""),
            QPair<QLabel*, QString>(ui->t1_label_13, ""),
            QPair<QLabel*, QString>(ui->t1_label_14, ""),
            QPair<QLabel*, QString>(ui->t1_label_15, ""),
            QPair<QLabel*, QString>(ui->t1_label_16, ""),
            QPair<QLabel*, QString>(ui->t1_label_17, ""),
            QPair<QLabel*, QString>(ui->t1_label_18, ""),
            QPair<QLabel*, QString>(ui->t1_label_19, "")
    };
    labels["wash"] =
    {
            QPair<QLabel*, QString>(ui->t2_label_1, ""),
            QPair<QLabel*, QString>(ui->t2_label_2, ""),
            QPair<QLabel*, QString>(ui->t2_label_3, ""),
            QPair<QLabel*, QString>(ui->t2_label_4, ""),
            QPair<QLabel*, QString>(ui->t2_label_5, ""),
            QPair<QLabel*, QString>(ui->t2_label_6, ""),
            QPair<QLabel*, QString>(ui->t2_label_7, ""),
            QPair<QLabel*, QString>(ui->t2_label_8, ""),
            QPair<QLabel*, QString>(ui->t2_label_9, ""),
            QPair<QLabel*, QString>(ui->t2_label_10, ""),
            QPair<QLabel*, QString>(ui->t2_label_11, ""),
            QPair<QLabel*, QString>(ui->t2_label_12, ""),
            QPair<QLabel*, QString>(ui->t2_label_13, ""),
            QPair<QLabel*, QString>(ui->t2_label_14, ""),
            QPair<QLabel*, QString>(ui->t2_label_15, ""),
            QPair<QLabel*, QString>(ui->t2_label_16, ""),
            QPair<QLabel*, QString>(ui->t2_label_17, ""),
            QPair<QLabel*, QString>(ui->t2_label_18, ""),
            QPair<QLabel*, QString>(ui->t2_label_19, "")
    };
    labels["walk"] =
    {
            QPair<QLabel*, QString>(ui->t3_label_1, ""),
            QPair<QLabel*, QString>(ui->t3_label_2, ""),
            QPair<QLabel*, QString>(ui->t3_label_3, ""),
            QPair<QLabel*, QString>(ui->t3_label_4, ""),
            QPair<QLabel*, QString>(ui->t3_label_5, ""),
            QPair<QLabel*, QString>(ui->t3_label_6, ""),
            QPair<QLabel*, QString>(ui->t3_label_7, ""),
            QPair<QLabel*, QString>(ui->t3_label_8, ""),
            QPair<QLabel*, QString>(ui->t3_label_9, ""),
            QPair<QLabel*, QString>(ui->t3_label_10, ""),
            QPair<QLabel*, QString>(ui->t3_label_11, ""),
            QPair<QLabel*, QString>(ui->t3_label_12, ""),
            QPair<QLabel*, QString>(ui->t3_label_13, ""),
            QPair<QLabel*, QString>(ui->t3_label_14, ""),
            QPair<QLabel*, QString>(ui->t3_label_15, ""),
            QPair<QLabel*, QString>(ui->t3_label_16, ""),
            QPair<QLabel*, QString>(ui->t3_label_17, ""),
            QPair<QLabel*, QString>(ui->t3_label_18, ""),
            QPair<QLabel*, QString>(ui->t3_label_19, "")
    };
    labels["sleep"] =
    {
            QPair<QLabel*, QString>(ui->t4_label_1, ""),
            QPair<QLabel*, QString>(ui->t4_label_2, ""),
            QPair<QLabel*, QString>(ui->t4_label_3, ""),
            QPair<QLabel*, QString>(ui->t4_label_4, ""),
            QPair<QLabel*, QString>(ui->t4_label_5, ""),
            QPair<QLabel*, QString>(ui->t4_label_6, ""),
            QPair<QLabel*, QString>(ui->t4_label_7, ""),
            QPair<QLabel*, QString>(ui->t4_label_8, ""),
            QPair<QLabel*, QString>(ui->t4_label_9, ""),
            QPair<QLabel*, QString>(ui->t4_label_10, ""),
            QPair<QLabel*, QString>(ui->t4_label_11, ""),
            QPair<QLabel*, QString>(ui->t4_label_12, ""),
            QPair<QLabel*, QString>(ui->t4_label_13, ""),
            QPair<QLabel*, QString>(ui->t4_label_14, ""),
            QPair<QLabel*, QString>(ui->t4_label_15, ""),
            QPair<QLabel*, QString>(ui->t4_label_16, ""),
            QPair<QLabel*, QString>(ui->t4_label_17, ""),
            QPair<QLabel*, QString>(ui->t4_label_18, ""),
            QPair<QLabel*, QString>(ui->t4_label_19, "")
    };
    labels["pet"] =
    {
            QPair<QLabel*, QString>(ui->t5_label_1, ""),
            QPair<QLabel*, QString>(ui->t5_label_2, ""),
            QPair<QLabel*, QString>(ui->t5_label_3, ""),
            QPair<QLabel*, QString>(ui->t5_label_4, ""),
            QPair<QLabel*, QString>(ui->t5_label_5, ""),
            QPair<QLabel*, QString>(ui->t5_label_6, ""),
            QPair<QLabel*, QString>(ui->t5_label_7, ""),
            QPair<QLabel*, QString>(ui->t5_label_8, ""),
            QPair<QLabel*, QString>(ui->t5_label_9, ""),
            QPair<QLabel*, QString>(ui->t5_label_10, ""),
            QPair<QLabel*, QString>(ui->t5_label_11, ""),
            QPair<QLabel*, QString>(ui->t5_label_12, ""),
            QPair<QLabel*, QString>(ui->t5_label_13, ""),
            QPair<QLabel*, QString>(ui->t5_label_14, ""),
            QPair<QLabel*, QString>(ui->t5_label_15, ""),
            QPair<QLabel*, QString>(ui->t5_label_16, ""),
            QPair<QLabel*, QString>(ui->t5_label_17, ""),
            QPair<QLabel*, QString>(ui->t5_label_18, ""),
            QPair<QLabel*, QString>(ui->t5_label_19, "")
    };
    for(auto cathegory : itemButtons)
    {
        for(auto cur : cathegory)
        {
            QObject::connect(cur.first, SIGNAL(clicked()), this, SLOT(itemButtonClicked()));
        }
    }
    for(auto cur : toShopButtons)
    {
        QObject::connect(cur, SIGNAL(clicked()), this, SLOT(toShopButtonClicked()));
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


#include "shopwindow.h"
#include "ui_shopwindow.h"

ShopWindow::ShopWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopWindow)
{
    ui->setupUi(this);
    itemButtons["food"] =
    {
            QPair<QPushButton*, QString>(ui->t1_ShopButton_1, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_2, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_3, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_4, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_5, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_6, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_7, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_8, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_9, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_10, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_11, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_12, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_13, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_14, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_15, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_16, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_17, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_18, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_19, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_20, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_21, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_22, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_23, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_24, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_25, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_26, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_27, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_28, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_29, ""),
            QPair<QPushButton*, QString>(ui->t1_ShopButton_30, "")};
    itemButtons["walk"] =
    {
            QPair<QPushButton*, QString>(ui->t2_ShopButton_1, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_2, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_3, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_4, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_5, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_6, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_7, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_8, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_9, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_10, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_11, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_12, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_13, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_14, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_15, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_16, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_17, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_18, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_19, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_20, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_21, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_22, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_23, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_24, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_25, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_26, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_27, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_28, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_29, ""),
            QPair<QPushButton*, QString>(ui->t2_ShopButton_30, "")
    };
    itemButtons["wash"] =
    {
            QPair<QPushButton*, QString>(ui->t3_ShopButton_1, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_2, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_3, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_4, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_5, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_6, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_7, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_8, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_9, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_10, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_11, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_12, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_13, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_14, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_15, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_16, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_17, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_18, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_19, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_20, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_21, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_22, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_23, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_24, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_25, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_26, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_27, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_28, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_29, ""),
            QPair<QPushButton*, QString>(ui->t3_ShopButton_30, "")
    };
    itemButtons["sleep"] =
    {
            QPair<QPushButton*, QString>(ui->t4_ShopButton_1, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_2, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_3, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_4, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_5, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_6, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_7, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_8, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_9, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_10, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_11, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_12, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_13, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_14, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_15, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_16, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_17, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_18, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_19, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_20, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_21, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_22, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_23, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_24, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_25, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_26, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_27, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_28, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_29, ""),
            QPair<QPushButton*, QString>(ui->t4_ShopButton_30, "")
    };
    itemButtons["pet"] =
    {
            QPair<QPushButton*, QString>(ui->t5_ShopButton_1, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_2, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_3, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_4, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_5, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_6, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_7, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_8, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_9, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_10, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_11, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_12, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_13, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_14, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_15, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_16, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_17, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_18, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_19, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_20, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_21, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_22, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_23, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_24, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_25, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_26, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_27, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_28, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_29, ""),
            QPair<QPushButton*, QString>(ui->t5_ShopButton_30, "")
    };
    for(auto cathegory : itemButtons)
    {
        for(auto cur : cathegory)
        {
            QObject::connect(cur.first, SIGNAL(clicked()), this, SLOT(itemButtonClicked()));
        }
    }
    labels["food"] =
    {
            QPair<QLabel*, QString>(ui->t1_ShopLabel_1, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_2, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_3, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_4, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_5, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_6, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_7, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_8, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_9, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_10, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_11, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_12, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_13, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_14, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_15, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_16, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_17, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_18, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_19, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_20, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_21, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_22, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_23, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_24, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_25, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_26, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_27, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_28, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_29, ""),
            QPair<QLabel*, QString>(ui->t1_ShopLabel_30, ""),
    };
    labels["walk"] =
    {
            QPair<QLabel*, QString>(ui->t2_ShopLabel_1, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_2, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_3, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_4, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_5, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_6, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_7, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_8, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_9, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_10, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_11, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_12, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_13, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_14, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_15, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_16, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_17, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_18, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_19, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_20, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_21, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_22, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_23, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_24, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_25, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_26, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_27, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_28, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_29, ""),
            QPair<QLabel*, QString>(ui->t2_ShopLabel_30, ""),
    };
    labels["wash"] =
    {
            QPair<QLabel*, QString>(ui->t3_ShopLabel_1, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_2, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_3, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_4, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_5, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_6, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_7, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_8, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_9, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_10, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_11, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_12, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_13, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_14, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_15, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_16, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_17, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_18, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_19, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_20, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_21, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_22, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_23, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_24, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_25, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_26, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_27, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_28, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_29, ""),
            QPair<QLabel*, QString>(ui->t3_ShopLabel_30, ""),
    };
    labels["sleep"] =
    {
            QPair<QLabel*, QString>(ui->t4_ShopLabel_1, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_2, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_3, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_4, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_5, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_6, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_7, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_8, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_9, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_10, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_11, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_12, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_13, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_14, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_15, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_16, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_17, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_18, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_19, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_20, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_21, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_22, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_23, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_24, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_25, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_26, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_27, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_28, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_29, ""),
            QPair<QLabel*, QString>(ui->t4_ShopLabel_30, ""),
    };
    labels["pet"] =
    {
            QPair<QLabel*, QString>(ui->t5_ShopLabel_1, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_2, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_3, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_4, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_5, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_6, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_7, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_8, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_9, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_10, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_11, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_12, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_13, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_14, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_15, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_16, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_17, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_18, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_19, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_20, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_21, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_22, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_23, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_24, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_25, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_26, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_27, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_28, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_29, ""),
            QPair<QLabel*, QString>(ui->t5_ShopLabel_30, ""),
    };

}

void ShopWindow::displayInventory()
{
    for(size_t i = inv.size("food"); i < itemButtons["food"].size(); i++)
    {
        itemButtons["food"][i].first->setEnabled(false);
        itemButtons["food"][i].first->setVisible(false);
        labels["food"][i].first->setVisible(false);
    }
    for(size_t i = inv.size("walk"); i < itemButtons["walk"].size(); i++)
    {
        itemButtons["walk"][i].first->setEnabled(false);
        itemButtons["walk"][i].first->setVisible(false);
        labels["wash"][i].first->setVisible(false);
    }
    for(size_t i = inv.size("wash"); i < itemButtons["wash"].size(); i++)
    {
        itemButtons["wash"][i].first->setEnabled(false);
        itemButtons["wash"][i].first->setVisible(false);
        labels["wash"][i].first->setVisible(false);
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
        if(inv[i].item->type == Misc::typeEnum::WALK)
        {
            itemButtons["walk"][k2].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["walk"][k2].second = inv[i].item->name;
            labels["walk"][k2].first->setText(QString::number(inv[i].count));
            k2++;
        }
        if(inv[i].item->type == Misc::typeEnum::WASH)
        {
            itemButtons["wash"][k3].first->setIcon(QIcon(inv[i].pathToSkin));
            itemButtons["wash"][k3].second = inv[i].item->name;
            labels["wash"][k3].first->setText(QString::number(inv[i].count));
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


ShopWindow::~ShopWindow()
{
    delete ui;
}

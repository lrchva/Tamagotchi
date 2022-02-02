#include "animalwindow.h"
#include "ui_animalwindow.h"
#include "inventory.h"
#include <QMessageBox>
#include <QLabel>
#include <QIcon>

AnimalWindow::AnimalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimalWindow)
{
    ui->setupUi(this);
    shopWindow = new ShopWindow();
    Inventory inv;
    if(inv.fillFromJson("D:\\\\Repos\\Al_Tama\\Items.json"))
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
    foodButtons = {ui->foodButton_1, ui->foodButton_2, ui->foodButton_3, ui->foodButton_4, ui->foodButton_5,
                   ui->foodButton_6, ui->foodButton_7, ui->foodButton_8, ui->foodButton_9, ui->foodButton_10,
                  ui->foodButton_11, ui->foodButton_12, ui->foodButton_13, ui->foodButton_14, ui->foodButton_15,
                  ui->foodButton_16, ui->foodButton_17, ui->foodButton_18, ui->foodButton_19};
    washMiscButtons = {ui->washMisc_button_1, ui->washMisc_button_2, ui->washMisc_button_3, ui->washMisc_button_4, ui->washMisc_button_5,
                   ui->washMisc_button_6, ui->washMisc_button_7, ui->washMisc_button_8, ui->washMisc_button_9, ui->washMisc_button_10,
                  ui->washMisc_button_11, ui->washMisc_button_12, ui->washMisc_button_13, ui->washMisc_button_14, ui->washMisc_button_15,
                  ui->washMisc_button_16, ui->washMisc_button_17, ui->washMisc_button_18, ui->washMisc_button_0};

    for(size_t i = 0; i < inv.foodSize(); i++)
    {
        foodButtons[i]->setIcon(QIcon(inv.atFood(i).pathToSkin));
    }
    for(size_t i = inv.foodSize(); i < foodButtons.size(); i++)
    {
        foodButtons[i]->setVisible(false);
        foodButtons[i]->setEnabled(false);
    }
    for(size_t i = 0; i < inv.washMiscSize(); i++)
    {
        washMiscButtons[i]->setIcon(QIcon(inv.atWashMisc(i).pathToSkin));
    }
    for(size_t i = inv.washMiscSize(); i < washMiscButtons.size(); i++)
    {
        washMiscButtons[i]->setVisible(false);
        washMiscButtons[i]->setEnabled(false);
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


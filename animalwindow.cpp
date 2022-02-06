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
    if(inv.loadFromJson("D:\\\\Repos\\Al_Tama\\Items.json"))
    {
        QMessageBox::information(this, "Title", "Loading successfull");
    }
    else
    {
        QMessageBox::critical(this, "Title", "Loading failed");
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


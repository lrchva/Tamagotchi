#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    animalWindow = new AnimalWindow();
    shopWindow = new ShopWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toAnimalsButton_clicked()
{
    animalWindow->show();
    this->close();
}


void MainWindow::on_toShopButton_clicked()
{
    shopWindow->show();
    this->close();
}

bool exitButtonHasBeenPressed = false;
void MainWindow::on_exitButton_clicked()
{
    if(!exitButtonHasBeenPressed)
    {
        exitButtonHasBeenPressed = true;
        int n = 15;
        ui->exitButton->setText(QString("Are you sure? ") + QString::number(n));
    }
    else
    {
        this->close();
    }
}


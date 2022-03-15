#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::shopUserinteraction()
{
    if(animalWindow == nullptr) return;
    animalWindow->displayInventory();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toAnimalsButton_clicked()
{
    animalWindow = new AnimalWindow();
    animalWindow->show();
    this->close();
}


void MainWindow::on_toShopButton_clicked()
{
    shopWindow = new ShopWindow();
    shopWindow->show();
    QObject::connect(shopWindow, SIGNAL(destroyed()), this, SLOT(shopUserInteraction()));
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


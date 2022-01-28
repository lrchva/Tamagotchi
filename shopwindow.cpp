#include "shopwindow.h"
#include "ui_shopwindow.h"

ShopWindow::ShopWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopWindow)
{
    ui->setupUi(this);
}

ShopWindow::~ShopWindow()
{
    delete ui;
}

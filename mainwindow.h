#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "animalwindow.h"
#include "shopwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toAnimalsButton_clicked();

    void on_toShopButton_clicked();

    void on_exitButton_clicked();
    void shopUserinteraction();

private:
    Ui::MainWindow* ui;
    AnimalWindow* animalWindow;
    ShopWindow* shopWindow;
};
#endif // MAINWINDOW_H

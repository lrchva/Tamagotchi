#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QWidget>

namespace Ui {
class ShopWindow;
}

class ShopWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShopWindow(QWidget *parent = nullptr);
    ~ShopWindow();

private:
    Ui::ShopWindow *ui;
};

#endif // SHOPWINDOW_H

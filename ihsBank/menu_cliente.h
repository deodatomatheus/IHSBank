#ifndef MENU_CLIENTE_H
#define MENU_CLIENTE_H

#include <QDialog>
#include <unistd.h>
#include <fcntl.h>
#include <QSocketNotifier>

namespace Ui {
class menu_cliente;
}

class menu_cliente : public QDialog
{
    Q_OBJECT

public:
    explicit menu_cliente(QWidget *parent = nullptr, QString nome = "@",QString conta = "@");
    ~menu_cliente();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



private:
    Ui::menu_cliente *ui;
    QSocketNotifier* notifier;
    QSocketNotifier* notifierw;
};

#endif // MENU_CLIENTE_H

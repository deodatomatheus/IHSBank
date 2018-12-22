#ifndef SAQUE_H
#define SAQUE_H
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <unistd.h>
#include <fcntl.h>
namespace Ui {
class saque;
}

class saque : public QDialog
{
    Q_OBJECT

public:
    explicit saque(QWidget *parent = nullptr,QString conta = "@");
    ~saque();

private slots:
    void on_btn_sacar_clicked();

private:
    Ui::saque *ui;
};

#endif // SAQUE_H

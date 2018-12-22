#ifndef DEPOSITO_H
#define DEPOSITO_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <unistd.h>
#include <fcntl.h>

namespace Ui {
class deposito;
}

class deposito : public QDialog
{
    Q_OBJECT

public:
    explicit deposito(QWidget *parent = nullptr,QString conta = "@");
    ~deposito();

private slots:
    void on_btn_depositar_clicked();

private:
    Ui::deposito *ui;
    //QSocketNotifier* notifier;
};

#endif // DEPOSITO_H

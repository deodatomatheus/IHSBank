#ifndef ADICIONAR_CLIENTE_H
#define ADICIONAR_CLIENTE_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <unistd.h>
#include <fcntl.h>
namespace Ui {
class adicionar_cliente;
}

class adicionar_cliente : public QDialog
{
    Q_OBJECT

public:
    explicit adicionar_cliente(QWidget *parent = nullptr);
    ~adicionar_cliente();

private slots:
    void on_btn_add_clicked();

private:
    Ui::adicionar_cliente *ui;
};

#endif // ADICIONAR_CLIENTE_H

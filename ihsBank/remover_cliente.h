#ifndef REMOVER_CLIENTE_H
#define REMOVER_CLIENTE_H
#include <QtSql>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <unistd.h>
#include <fcntl.h>

namespace Ui {
class remover_cliente;
}

class remover_cliente : public QDialog
{
    Q_OBJECT

public:
    explicit remover_cliente(QWidget *parent = nullptr);
    ~remover_cliente();

private slots:
    void on_btn_excluir_clicked();

private:
    Ui::remover_cliente *ui;
};

#endif // REMOVER_CLIENTE_H

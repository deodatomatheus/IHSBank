#ifndef LISTAR_CLIENTES_H
#define LISTAR_CLIENTES_H
#include <QtSql>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <unistd.h>
#include <fcntl.h>
namespace Ui {
class listar_clientes;
}

class listar_clientes : public QDialog
{
    Q_OBJECT

public:
    explicit listar_clientes(QWidget *parent = nullptr);
    ~listar_clientes();

private:
    Ui::listar_clientes *ui;
};

#endif // LISTAR_CLIENTES_H

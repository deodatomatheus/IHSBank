#ifndef MOSTRAR_DADOS_H
#define MOSTRAR_DADOS_H
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <unistd.h>
#include <fcntl.h>
namespace Ui {
class mostrar_dados;
}

class mostrar_dados : public QDialog
{
    Q_OBJECT

public:
    explicit mostrar_dados(QWidget *parent = nullptr,QString conta = "@");
    ~mostrar_dados();

private:
    Ui::mostrar_dados *ui;
};

#endif // MOSTRAR_DADOS_H

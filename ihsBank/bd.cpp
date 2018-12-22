#include "bd.h"
#include "ui_bd.h"

bd::bd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bd)
{
    ui->setupUi(this);
}
void bd::connectar()
{
    static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE");
    bancodeDados.setDatabaseName("/home/de2i-150/Desktop/ihsBank/bancoihs");

}
bd::~bd()
{
    delete ui;
}


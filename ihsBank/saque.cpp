#include "saque.h"
#include "ui_saque.h"
static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE","bdc_s");
static QString c;

saque::saque(QWidget *parent,QString conta) :
    QDialog(parent),
    ui(new Ui::saque)
{
    ui->setupUi(this);
    c = conta;
    bancodeDados.setDatabaseName("/home/de2i-150/Desktop/ihsBank/bancoihs");
    if(!bancodeDados.open())
    {
        qDebug() << "Banco de dados nao abriu" ;

    }
    else
    {
        qDebug() << "Banco de dados abriu" ;
    }

}

saque::~saque()
{
    bancodeDados.close();
    delete ui;
}

void saque::on_btn_sacar_clicked()
{
    QString saque = ui->txt_saque->text();
    double s = saque.toDouble();
    QSqlQuery query(bancodeDados);
    query.prepare("Select saldo from cliente Where conta = " + c);
    double saldo;
    if(query.exec())
    {

        query.first();
        saldo = query.value(0).toDouble();
        qDebug() << saldo;
        if(saldo - s < 0)
        {
            QMessageBox::warning(this,"Sem saldo","Voce está sem saldo no momento");
            this->close();
        }
        else
        {
            saldo -= s;
            query.prepare("Update cliente set saldo = "+ QString::number(saldo) + " where conta = " + c);
            if(query.exec())
            {
                QMessageBox::warning(this,"Saque","Saque realizado com sucesso!!!");
                this->close();
            }
            else
            {
                QMessageBox::warning(this,"Erro","Erro ao sacar");
            }
        }
    }
    else
        QMessageBox::warning(this,"Erro","erro");


}

#include "deposito.h"
#include "ui_deposito.h"
static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE","bdc_d");
static QString c;

deposito::deposito(QWidget *parent,QString conta) :
    QDialog(parent),
    ui(new Ui::deposito)
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

deposito::~deposito()
{
    delete ui;
    bancodeDados.close();
}

void deposito::on_btn_depositar_clicked()
{
    QString deposito = ui->txt_deposito->text();
    double d = deposito.toDouble();
    QSqlQuery query(bancodeDados);
    query.prepare("Select saldo from cliente Where conta = " + c);
    double saldo;
    if(query.exec())
    {

        query.first();
        saldo = query.value(0).toDouble();
        qDebug() << saldo;
        if(d <= 0)
        {
            QMessageBox::warning(this,"Deposito","Voce nao pode depositar esse valor");
            this->close();
        }
        else
        {
            saldo += d;
            query.prepare("Update cliente set saldo = "+ QString::number(saldo) + " where conta = " + c);
            if(query.exec())
            {
                QMessageBox::warning(this,"Deposito","Deposito realizado com sucesso!!!");
                this->close();
            }
            else
            {
                QMessageBox::warning(this,"Erro","Erro ao depositar");
            }
        }
    }
    else
        QMessageBox::warning(this,"Erro","conta nao encontrada");


}

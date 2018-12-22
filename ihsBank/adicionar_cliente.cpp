#include "adicionar_cliente.h"
#include "ui_adicionar_cliente.h"
#include "login_gerente.h"
static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE","bdg_add");

adicionar_cliente::adicionar_cliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adicionar_cliente)
{
    ui->setupUi(this);
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

adicionar_cliente::~adicionar_cliente()
{
    bancodeDados.close();
    delete ui;
}

void adicionar_cliente::on_btn_add_clicked()
{
    QString cpf = ui->txt_cpf->text();
    QString cpf_g = ui->txt_cpf_g->text();
    QString conta = ui->txt_conta->text();
    QString senha = ui->txt_senha->text();
    QString nome = ui->txt_nome->text();
    QSqlQuery query(bancodeDados);
    query.prepare("Insert into cliente Values ("+ cpf +","+ cpf_g +",'"+ nome +"',"+ conta +",'"+ senha +"',0)");
    if(query.exec())
    {
        QMessageBox::information(this,"inserir","Registro inserido com sucesso");
        ui->txt_cpf->clear();
        ui->txt_cpf_g->clear();
        ui->txt_conta->clear();
        ui->txt_senha->clear();
        ui->txt_nome->clear();
        ui->txt_cpf->setFocus();


    }
    else
           QMessageBox::information(this,"inserir","Registro nao inserido com sucesso");
}

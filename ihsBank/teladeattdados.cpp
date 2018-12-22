#include "teladeattdados.h"
#include "ui_teladeattdados.h"
static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE","bdc_att_dados");
static QString c;
teladeattdados::teladeattdados(QWidget *parent,QString conta) :
    QDialog(parent),
    ui(new Ui::teladeattdados)
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

teladeattdados::~teladeattdados()
{
    bancodeDados.close();
    delete ui;
}

void teladeattdados::on_pushButton_clicked()
{
    QString nome = ui->txt_nome->text();
    QString senha = ui->txt_senha->text();
    QSqlQuery query(bancodeDados);
    query.prepare("Update cliente set nome = '"+ nome + "',senha = '"+ senha +"' where conta = " + c);
    if(query.exec())
    {
        this->close();
    }
    else
    {
        QMessageBox::warning(this,"Erro","Erro ao atualizar contato");
    }
}

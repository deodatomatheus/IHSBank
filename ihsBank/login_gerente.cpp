#include "login_gerente.h"
#include "ui_login_gerente.h"
#include "menu_gerente.h"

static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE","bdg");
int tentativag = 1;
int rg = 1;
int gm = 31;
int dev_lg = open("/dev/de2i150_altera", O_RDWR);
login_gerente::login_gerente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_gerente)
{
    ui->setupUi(this);
    bancodeDados.setDatabaseName("/home/de2i-150/Desktop/ihsBank/bancoihs");
    if(!bancodeDados.open())
        ui->label_status->setText("Bd nao aberto");
    else
        ui->label_status->setText("Bd aberto");

    ui->txt_cpf->setText("10964109409");
    ui->txt_senha->setText("ihss2");

    notifier = new QSocketNotifier(dev_lg,QSocketNotifier::Write,this);
    connect(notifier,SIGNAL(activated(int)),this,SLOT(on_pushButton_clicked()));
    notifier->setEnabled(false);
}

login_gerente::~login_gerente()
{
    delete ui;
    bancodeDados.close();
}

/*
void login_gerente::on_btn_entrar_clicked()
{
    notifier->setEnabled(false);
    QString cpf = ui->txt_cpf->text();
    QString senha = ui->txt_senha->text();

    if(!bancodeDados.isOpen())
    {
        qDebug() << "Banco de dados nao esta aberto";
        return;
    }

    QSqlQuery query(bancodeDados);
    query.prepare("Select * from gerente where cpf = "+ cpf +" and senha = '"+ senha+"'");

    if(query.exec())
    {
        int count=0;
        while(query.next())
        {
            count++;
        }


        if(count > 0)
        {
            query.first();
            QString nome = query.value(1).toString();
            QMessageBox::information(this,"Verificacao","login e senha corretos");
            menu_gerente mg(this,nome);
            int g = 255;
            write(dev_lg, &g, 3);
            int z = 0;
            write(dev_lg, &z, 2);
            mg.setModal(true);
            mg.exec();
            this->close();
        }
        else
        {
            QMessageBox::information(this,"Verificacao","login e senha incorretos");
            ui->txt_cpf->clear();
            ui->txt_senha->clear();
            ui->txt_cpf->setFocus();
            tentativag--;
            int z = 0;
            write(dev_lg, &z, 3);
            write(dev_lg, &rg, 2);
            notifier->setEnabled(false);
            rg += 2;
            QMessageBox::warning(this,"tentativas","Voce tem " + QString::number(tentativag) + " tentativa(s)");
        }
    }
    if(!tentativag)
        write(dev_lg, &gm, 2);
        QMessageBox::warning(this,"tentativas excedidas","Voce errou as 3 tentativas");
        this->close();

}*/

void login_gerente::on_pushButton_clicked()
{
    notifier->setEnabled(false);
    QString cpf = ui->txt_cpf->text();
    QString senha = ui->txt_senha->text();

    if(!bancodeDados.isOpen())
    {
        qDebug() << "Banco de dados nao esta aberto";
        return;
    }

    QSqlQuery query(bancodeDados);
    query.prepare("Select * from gerente where cpf = "+ cpf +" and senha = '"+ senha+"'");

    if(query.exec())
    {
        int count=0;
        while(query.next())
        {
            count++;
        }


        if(count > 0)
        {
            query.first();
            QString nome = query.value(1).toString();
            QMessageBox::information(this,"Verificacao","login e senha corretos");
            menu_gerente mg(this,nome);
            int g = 255;
            write(dev_lg, &g, 3);
            int z = 0;
            write(dev_lg, &z, 2);
            mg.setModal(true);
            mg.exec();
            this->close();
        }
        else
        {
            QMessageBox::information(this,"Verificacao","login e senha incorretos");
            ui->txt_cpf->clear();
            ui->txt_senha->clear();
            ui->txt_cpf->setFocus();
            tentativag--;
            int z = 0;
            write(dev_lg, &z, 3);
            write(dev_lg, &rg, 2);
            notifier->setEnabled(false);
            rg += 2;
            QMessageBox::warning(this,"tentativas","Voce tem " + QString::number(tentativag) + " tentativa(s)");
        }
    }
    if(!tentativag)
        write(dev_lg, &gm, 2);
        QMessageBox::warning(this,"tentativas excedidas","Voce errou.");
        this->close();
}

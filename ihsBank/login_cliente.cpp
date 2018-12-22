#include "login_cliente.h"
#include "ui_login_cliente.h"
#include "menu_cliente.h"
int tentativac = 3;
int r = 1;
int dev_lc = open("/dev/de2i150_altera", O_RDWR);
static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE","bd1");

login_cliente::login_cliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_cliente)
{
    ui->setupUi(this);

    bancodeDados.setDatabaseName("/home/de2i-150/Desktop/ihsBank/bancoihs");
    if(!bancodeDados.open())
        ui->label_status->setText("Bd nao aberto");
    else
        ui->label_status->setText("Bd aberto");

    notifier = new QSocketNotifier(dev_lc,QSocketNotifier::Write,this);
    connect(notifier,SIGNAL(activated(int)),this,SLOT(on_pushButton_clicked()));

}

login_cliente::~login_cliente()
{
    delete ui;
    bancodeDados.close();
}

void login_cliente::on_pushButton_clicked()
{
    notifier->setEnabled(false);
    QString conta = ui->txt_conta->text();
    QString senha = ui->txt_senha->text();

    if(!bancodeDados.isOpen())
    {
        qDebug() << "Banco de dados nao esta aberto";
        return;
    }

    QSqlQuery query(bancodeDados);
    query.prepare("Select * from cliente where conta = "+ conta +" and senha = '"+ senha+"'");

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
            QString nome = query.value(2).toString();
            QMessageBox::information(this,"Verificacao","login e senha corretos");
            menu_cliente mc(this,nome,conta);
            int g = 255;
            write(dev_lc, &g, 3);
            int z = 0;
            write(dev_lc, &z, 2);
            mc.setModal(true);
            mc.exec();
            this->close();

        }
        else
        {
            QMessageBox::information(this,"Verificacao","login e senha incorretos");
            ui->txt_conta->clear();
            ui->txt_senha->clear();
            ui->txt_conta->setFocus();
            tentativac--;
            int z = 0;
            write(dev_lc, &z, 3);
            write(dev_lc, &r, 2);
            notifier->setEnabled(false);
            r += 2;
            QMessageBox::warning(this,"tentativas","Voce tem " + QString::number(tentativac) + " tentativa(s)");
        }
    }
    if(!tentativac)
    {
        int m = 31;
        write(dev_lc, &m, 3);
        QMessageBox::warning(this,"tentativas excedidas","Voce errou as 3 tentativas");
        this->close();
    }

}

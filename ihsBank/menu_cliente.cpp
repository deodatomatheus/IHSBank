#include "menu_cliente.h"
#include "ui_menu_cliente.h"
#include "atualizar_dados.h"
#include "mostrar_dados.h"
#include "saque.h"
#include "deposito.h"

int dev_mc = open("/dev/de2i150_altera", O_RDWR);
int b = 16;

static QString c;
menu_cliente::menu_cliente(QWidget *parent,QString nome,QString conta) :
    QDialog(parent),
    ui(new Ui::menu_cliente)
{
    ui->setupUi(this);
    ui->label->setText("Bem vindo(a)," + nome);
    c = conta;
    notifier = new QSocketNotifier(dev_mc,QSocketNotifier::Read,this);

    connect(notifier,SIGNAL(activated(int)),this,SLOT(on_pushButton_clicked()));
    connect(notifier,SIGNAL(activated(int)),this,SLOT(on_pushButton_2_clicked()));
    connect(notifier,SIGNAL(activated(int)),this,SLOT(on_pushButton_3_clicked()));
    connect(notifier,SIGNAL(activated(int)),this,SLOT(on_pushButton_4_clicked()));


}

menu_cliente::~menu_cliente()
{
    delete ui;
}

void menu_cliente::on_pushButton_clicked()
{
    read(dev_mc,&b,1);
    qDebug() << "Botao " << b << endl;
    notifier->setEnabled(false);

    if(b == 7)
    {
        atualizar_dados ad(this,c);
        ad.exec();
    }

    notifier->setEnabled(true);
}

void menu_cliente::on_pushButton_2_clicked()
{
    read(dev_mc,&b,1);
    qDebug() << "Botao " << b << endl;
    notifier->setEnabled(false);

    if(b == 11)
    {
        mostrar_dados md(this,c);
        md.exec();
    }
      notifier->setEnabled(true);
}

void menu_cliente::on_pushButton_3_clicked()
{
    read(dev_mc,&b,1);
    qDebug() << "Botao " << b << endl;
    notifier->setEnabled(false);

    if(b == 13)
    {
        saque s(this,c);
        s.exec();
    }
    notifier->setEnabled(true);

}

void menu_cliente::on_pushButton_4_clicked()
{
    read(dev_mc,&b,1);
    qDebug() << "Botao " << b << endl;
    notifier->setEnabled(false);

    if(b == 14)
    {
        deposito d(this,c);
        d.exec();
    }
    notifier->setEnabled(true);

}


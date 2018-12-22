#include "menu_gerente.h"
#include "ui_menu_gerente.h"
#include "adicionar_cliente.h"
#include "listar_clientes.h"
#include "remover_cliente.h"

int dev_mg = open("/dev/de2i150_altera", O_RDWR);
int bg;


menu_gerente::menu_gerente(QWidget *parent,QString nome) :
    QDialog(parent),
    ui(new Ui::menu_gerente)
{

    ui->setupUi(this);
    ui->label->setText("Bem vindo," + nome);
    notifier = new QSocketNotifier(dev_mg,QSocketNotifier::Read,this);
    connect(notifier,SIGNAL(activated(int)),this,SLOT(on_pushButton_clicked()));
    connect(notifier,SIGNAL(activated(int)),this,SLOT(on_pushButton_2_clicked()));
    connect(notifier,SIGNAL(activated(int)),this,SLOT(on_pushButton_3_clicked()));

}

menu_gerente::~menu_gerente()
{
    delete ui;
}

void menu_gerente::on_pushButton_clicked()
{
    read(dev_mg,&bg,1);
    qDebug() << "Botao " << bg << endl;
    notifier->setEnabled(false);

    if(bg == 7)
    {

        adicionar_cliente ac;
        ac.exec();
    }
    notifier->setEnabled(true);

}

void menu_gerente::on_pushButton_2_clicked()
{
    read(dev_mg,&bg,1);
    qDebug() << "Botao " << bg << endl;
    notifier->setEnabled(false);

    if(bg == 11)
    {
        listar_clientes lc(this);
        lc.exec();
    }
    notifier->setEnabled(true);

}

void menu_gerente::on_pushButton_3_clicked()
{
    read(dev_mg,&bg,1);
    qDebug() << "Botao " << bg << endl;
    notifier->setEnabled(false);

    if(bg == 13)
    {
        remover_cliente rc;
        rc.exec();
    }
    notifier->setEnabled(true);

}

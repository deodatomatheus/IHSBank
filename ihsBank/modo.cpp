#include "modo.h"
#include "ui_modo.h"
#include "login_gerente.h"
#include "login_cliente.h"

int s = 3;
int dev = open("/dev/de2i150_altera", O_RDWR);
unsigned int seg;
modo::modo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::modo)
{
   ui->setupUi(this);
   notifierw = new QSocketNotifier(dev,QSocketNotifier::Write,this);
   notifier = new QSocketNotifier(dev, QSocketNotifier::Read, this);
   connect(notifier,SIGNAL(activated(int)),this,SLOT(teste_modo_placa_cliente()));
   connect(notifier,SIGNAL(activated(int)),this,SLOT(teste_modo_placa_gerente()));
   connect(notifier,SIGNAL(activated(int)),this,SLOT(on_actionSair_triggered()));
   connect(notifierw,SIGNAL(activated(int)),this,SLOT(mostrar_7()));
}

modo::~modo()
{
    delete ui;
}

void modo::teste_modo_placa_gerente()
{

    read(dev, &s, 0);
    qDebug() << "switch " << s << endl ;

    notifier->setEnabled(false);

    if(s == 1) {
        login_gerente lg;
        this->close();
        qDebug() << "Ok gerente";
        lg.exec();
    }
    notifier->setEnabled(true);

}
void modo::on_actionSair_triggered()
{
   read(dev, &s, 0);
   notifier->setEnabled(false);
   if (s == 1027)
       this->close();
   notifier->setEnabled(true);
}
void modo::teste_modo_placa_cliente()
{
    read(dev, &s, 0);
    notifier->setEnabled(false);
    qDebug() << "switch " << s << endl;
    if (s == 0) {
        login_cliente lc;
        this->close();
        qDebug() << "Ok cliente";
        lc.exec();
    }
    notifier->setEnabled(true);
}
void modo::mostrar_7()
{
    int k;
    k = 0;
    k = ~k;
    notifierw->setEnabled(false);
    write(dev,&k,1);
    int j = 423533;
    j = ~j;
    notifierw->setEnabled(false);
    write(dev,&j,0);

}


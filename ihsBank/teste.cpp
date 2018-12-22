#include "teste.h"
#include "ui_teste.h"
#include <QDebug>
#include <QSocketNotifier>

teste::teste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teste)
{
    ui->setupUi(this);
    notifier = new QSocketNotifier(dev, QSocketNotifier::Read, this);
    //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(board()));
    connect(notifier,SIGNAL(activated(int)),this,SLOT(board()));
    dev = open("/dev/de2i150_altera", O_RDWR);
}

teste::~teste()
{
    delete ui;
}
void teste::board()
{

    int s = 0, b = 1;

    read(dev, &s, 0);
    read(dev, &b, 1);
    qDebug() << "switch " << s << endl ;

    notifier->setEnabled(false);

    //write(dev, &j, 2);

    //read(dev, &j, 1);
    qDebug() <<"button pressed " << b << endl;

      //close(dev);


    /*
    int i, j;

      //int dev = open("/dev/de2i150_altera", O_RDWR);

      for (i=0; i>-1; i++) {
        read(dev, &j, 0);
        qDebug() <<"button " << j << endl;


        write(dev, &j, 2);

        read(dev, &j, 1);

        qDebug() <<"button " << j << endl;


        write(dev, &j, 3);
      }
      */

      //close(dev);
}

void teste::on_pushButton_clicked()
{
    notifier->setEnabled(true);
}

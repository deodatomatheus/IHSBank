#include "mostrar_dados.h"
#include "ui_mostrar_dados.h"

static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE","bdc_mostrar");
static QString c;

mostrar_dados::mostrar_dados(QWidget *parent,QString conta) :
    QDialog(parent),
    ui(new Ui::mostrar_dados)
{
    ui->setupUi(this);
    c = conta;
    bancodeDados.setDatabaseName("/home/de2i-150/Desktop/ihsBank/bancoihs");
    if(!bancodeDados.open())
    {
        qDebug() << "Banco de dados nao abriu pra att" ;
    }
    else
    {
        qDebug() << "Banco de dados abriu pra att" ;
    }

    QSqlQuery query(bancodeDados);
    query.prepare("Select * from cliente Where conta = " + conta);
    if(query.exec())
    {
        int count = 0;
        ui->tableWidget->setColumnCount(5);
        while(query.next())
        {
            ui->tableWidget->insertRow(count);
            int j = 0;
            for (int i = 0 ; i < 5 ; i++,j++)
            {
                    if (i == 1)
                        j++;
                     ui->tableWidget->setItem(count,i,new QTableWidgetItem(query.value(j).toString()));

            }
            count++;
        }

        QStringList cabecalhos = {"cpf","nome","conta","senha","saldo"};
        ui->tableWidget->setHorizontalHeaderLabels(cabecalhos);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // nao editavel
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //linha inteira selecionada
        ui->tableWidget->verticalHeader()->setVisible(false);
        ui->tableWidget->setStyleSheet("QTableView {selection-background-color:blue}");

    }
    else
    {
        QMessageBox::warning(this,"Erro","Erro ao pesquisar");
    }
}

mostrar_dados::~mostrar_dados()
{
    delete ui;
    bancodeDados.close();
}

#include "listar_clientes.h"
#include "ui_listar_clientes.h"

static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE","bdg_listar");

listar_clientes::listar_clientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listar_clientes)
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
    QSqlQuery query(bancodeDados);
    query.prepare("Select * from cliente");
    if(query.exec())
    {
        int count = 0;
        ui->tableWidget->setColumnCount(6);
        while(query.next())
        {
            ui->tableWidget->insertRow(count);
            for (int i = 0; i < 6 ; i++)
            {
                  ui->tableWidget->setItem(count,i,new QTableWidgetItem(query.value(i).toString()));
            }
            count++;
        }
        /*
        ui->tableWidget->setColumnWidth(0,30);
        ui->tableWidget->setColumnWidth(1,158);
        ui->tableWidget->setColumnWidth(3,250);
        */
        QStringList cabecalhos = {"cpf","cpf_g","nome","conta","senha","saldo"};
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

listar_clientes::~listar_clientes()
{
    delete ui;
    bancodeDados.close();
}

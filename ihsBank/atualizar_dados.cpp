#include "atualizar_dados.h"
#include "ui_atualizar_dados.h"
#include "teladeattdados.h"
static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE","bdc_att");
static QString c;
atualizar_dados::atualizar_dados(QWidget *parent,QString conta) :
    QDialog(parent),
    ui(new Ui::atualizar_dados)
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

atualizar_dados::~atualizar_dados()
{
    bancodeDados.close();
    delete ui;
}

void atualizar_dados::on_btn_att_clicked()
{
    int linha = ui->tableWidget->currentRow();
    teladeattdados t(this,c);
    t.exec();
    // aqui
    QSqlQuery query(bancodeDados);
    query.prepare("Select * from cliente Where conta = " + c);
    if(query.exec())
    {
        query.first();
        int j = 0;
        for (int i = 0 ; i < 5 ; i++,j++)
        {
                if (i == 1)
                    j++;
                 ui->tableWidget->setItem(linha,i,new QTableWidgetItem(query.value(j).toString()));

        }
    }

}

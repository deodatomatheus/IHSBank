#include "remover_cliente.h"
#include "ui_remover_cliente.h"

static QSqlDatabase bancodeDados = QSqlDatabase::addDatabase("QSQLITE","bdg_excluir");

remover_cliente::remover_cliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remover_cliente)
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

remover_cliente::~remover_cliente()
{
    bancodeDados.close();
    delete ui;
}

void remover_cliente::on_btn_excluir_clicked()
{
    int linha = ui->tableWidget->currentRow();
    int cpf = ui->tableWidget->item(linha,0)->text().toInt();
    QSqlQuery query(bancodeDados);
    query.prepare("Delete From cliente Where cpf = "+ QString::number(cpf));
    if(query.exec())
    {
         QMessageBox::information(this,"Excluir","Registro excluido");
         ui->tableWidget->removeRow(linha);
    }
    else
    {
        QMessageBox::warning(this,"Erro","Erro ao excluir");
    }

}

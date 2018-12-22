#ifndef ATUALIZAR_DADOS_H
#define ATUALIZAR_DADOS_H


#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class atualizar_dados;
}

class atualizar_dados : public QDialog
{
    Q_OBJECT

public:
    explicit atualizar_dados(QWidget *parent = nullptr,QString conta = "@");
    ~atualizar_dados();

private slots:
    void on_btn_att_clicked();

private:
    Ui::atualizar_dados *ui;
};

#endif // ATUALIZAR_DADOS_H

#ifndef TELADEATTDADOS_H
#define TELADEATTDADOS_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <unistd.h>
#include <fcntl.h>
namespace Ui {
class teladeattdados;
}

class teladeattdados : public QDialog
{
    Q_OBJECT

public:
    explicit teladeattdados(QWidget *parent = nullptr,QString conta = "@");
    ~teladeattdados();

private slots:
    void on_pushButton_clicked();

private:
    Ui::teladeattdados *ui;
};

#endif // TELADEATTDADOS_H

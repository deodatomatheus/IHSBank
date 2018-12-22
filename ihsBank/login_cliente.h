#ifndef LOGIN_CLIENTE_H
#define LOGIN_CLIENTE_H
#include <QtSql>
#include <QDialog>
#include <QMessageBox>
#include <QtDebug>
#include <unistd.h>
#include <fcntl.h>
#include <QSocketNotifier>
namespace Ui {
class login_cliente;
}

class login_cliente : public QDialog
{
    Q_OBJECT

public:
    explicit login_cliente(QWidget *parent = nullptr);
    ~login_cliente();

private slots:

    void on_pushButton_clicked();

private:
    Ui::login_cliente *ui;
    QSocketNotifier* notifier;
};

#endif // LOGIN_CLIENTE_H

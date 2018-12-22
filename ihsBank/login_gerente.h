#ifndef LOGIN_GERENTE_H
#define LOGIN_GERENTE_H
#include <QtDebug>
#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <unistd.h>
#include <fcntl.h>
#include <QSocketNotifier>
namespace Ui {
class login_gerente;
}

class login_gerente : public QDialog
{
    Q_OBJECT

public:
    explicit login_gerente(QWidget *parent = nullptr);
    ~login_gerente();

private slots:
    //void on_btn_entrar_clicked();

    void on_pushButton_clicked();

private:
    Ui::login_gerente *ui;
    QSocketNotifier* notifier;
};

#endif // LOGIN_GERENTE_H

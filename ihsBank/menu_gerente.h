#ifndef MENU_GERENTE_H
#define MENU_GERENTE_H

#include <QDialog>
#include <QtSql>
#include <unistd.h>
#include <fcntl.h>
#include <QSocketNotifier>

namespace Ui {
class menu_gerente;
}

class menu_gerente : public QDialog
{
    Q_OBJECT

public:
    explicit menu_gerente(QWidget *parent = nullptr,QString nome= "@");
    ~menu_gerente();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::menu_gerente *ui;
    QSocketNotifier* notifier;
};

#endif // MENU_GERENTE_H

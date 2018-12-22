#ifndef MODO_H
#define MODO_H

#include <QMainWindow>
#include <unistd.h>
#include <fcntl.h>
#include <QSocketNotifier>

namespace Ui {
class modo;
}

class modo : public QMainWindow
{
    Q_OBJECT

public:
    explicit modo(QWidget *parent = nullptr);
    ~modo();
    void board(long int);
signals:
    void board_signal(long int);

private slots:
    void teste_modo_placa_gerente();

    void on_actionSair_triggered();

    void teste_modo_placa_cliente();

    void mostrar_7();

private:
    Ui::modo *ui;
    QSocketNotifier* notifier;
    QSocketNotifier* notifierw;
    //int dev;
};

#endif // MODO_H

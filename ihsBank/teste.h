#ifndef TESTE_H
#define TESTE_H
#include <unistd.h>
#include <fcntl.h>
#include <QSocketNotifier>
#include <QDialog>

namespace Ui {
class teste;
}

class teste : public QDialog
{
    Q_OBJECT

public:
    explicit teste(QWidget *parent = 0);
    ~teste();
private slots:
    void board();
    void on_pushButton_clicked();

private:
    Ui::teste *ui;
    QSocketNotifier* notifier;
    int dev;
};

#endif // TESTE_H

#ifndef BD_H
#define BD_H
#include <QtSql>
#include <QDialog>
#include <QMessageBox>
namespace Ui {
class bd;
}

class bd : public QDialog
{
    Q_OBJECT

public:
    explicit bd(QWidget *parent = nullptr);
    ~bd();
private:
    Ui::bd *ui;
};

#endif // BD_H

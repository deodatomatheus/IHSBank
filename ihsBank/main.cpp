#include "modo.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *tela = new QSplashScreen;
    tela->setPixmap(QPixmap(":/imgs/47388300_339725040187838_3001942283160387584_n.png").scaled(400,400,Qt::KeepAspectRatio));
    tela->show();
    modo w;
    QTimer::singleShot(2000,tela,SLOT(close()));
    QTimer::singleShot(2000,&w,SLOT(show()));
    return a.exec();
}

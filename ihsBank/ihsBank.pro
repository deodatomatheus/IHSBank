#-------------------------------------------------
#
# Project created by QtCreator 2018-11-30T21:15:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ihsBank
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += -qt-sqlite c++11

SOURCES += \
        main.cpp \
        modo.cpp \
    login_gerente.cpp \
    login_cliente.cpp \
    menu_gerente.cpp \
    menu_cliente.cpp \
    adicionar_cliente.cpp \
    listar_clientes.cpp \
    remover_cliente.cpp \
    atualizar_dados.cpp \
    mostrar_dados.cpp \
    saque.cpp \
    deposito.cpp \
    teladeattdados.cpp

HEADERS += \
        modo.h \
    login_gerente.h \
    login_cliente.h \
    menu_gerente.h \
    menu_cliente.h \
    adicionar_cliente.h \
    listar_clientes.h \
    remover_cliente.h \
    atualizar_dados.h \
    mostrar_dados.h \
    saque.h \
    deposito.h \
    teladeattdados.h


FORMS += \
        modo.ui \
    login_gerente.ui \
    login_cliente.ui \
    menu_gerente.ui \
    menu_cliente.ui \
    adicionar_cliente.ui \
    listar_clientes.ui \
    remover_cliente.ui \
    atualizar_dados.ui \
    mostrar_dados.ui \
    saque.ui \
    deposito.ui \
    teladeattdados.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc

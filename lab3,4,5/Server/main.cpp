#include <QCoreApplication>
#include <QDebug>
#include "AppTcpServer.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    AppTcpServer server;
    return QCoreApplication::exec();
}

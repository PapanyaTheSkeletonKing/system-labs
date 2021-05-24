//
// Created by Vyatalech on 23.05.2021.
//

#include "clientsocket.h"

void ClientSocket::connectToServer(int host_port) {
    connectToHost(QHostAddress::LocalHost, host_port);

    if (!waitForConnected(5000)) qDebug() << "Error connecting to server";
}

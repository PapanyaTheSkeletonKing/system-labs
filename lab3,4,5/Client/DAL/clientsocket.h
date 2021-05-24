//
// Created by Vyatalech on 23.05.2021.
//

#ifndef UNTITLED3_CLIENTSOCKET_H
#define UNTITLED3_CLIENTSOCKET_H
#include<QTcpSocket>
#include "QHostAddress"
#include "Note.h"

class ClientSocket : public QTcpSocket {
    Q_OBJECT
public:
    explicit ClientSocket( QObject *parent = nullptr ) :
            QTcpSocket( parent ) { }

            void connectToServer( int host_port );
public slots:

private:
};


#endif //UNTITLED3_CLIENTSOCKET_H

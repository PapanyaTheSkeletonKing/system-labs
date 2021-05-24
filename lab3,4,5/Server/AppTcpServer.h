//
// Created by Vyatalech on 23.05.2021.
//

#ifndef UNTITLED1_APPTCPSERVER_H
#define UNTITLED1_APPTCPSERVER_H


#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "NotesRepository.h"


class AppTcpServer : public QObject {
    Q_OBJECT
public:
    explicit AppTcpServer(QObject *parent=nullptr);
    signals:

public slots:
    void newConnection();
    void returnData();

private:
    QByteArray processRequestData(QByteArray requestData);
    QTcpServer *server;
    NotesRepository *notes_repository;
    QSqlDatabase sqlDatabase;
};


#endif //UNTITLED1_APPTCPSERVER_H

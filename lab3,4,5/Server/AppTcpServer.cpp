//
// Created by Vyatalech on 23.05.2021.
//

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "AppTcpServer.h"

AppTcpServer::AppTcpServer(QObject *parent) :
        QObject(parent)
{
    server = new QTcpServer(this);
    sqlDatabase = QSqlDatabase::addDatabase("QSQLITE","SQLITE");
    sqlDatabase.setDatabaseName(R"(C:\Program Files\sqlite\Notes1)");
    sqlDatabase.setHostName("notes");
    sqlDatabase.open();

    notes_repository = new NotesRepository(sqlDatabase);

    connect(server, SIGNAL(newConnection()),
            this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::LocalHost, 80))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
    }
}



void AppTcpServer::newConnection()
{
    QTcpSocket *new_socket = server->nextPendingConnection();

    connect(new_socket, SIGNAL(readyRead()),
            this, SLOT(returnData()));

    qDebug() << "Request process started...";


}

QByteArray AppTcpServer::processRequestData(QByteArray requestData) {
    QJsonDocument jsonDocData = QJsonDocument::fromJson(requestData);
    QJsonObject jsonObject = jsonDocData.object();
    QJsonObject responseJson;
    string request_type = jsonObject["Type"].toString().toStdString();
    responseJson["Type"] = request_type.c_str();

    if (request_type == "UserNotes"){
        auto user = new User(jsonObject);
        auto notes = notes_repository->GetByUser(*user);

        QJsonArray notes_array;

        for (auto& note : notes){
            QJsonObject noteJsonObject;

            noteJsonObject["Id"]          = note.GetId();
            noteJsonObject["Text"]        = note.GetText().c_str();
            noteJsonObject["InitialDate"] = note.GetInitialDate().toString().toStdString().c_str();
            noteJsonObject["UserId"]      = note.GetUserId();

            notes_array.append(noteJsonObject);
        }

        responseJson["notes"] = notes_array;

        qDebug() << responseJson;
    }
    else if (request_type == "AddNote"){
        Note note = { jsonObject };
        notes_repository ->Add(note);
    }
    else if (request_type == "UpdateNote"){
        qDebug() << jsonObject;
        Note note = { jsonObject };
        notes_repository ->Update(note);
    }

    return QJsonDocument(responseJson).toJson();
}

void AppTcpServer::returnData() {
    auto *socket = dynamic_cast<QTcpSocket*>(sender());
    socket->write(processRequestData(socket->readAll()));
    socket->flush();
    socket->close();
    qDebug() << "Request process end...";
}

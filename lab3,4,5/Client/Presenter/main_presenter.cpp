//
// Created by Vyatalech on 26.04.2021.
//

#include <QDateTime>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "main_presenter.h"
#include "../DAL/ObjectHelper.h"
#include "../json.hpp"
using namespace std;

void MainPresenter::ConnectToViews () {
    connect(this->login_view, SIGNAL(loginButtonClicked(std::string,std::string))
            , this, SLOT(on_loginRequested(std::string,std::string)));
    connect(this, SIGNAL(LoadMainView(std::vector<Note>)), main_view, SLOT(on_mainView_loading(std::vector<Note>)));

    connect(this->main_view, SIGNAL(OpenNote(Note)), this, SLOT(on_open_editorWithNote(Note)));
    connect(this->main_view, SIGNAL(CreateNewNoteButtonClicked()), this, SLOT(on_open_editorWithNewNote()));

    connect(this, SIGNAL(OpenEditorView(Note)), editor_view, SLOT(on_loadTextFromDb(Note)));
    connect(this, SIGNAL(OpenEditorView(Note)), main_view, SLOT(on_editor_opened()));

    connect(editor_view, SIGNAL(closeButtonClicked()), this,SLOT(on_editor_closing()));
    connect(editor_view, SIGNAL(closeButtonClicked()), main_view,SLOT(on_editor_closing()));
    connect(editor_view, SIGNAL(saveButtonClicked(Note)), this, SLOT(on_save_note(Note)));
}

void MainPresenter::on_loginRequested(std::string username, std::string password) {
        User user = userRepository->GetByCredentials(username, password);
    if (ObjectHelper::IsEmpty(user)) {
            login_view->ShowErrorMessage("User not found.Try one more time.");
            return;
    }
    sqlDatabase.close();
    connectedUser = user;

    socket->connectToServer(80);
    socket->write(userRepository->toByteArray(user));
}


MainPresenter::~MainPresenter(){
    sqlDatabase.close();
}

MainPresenter::MainPresenter(MainView *main_view,LoginView* login_view,EditorView* editor_view) {
    sqlDatabase = QSqlDatabase::addDatabase("QSQLITE","SQLITE");
    sqlDatabase.setDatabaseName(R"(C:\Program Files\sqlite\Notes1)");
    sqlDatabase.setHostName("notes");
    sqlDatabase.open();

    this -> main_view = main_view;
    this -> login_view = login_view;
    this -> editor_view = editor_view;

    userRepository = new UserRepository(sqlDatabase);

    ConnectToViews();
    setupSocket(80);
}

void MainPresenter::on_open_editorWithNote(Note note) {
    emit OpenEditorView(note);
}


void MainPresenter::on_open_editorWithNewNote() {
    Note note;
    note.isNew = true;
    note.SetUserId(connectedUser.GetId());
    note.SetInitialDate(QDateTime::currentDateTime());
    note.SetId(NotesRepository::lastNoteId++);
    note.SetText("");

    emit OpenEditorView(note);
}

void MainPresenter::on_save_note(Note note) {
    auto request = ObjectHelper::toJson(note);
    if (note.isNew) {
        request["Type"] = "AddNote";
    }
    else {

        request["Type"] = "UpdateNote";
    }
    socket->connectToServer(80);
    socket->write(QJsonDocument(request).toJson());
}

void MainPresenter::on_editor_closing() {
    socket->connectToServer(80);
    socket->write(userRepository->toByteArray(connectedUser));
    editor_view->hide();
}

void MainPresenter::connected() {
    qDebug() << "connected ..";
}

void MainPresenter::disconnected() {
    qDebug() << "disconnected...";
}

void MainPresenter::bytesWritten(qint64 bytes) {
    qDebug() << bytes << " bytes written...";
}

void MainPresenter::onResponseParse(const QByteArray& responseData){
    QJsonObject jsonResponseObject = QJsonDocument::fromJson(responseData).object();
    string request_type =  jsonResponseObject["Type"].toString().toStdString();

    if (request_type == "UserNotes"){
        emit LoadMainView(ObjectHelper::parseFromResponse(jsonResponseObject["notes"].toArray()));
    }
}

void MainPresenter::readyRead() {
    qDebug() << "reading...";
    onResponseParse(socket->readAll());
}

void MainPresenter::setupSocket(int host_port) {
    socket = new ClientSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

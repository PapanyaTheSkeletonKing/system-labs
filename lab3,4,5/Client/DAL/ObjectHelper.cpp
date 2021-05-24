//
// Created by Vyatalech on 16.05.2021.
//

#include <QJsonObject>
#include "ObjectHelper.h"
#include "QJsonDocument"
#include "QJsonArray"


#include "Note.h"
#include "NotesRepository.h"

vector<User> ObjectHelper::ParseUsersFromQuery(QSqlQuery * query) {
    vector<User> users = {};
    while (query->next()) {
        User user;
        user.SetId(query->value(0).toInt());
        user.SetUsername(query->value(1).toString().toStdString());
        user.SetPassword(query->value(2).toString().toStdString());

        users.push_back(user);
    }
    return users;
}

bool ObjectHelper::IsEmpty(const User &user) {
    return user.GetPassword().empty() && user.GetUsername().empty();
}

QJsonObject ObjectHelper::toJson(const Note &note){
    QJsonObject noteJsonObject;
    noteJsonObject["Id"]          = note.GetId();
    noteJsonObject["Text"]        = note.GetText().c_str();
    noteJsonObject["InitialDate"] = note.GetInitialDate().toString().toStdString().c_str();
    noteJsonObject["UserId"]      = note.GetUserId();
    return noteJsonObject;
}

vector<Note> ObjectHelper::parseFromResponse(QJsonArray responseData){
    vector<Note> notes;

            foreach(QJsonValue value,responseData){
            Note note;

            note.SetId(value["Id"].toInt());
            note.SetText(value["Text"].toString().toStdString());
            note.SetInitialDate(QDateTime::fromString(value["InitialDate"].toString()));
            note.SetUserId(value["UserId"].toInt());

            notes.push_back(note);
            NotesRepository::lastNoteId = note.GetId() + 1;
        }
    return notes;
}

vector<Note> ObjectHelper::ParseNotesFromQuery(QSqlQuery *query) {
    vector<Note> notes = {};
    while (query->next()) {
        Note note;
        note.SetId(query->value(0).toInt());
        note.SetText(query->value(1).toString().toStdString());
        note.SetInitialDate(QDateTime::fromSecsSinceEpoch(query->value(2).toUInt(),Qt::LocalTime));
        note.SetUserId(query->value(3).toInt());

        notes.push_back(note);
    }
    return notes;
}

//
// Created by Vyatalech on 16.05.2021.
//

#include "ObjectHelper.h"
#include "Note.h"

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

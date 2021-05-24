//
// Created by Vyatalech on 20.04.2021.
//

#include "Note.h"

QDateTime Note::GetInitialDate() const {
    return initialDate;
}

void Note::SetInitialDate(const QDateTime &date) {
    initialDate = date;
}

void Note::SetText(const string &text) {
    this->text = text;
}

void Note::SetId(int id) {
    this->id = id;
}

int Note::GetId() const {
    return id;
}

string Note::GetText() const {
    return text;
}

int Note::GetUserId() const {
    return userId;
}

void Note::SetUserId(int id) {
    userId = id;
}

Note::Note(QJsonObject &jsonData) {
    SetId(jsonData["Id"].toInt());
    SetText(jsonData["Text"].toString().toStdString());
    SetInitialDate(QDateTime::fromString(jsonData["InitialDate"].toString()));
    SetUserId(jsonData["UserId"].toInt());
}

Note::Note() {

}




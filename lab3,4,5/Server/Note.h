//
// Created by Vyatalech on 20.04.2021.
//

#ifndef UNTITLED3_NOTE_H
#define UNTITLED3_NOTE_H

#include <string>
#include <QDate>
#include "QJsonObject"

using namespace std;


class Note {
public:
    Note();

    Note(QJsonObject &jsonData);

    void SetInitialDate(const QDateTime& date);
    void SetText(const string& text);
    void SetId(int id);
    void SetUserId(int id);

    QDateTime GetInitialDate() const;
    string GetText() const;

    int GetUserId() const;
    int GetId()     const;



private:
    QDateTime initialDate;
    string    text;
    int       userId;
    int       id;
};


#endif //UNTITLED3_NOTE_H

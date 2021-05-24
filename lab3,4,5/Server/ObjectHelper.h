//
// Created by Vyatalech on 16.05.2021.
//

#ifndef UNTITLED3_OBJECTHELPER_H
#define UNTITLED3_OBJECTHELPER_H


#include <QSqlQuery>
#include "User.h"
#include "vector"
#include "Note.h"

using namespace std;

class ObjectHelper {
public:
    static vector<User> ParseUsersFromQuery(QSqlQuery *);
    static vector<Note> ParseNotesFromQuery(QSqlQuery *);

    static bool IsEmpty(const User& user);

};


#endif //UNTITLED3_OBJECTHELPER_H

//
// Created by Vyatalech on 16.05.2021.
//

#ifndef UNTITLED3_USERREPOSITORY_H
#define UNTITLED3_USERREPOSITORY_H


#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "User.h"
#include "forward_list"

class UserRepository{
public:
    UserRepository(QSqlDatabase &dbInstance);

    vector<User> GetAll();

    QByteArray toByteArray(User& user);
    void  Add(User& note);
    void  Update(User& note);
    void  Delete(User& note);
    void  Delete(int id);
    User  Get(int id) ;
    User  GetByCredentials(const string& username, const string& password);

private:
    QSqlDatabase& dbInstance;
    QSqlQuery* dbQueryObject;
};


#endif //UNTITLED3_USERREPOSITORY_H

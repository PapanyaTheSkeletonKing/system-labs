//
// Created by Vyatalech on 16.05.2021.
//

#include <QJsonObject>
#include "UserRepository.h"
#include "QueryFactory.h"
#include "ObjectHelper.h"
#include "QJsonDocument"
#include "NotesRepository.h"

vector<User> UserRepository::GetAll() {
   dbQueryObject->exec(
            QueryFactory::MakeSelectQuery(
                    {"*"},
                    "users")
    );
    return ObjectHelper::ParseUsersFromQuery(dbQueryObject);
}

User UserRepository::GetByCredentials(const string& username, const string& password) {
    dbQueryObject->exec(
            QueryFactory::MakeSelectQuery(
                    {"*"},
                    "users",
                    "Password='" + password + "' AND " +
                    "Username='" + username + "'")
                    );

    vector<User> loadedUsers = ObjectHelper::ParseUsersFromQuery(dbQueryObject);
    if (!loadedUsers.empty()){
        return loadedUsers[0];
    } else {
        return *new User;
    }
}



UserRepository::UserRepository(QSqlDatabase &dbInstance) : dbInstance(dbInstance){
    dbQueryObject = new QSqlQuery(dbInstance);
}

QByteArray UserRepository::toByteArray(User &user) {
    QJsonObject userDataRequestJson;
    userDataRequestJson["Type"] = "UserNotes";
    userDataRequestJson["Id"]       = user.GetId();
    userDataRequestJson["Username"] = user.GetUsername().c_str();
    userDataRequestJson["Password"] = user.GetPassword().c_str();

    return QJsonDocument(userDataRequestJson).toJson();
}

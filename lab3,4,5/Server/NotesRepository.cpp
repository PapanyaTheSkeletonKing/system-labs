//
// Created by Vyatalech on 20.04.2021.
//

#include "NotesRepository.h"
#include "QueryFactory.h"
#include "ObjectHelper.h"

NotesRepository::NotesRepository(QSqlDatabase &dbInstance)
        : dbInstance(dbInstance){
    queryObject = new QSqlQuery(dbInstance);
}

vector<Note> NotesRepository::GetAll() {
    queryObject->exec(QueryFactory::MakeSelectQuery(
            {"*"},
            "notes"));

    return ObjectHelper::ParseNotesFromQuery(queryObject);
}

void NotesRepository::Add(const Note& note) {
    QString query = QueryFactory::MakeInsertQuery
            ("notes",
             to_string(note.GetId()) +
             ",'" + note.GetText() + "'," +
              to_string(note.GetInitialDate().toSecsSinceEpoch()) + "," +
              to_string(note.GetUserId()));

    dbInstance.exec(query);
}



void NotesRepository::Update(const Note &note) {
    dbInstance.exec(QueryFactory::MakeUpdateQuery(
            "notes",
            "Text='" + note.GetText()+ "'",
            "Id=" + to_string(note.GetId())
    ));
}

vector<Note> NotesRepository::GetByUser(const User& user) {
    queryObject->exec(QueryFactory::MakeSelectQuery
            ({"*"},
             "notes",
             "UserId=" + to_string(user.GetId())
             ));
    auto result = ObjectHelper::ParseNotesFromQuery(queryObject);
    return result;
}

bool NotesRepository::IsExist(const Note &note) {
    queryObject->exec(
            QueryFactory::MakeSelectQuery(
                    {"*"},
                    "notes",
                    "Id=" + to_string(note.GetId()))
    );

    return !ObjectHelper::ParseNotesFromQuery(queryObject).empty();
}







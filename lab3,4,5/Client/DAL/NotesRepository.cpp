//
// Created by Vyatalech on 20.04.2021.
//

#include <QJsonDocument>
#include <QJsonObject>
#include "NotesRepository.h"
#include "QueryFactory.h"
#include "ObjectHelper.h"
#include "QJsonArray.h"


int NotesRepository::lastNoteId = 0;

NotesRepository::NotesRepository(QSqlDatabase &dbInstance)
        : dbInstance(dbInstance){
    queryObject = new QSqlQuery(dbInstance);
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



bool NotesRepository::IsExist(const Note &note) {
    queryObject->exec(
            QueryFactory::MakeSelectQuery(
                    {"*"},
                    "notes",
                    "Id=" + to_string(note.GetId()))
    );

    return !ObjectHelper::ParseNotesFromQuery(queryObject).empty();
}







//
// Created by Vyatalech on 20.04.2021.
//

#include "forward_list"
using namespace std;
#ifndef UNTITLED3_REPOSITORY_H
#define UNTITLED3_REPOSITORY_H
#include "QSqlDatabase"
#include "Note.h"
#include "User.h"

class NotesRepository{
public:
    NotesRepository(QSqlDatabase &dbInstance);
    vector<Note> GetAll();

    static int lastNoteId;
    void  Add(const Note& note);
    void  Update(const Note& note);
    void  Delete(const Note& note);
    void  Delete(int id);
    Note  Get(int id);
    bool IsExist(const Note& note);

    vector<Note>  GetByUser(const User& user);

private:
    QSqlDatabase& dbInstance;
    QSqlQuery* queryObject;

};


#endif //UNTITLED3_REPOSITORY_H

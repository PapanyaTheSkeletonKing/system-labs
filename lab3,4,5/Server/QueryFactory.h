//
// Created by Vyatalech on 26.04.2021.
//

#ifndef UNTITLED3_QUERYFACTORY_H
#define UNTITLED3_QUERYFACTORY_H

#include <string>
#include <QSqlQuery>

using namespace std;

class QueryFactory {
public:
    static QString MakeSelectQuery(const vector<string>& rows, const string& table_name,const string& condition = "");
    static QString MakeDeleteQuery(const string &table_name, const string &condition);
    static QString MakeInsertQuery(const string& table_name, const string &values);
    static QString MakeUpdateQuery(const string& table_name, const string &columns,const string& condition);

};



#endif //UNTITLED3_QUERYFACTORY_H

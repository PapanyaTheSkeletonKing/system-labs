//
// Created by Vyatalech on 26.04.2021.
//

#include "QueryFactory.h"
#include "Util.h"



QString QueryFactory::MakeSelectQuery(const vector<string> &rows,
                                      const string &table_name,
                                      const string &condition) {
    string query_rows;
    for (auto &row : rows) {
        if (!Util::IsLastObjectOfVector(row, rows))
            query_rows += row + ", ";
        else
            query_rows += row + " ";
    }

    if ( !condition.empty() ){
        auto result = QString::fromStdString(
                "SELECT " + query_rows +
                "FROM " + table_name +
                " WHERE " + condition +";");
        return result;
    }

    auto result = QString::fromStdString(
            "SELECT " + query_rows +
              "FROM " + table_name + ";");
    return result;
}

QString QueryFactory::MakeDeleteQuery(const string &table_name,
                                      const string &condition) {
    return QString::fromStdString(
            "DELETE FROM " + table_name +
            "WHERE " + condition + ";"
    );
}

QString QueryFactory::MakeInsertQuery(const string &table_name,
                                      const string &values) {
    return QString::fromStdString(
            "INSERT INTO " + table_name +
            " VALUES " +"(" + values + ");");
}

QString QueryFactory::MakeUpdateQuery(const string &table_name, const string &columns, const string &condition) {
    QString string =  QString::fromStdString(
            "UPDATE " + table_name +
            " SET " + columns +
            " WHERE " + condition + ";");
    return string;

}




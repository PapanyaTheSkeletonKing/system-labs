//
// Created by Vyatalech on 26.04.2021.
//

#ifndef UNTITLED3_HELPER_H
#define UNTITLED3_HELPER_H

#endif //UNTITLED3_HELPER_H

#include <QSql>

class Util{
public:
    template <class T>
    static inline bool IsLastObjectOfVector(const T &elem,const vector<T> &vec){
        return vec.back() == elem;
    }
    static inline QSqlDatabase GetDbInstance(){
        return db_instance;
    }

    static inline void SetDbInstance(QSqlDatabase& db){
        db_instance = db;
    }

private:
    static QSqlDatabase& db_instance;
};
//
// Created by Vyatalech on 16.05.2021.
//

#ifndef UNTITLED3_USER_H
#define UNTITLED3_USER_H
using namespace std;

class User {
public:
    string GetUsername() const { return username; }
    string GetPassword() const { return password; }
    int    GetId()       const { return id; }

    void SetUsername(const string&);
    void SetPassword(const string&);
    void SetId(int id);

private:
    int id;
    string username;
    string password;
};


#endif //UNTITLED3_USER_H

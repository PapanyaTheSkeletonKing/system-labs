//
// Created by Vyatalech on 16.05.2021.
//

#include <string>
#include "User.h"

void User::SetUsername(const string &username) {
    this->username = username;
}

void User::SetPassword(const string &password) {
    this->password = password;
}

void User::SetId(int id) {
    this->id = id;
}

//
// Created by Vyatalech on 16.05.2021.
//

#ifndef UNTITLED3_LOGINVIEW_H
#define UNTITLED3_LOGINVIEW_H

#include <QWidget>
#include <QMainWindow>
#include "../DAL/User.h"
#include "../DAL/Note.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class LoginView; }
QT_END_NAMESPACE


class LoginView : public QMainWindow {
Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);

    ~LoginView() override ;
    void ShowErrorMessage(const string &message);


public slots:
    void on_button_login_click();

    signals:
    void loginButtonClicked(std::string,std::string);

private:

    Ui::LoginView *ui;
};


#endif //UNTITLED3_LOGINVIEW_H

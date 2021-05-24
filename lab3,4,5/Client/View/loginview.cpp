//
// Created by Vyatalech on 16.05.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LoginView.h" resolved

#include <QDialog>
#include <QMessageBox>
#include <iostream>
#include "loginview.h"
#include "ui_LoginView.h"


LoginView::LoginView(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::LoginView) {
    ui->setupUi(this);
    connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(on_button_login_click()));
}

LoginView::~LoginView() {
    delete ui;
}

void LoginView::on_button_login_click() {
    std::cout << "1";
    QString login = ui->loginText->text();
    QString password = ui->passwordText->text();
    if (login.isEmpty() || password.isEmpty()){
        ShowErrorMessage("Input is wrong.Please, fill up all fields.");
        return;
    }
    this->hide();
    emit loginButtonClicked(login.toStdString(),password.toStdString());

}

void LoginView::ShowErrorMessage(const string &message) {
    auto* msgBox = new QMessageBox();
    msgBox->setText(QString::fromStdString(message));
    msgBox->exec();

    delete msgBox;
    show();
}



#include "mainview.h"
#include "ui_mainview.h"
#include <QFileDialog>
#include <QMainWindow>
#include <string>
#include <QSqlDatabase>
#include <QMessageBox>
#include "../Utils/Util.h"
using namespace std;

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
{
    ui->setupUi(this);
    ui->notesTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->notesTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->notesTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->notesTableWidget->setColumnCount(2);
    ui->notesTableWidget->setFixedWidth(280);
    ui->notesTableWidget->setColumnWidth(1,160);

    setupConnections();
}




void MainView::SetupConnections() {
}


MainView::~MainView()
{
    delete ui;
}

void MainView::on_editor_opened() {
    this -> hide();
}

void MainView::on_editor_closing() {
    this -> show();
}





Note MainView::GetSelectedNote() {
    int selectedRowIndex = ui->notesTableWidget->selectionModel()->selectedRows()[0].row();
    return notes[selectedRowIndex];
}

void MainView::on_mainView_loading(std::vector<Note> notes) {
    this->show();
    this->notes = notes;

    ui->notesTableWidget->setRowCount(notes.size());
    ui->notesTableWidget->setColumnWidth(2,200);
    int row = 0;
    for (const Note& note : notes){
        for (int j = 0; j < 2; j++) {
            auto* item = new QTableWidgetItem();
            if (!j)
                item->setText(QString::fromStdString(to_string(note.GetId())));
            else
                item->setText(note.GetInitialDate().toString());

            ui->notesTableWidget->setItem(row, j, item);
        }
        row++;
    }

}

void MainView::on_openButton_clicked() {
    emit OpenNote(GetSelectedNote());
}

void MainView::setupConnections() {
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(on_openButton_clicked()));
    connect(ui->createButton, SIGNAL(clicked()), this, SLOT(on_createButton_clicked()));
}

void MainView::on_createButton_clicked() {
    emit CreateNewNoteButtonClicked();
}








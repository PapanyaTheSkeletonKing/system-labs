#include "editorview.h"
#include "ui_editorview.h"
#include <QDateTime>

EditorView::EditorView(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);

}

EditorView::~EditorView()
{
    delete ui;
}


string EditorView::GetText(){
    return ui->textEdit->toPlainText().toStdString();
}

void EditorView::SetTextToMainField(const string& text){
    ui->textEdit->setText(*new QString(text.c_str()));
}

void EditorView::on_textEdit_textChanged()
{
    if (ui->textEdit->hasFocus())
        textMemento.addTextState(ui->textEdit
        ->toPlainText()
        .toStdString());
}

void EditorView::on_undoButton_clicked()
{
    textMemento.undo();
    ui->textEdit->setText(QString::fromStdString(textMemento.getLastStateText()));
}

void EditorView::on_restoreBtn_clicked()
{
    textMemento.redo();
    ui->textEdit->setText(QString::fromStdString(textMemento.getLastStateText()));
}

void EditorView::on_saveButton_clicked()
{
    selectedNote.SetText(GetText());
    emit saveButtonClicked(selectedNote);
}

void EditorView::on_Editor_destroyed()
{

}

void EditorView::on_pushButton_clicked()
{
    this->hide();
    emit closeButtonClicked();
}

void EditorView::on_loadTextFromDb(Note note) {
    this->show();
    textMemento = *new Memento;
    selectedNote = note;
    SetTextToMainField(note.GetText());
}



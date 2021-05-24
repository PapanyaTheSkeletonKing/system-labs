#ifndef EDITOR_H
#define EDITOR_H

#include <QWindow>
#include <QMainWindow>
#include "../Utils/filemanager.h"
#include "../App/memento.h"
#include "../DAL/Note.h"

namespace Ui {
class Editor;
}

class EditorView : public QMainWindow
{
    Q_OBJECT


public:
    explicit EditorView(QMainWindow* parent = nullptr);

    ~EditorView();
    void SetTextToMainField(const string& text);
    string GetText();


public slots:
    void on_textEdit_textChanged();
    void on_undoButton_clicked();

    void on_loadTextFromDb(Note note);

    void on_saveButton_clicked();

    void on_Editor_destroyed();

    void on_pushButton_clicked();

    void on_restoreBtn_clicked();

    signals:
    void saveButtonClicked(Note);
    void closeButtonClicked();


private:
    string LoadTextFromFile(const string& filePath);
    Ui::Editor *ui;
    Memento textMemento;
    Note selectedNote;

};

#endif // EDITOR_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "editorview.h"
#include "../DAL/User.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    Note GetSelectedNote();
    void setupConnections();

    MainView(QWidget *parent = nullptr);
    ~MainView();
signals:
public slots:
    void on_openButton_clicked();

    void on_createButton_clicked();

    void on_mainView_loading(std::vector<Note> notes);

    void on_editor_opened();

    void on_editor_closing();

    signals:
    void OpenNote(Note);
    void CreateNewNoteButtonClicked();

private:
    Ui::MainView *ui;
    void SetupConnections();
    vector<Note> notes;

};
#endif // MAINWINDOW_H

//
// Created by Vyatalech on 26.04.2021.
//

#include <Qt>
#include "../View/mainview.h"
#include "../DAL/NotesRepository.h"
#include "../DAL/UserRepository.h"
#include "../View/loginview.h"
#include "../DAL/clientsocket.h"

class MainPresenter : QObject {
Q_OBJECT
public:

    MainPresenter(MainView *main_view,LoginView* login_view,EditorView* editor_View);
    ~MainPresenter();


    void ConnectToViews();


public slots:
    //UI Slots
    void on_loginRequested(std::string,std::string);
    void on_open_editorWithNote(Note);
    void on_open_editorWithNewNote();
    void on_save_note(Note);
    void on_editor_closing();
    //Socket slots
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void onResponseParse(const QByteArray& responseData);


signals:
    void LoadMainView(std::vector<Note>);
    void OpenEditorView(Note note);
private:
    void setupSocket( int host_port);

    EditorView *editor_view;
    MainView *main_view;
    LoginView *login_view;

    User connectedUser;
    Note currentNote;

    QSqlDatabase sqlDatabase;
    UserRepository *userRepository;

    ClientSocket *socket;

    //void ConnectMainViewToEditor();
};


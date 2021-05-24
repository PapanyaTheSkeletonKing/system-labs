#include <QApplication>
#include <QPushButton>
#include "../View/mainview.h"
#include "../View/loginview.h"
#include "../Presenter/main_presenter.h"

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    auto startWindow = new LoginView();
    auto mainPresenter = new MainPresenter(new MainView(),startWindow,new EditorView());
    startWindow->show();
    return QApplication::exec();
}

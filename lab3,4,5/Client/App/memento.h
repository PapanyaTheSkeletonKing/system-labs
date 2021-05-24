//
// Created by Vyatalech on 13.04.2021.
//
#include <string>
#include <vector>

using namespace std;

class Memento {
public:
    Memento();

    void undo();
    void redo();

    void addTextState(const string&);
    string& getLastStateText();


private:
    vector<string>* undoStates = new vector<string>(0);
    vector<string>* redoStates = new vector<string>(0);


};


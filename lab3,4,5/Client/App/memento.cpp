//
// Created by Vyatalech on 13.04.2021.
//

#include "memento.h"

string &Memento::getLastStateText() {
    return undoStates->back();
}

Memento::Memento() {
    undoStates->push_back("");
    redoStates->push_back("");
}

void Memento::addTextState(const string &newState) {
    undoStates->push_back(newState);
}

void Memento::undo() {
    redoStates->push_back(undoStates->back());
    undoStates->pop_back();
}

void Memento::redo(){
    if(!redoStates->empty()) {
        undoStates->push_back(redoStates->back());
        redoStates->pop_back();
    }
}


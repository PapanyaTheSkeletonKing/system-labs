#include "filemanager.h"
#include <iostream>
#include <fstream>

using namespace std;

FileManager::FileManager() {}

string FileManager::ReadTextFromFile(const string& filepath){
    if (filepath == ""){
        return "";
    }

    string text;
    string finalString;
    ifstream File(filepath);

    while (getline(File,text)){
        finalString += text;
    }

    File.close();
    return finalString;
}

void FileManager::WriteToFile(const string& text,
                              const string& name,
                              const string& extension){
    string filename = "D:\\notes\\" + name + extension;

    ofstream toWrite(filename);
    toWrite << text;
    toWrite.close();
}

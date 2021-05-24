#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>

using namespace std;

class FileManager
{
public:
    FileManager();
    static string ReadTextFromFile(const string& filename);
    void WriteToFile(const string& text,
                     const string& filename);

    static void WriteToFile(const string &text, const string &filename, const string &extension);
};

#endif // FILEMANAGER_H

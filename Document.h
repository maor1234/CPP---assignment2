/* Yarin Knafo - 205580624
 * Maor Cohen - 301729414 */

#ifndef MATALA2_DOCUMENT_H
#define MATALA2_DOCUMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Document {

private:
    vector<string> theText;
    int currentLine;

public:

    Document();

    void print();
    void printCurrentLine();
    void printAll();

    void changeCurrentLine(int lineNumber);

    void append();
    void insert();
    void change();

    void deleteCurrentLine();

    void search(string substring);
    void replace(string oldString, string changeTo);
    
    bool checkValidInput();
    bool checkValidInput(int lineNumber);
};


#endif //MATALA2_DOCUMENT_H

/* Yarin Knafo - 205580624
 * Maor Cohen - 301729414 */

#include "Document.h"

using namespace std;

Document::Document() : currentLine(-1) {}


void Document::print() {

    if (checkValidInput()) return;

    cout << this->theText[this->currentLine] << endl;
}


void Document::printCurrentLine() {

    if (checkValidInput()) return;

    cout << this->currentLine + 1 << "\t";
    this->print();
}


void Document::changeCurrentLine(int lineNumber) {

    lineNumber--;
    if (checkValidInput(lineNumber)) return;

    this->currentLine = lineNumber;
    this->print();
}


void Document::printAll() {

    if (checkValidInput()) return;

    for (string &line : theText)
        cout << line << endl;

}


void Document::append() {

    string line;
    vector<string>::iterator it;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, line);

    while (line != ".") {
        it = theText.begin();
        this->currentLine++;
        this->theText.insert(it + this->currentLine, line);
        getline(cin, line);
    }
}


void Document::insert() {

    string line;
    vector<string>::iterator it;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, line);

    if (this->currentLine == -1)
        this->currentLine =0;

    while (line != ".") {
        it = theText.begin();
        this->theText.insert(it + this->currentLine, line);
        this->currentLine++;
        getline(cin, line);
    }
}


void Document::change() {

    if (checkValidInput()) return;

    this->deleteCurrentLine();
    this->append();
}


void Document::deleteCurrentLine() {

    if (checkValidInput()) return;

    vector<string>::iterator it;
    it = theText.begin();
    this->theText.erase(it + this->currentLine);
    this->currentLine--;
}


void Document::search(string substring) {

    if (checkValidInput()) return;

    for (int i = this->currentLine; i < this->theText.size(); i++) {
        if (this->theText[i].find(substring) != -1) {
            cout << this->theText[i] << endl;
            this->currentLine = i;
            return;
        }
    }
    for (int i = 0; i < this->currentLine; i++) {
        if (this->theText[i].find(substring) != -1) {
            cout << this->theText[i] << endl;
            this->currentLine = i;
            return;
        }
    }
     cout << "invalid input" << endl;
}


void Document::replace(string oldString, string changeTo) {

    if (checkValidInput()) return;

    if (this->theText[this->currentLine].find(oldString) != -1) {
        int indexInLine = this->theText[this->currentLine].find(oldString);
        this->theText[this->currentLine].replace(indexInLine, oldString.size(), changeTo);
    }
    else
         cout << "invalid input" << endl;

}

bool Document::checkValidInput(){

    if (this->currentLine == -1){
        cout << "invalid input" << endl;
        return true;
    }

    return false;
}

bool Document::checkValidInput(int lineNumber) {

    if (this->theText.size() <= lineNumber) {
        cout << "invalid input" << endl;
        return true;
    }

    return false;
}

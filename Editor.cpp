/* Yarin Knafo - 205580624
 * Maor Cohen - 301729414 */

#include "Editor.h"

using namespace std;


Editor::Editor(){}


comnd Editor::checkInput(string const &input) {

    //Check all possibilities in the text and return the correct command
    if (input == "p")
        return comnd::printCurrentLine;
    else if (input == "n")
        return comnd::printLineNum;
    else if (input == "%p")
        return comnd::printAll;

    //Convert the input to number
    int lineNumber = atoi(input.c_str());

    if (lineNumber > 0) {
        doc.changeCurrentLine(lineNumber);
        return comnd::makeCurrent;
    }
    else if (input == "a")
        return comnd::append;
    else if (input == "i")
        return comnd::insert;
    else if (input == "c")
        return comnd::change;
    else if (input == "d")
        return comnd::deleteLine;
    else if (input.at(0) == '/')
        return comnd::search;
    else if (input.at(0) == 's')
        return comnd::replace;
    else if (input == "Q")
        return comnd::quit;


}


void Editor::loop() {
    while (1) {
        string line;
        cin >> line;
        int lineLen = line.size();
        switch (checkInput(line)) {
            case comnd::printCurrentLine:
                doc.print();
                break;
            case comnd::printLineNum:
                doc.printCurrentLine();
                break;
            case comnd::printAll:
                doc.printAll();
                break;
            case comnd::makeCurrent:
                break;
            case comnd::append:
                doc.append();
                break;
            case comnd::insert:
                doc.insert();
                break;
            case comnd::change:
                doc.change();
                break;
            case comnd::deleteLine:
                doc.deleteCurrentLine();
                break;
            case comnd::search:
                doc.search(line.substr(1,lineLen));
                break;
            case comnd::replace:
                if (line.substr(2, lineLen).find('/')  != -1) {
                    int indexInLine = line.substr(2, lineLen).find('/');
                    doc.replace(line.substr(2, indexInLine), line.substr(indexInLine + 3, lineLen - (indexInLine + 4)));
                }
                else
                     cout << "invalid input" << endl;
                break;
            case comnd::quit:
                exit(0);
            default:
                 cout << "invalid input" << endl;
        }
    }
}
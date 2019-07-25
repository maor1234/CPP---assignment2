/* Yarin Knafo - 205580624
 * Maor Cohen - 301729414 */

#ifndef MATALA2_EDITOR_H
#define MATALA2_EDITOR_H

#include "Document.h"
#include <sstream>

using namespace std;

enum class comnd {
    printCurrentLine,
    printLineNum,
    printAll,
    makeCurrent,
    append,
    insert,
    change,
    deleteLine,
    search,
    replace,
    quit
};

class Editor {

private:
    Document doc;
    comnd checkInput(string const &input);

public:
    Editor();
    void loop();

};


#endif //MATALA2_EDITOR_H

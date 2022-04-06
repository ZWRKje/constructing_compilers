#include <fstream>
#include <locale>
#include <stack>

#include "TNode.h"
#include "TStateM.h"

int main() {
    std::setlocale(LC_ALL, "ru");
    TStateM exmpl;
    char ch;
    std::ifstream in("a.txt");
    if (!in.is_open()) return 1;

    std::istreambuf_iterator<char> it(in);
    std::istreambuf_iterator<char> oef;
    std::string str(it, oef);
    size_t i = 0;

    while ((exmpl.cond() != STOP) && (exmpl.cond() != ERROR)) {
        ch = str[i];
        exmpl.change(ch);
        i++;
    }
    exmpl.isRealy(exmpl.root());

    if (exmpl.cond() == ERROR) {
        std::cout << "Неверные входные данные";
        return 1;
    }
    exmpl.printTree(exmpl.root(), 0);

    return 0;
}
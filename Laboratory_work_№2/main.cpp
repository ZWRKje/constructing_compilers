#include <fstream>
#include <locale>
#include <stack>

#include "TNode.h"
#include "TStateM.h"

void printTree(TNode elem, int ident) {
    TNode* child;
    std::cout << std::string(ident++, ' ') << elem.areaName() << ": ";
    std::cout << elem.areaSize() << std::endl;
    for (auto& example : elem.childs()) {
        child = example;
        printTree(*child, ident);
    }
}

int main() {
    std::setlocale(LC_ALL, "ru");
    TStateM exmpl;
    char ch;
    std::ifstream in("a.txt");
    if (!in.is_open()) return 1;

    while ((exmpl.cond() != S) && (exmpl.cond() != E)) {
        in >> ch;
        exmpl.change(ch);
    }

    printTree(exmpl.root(), 0);

    return 0;
}
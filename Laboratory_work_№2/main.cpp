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

void isRealy(TNode elem) {
    TNode* child;
    int size = 0;
    if (!elem.childs().empty()) {
        for (auto& examale : elem.childs()) {
            size += examale->areaSize();
        }
        if (elem.areaSize() != size) {
            std::cout << "Неверные входные данные" << std::endl;
            return;
        }
    }

    for (auto& example : elem.childs()) {
        child = example;
        isRealy(*child);
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

    isRealy(exmpl.root());
    printTree(exmpl.root(), 0);

    return 0;
}
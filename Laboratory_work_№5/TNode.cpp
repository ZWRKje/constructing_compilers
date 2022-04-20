#include "TNode.h"

#include <iostream>
#include <string>

void printTree(const TNode& tree, int ident) {
    TNode* child;
    std::cout << std::string(ident++, ' ') << tree._name << ":" << tree._val
              << std::endl;
    if (tree._child != 0) {
        child = tree._child;
        do {
            printTree(*child, ident);
            child = child->_brother;
        } while (child != 0);
    }
}

bool TNode::check(TNode& root) {
    TNode* child;
    static bool flag = false;
    static int size = 0;
    if (root._child != 0) {
        child = root._child;
        do {
            check(*child);
            size += child->_val;
            child = child->_brother;
        } while (child != 0);

        if (root._child == child) {
            flag = true;
        }
        if (root._val != size) {
            flag = false;
        }
        size = 0;
    }

    return flag;
}
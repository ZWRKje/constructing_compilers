#ifndef TNODE_H
#define TNODE_H

#include <string>
#include <vector>

class TNode {
   public:
    int _val;
    std::string _name;
    TNode* _child;
    TNode* _brother;
    TNode() {
        _val = 0;
        _child = 0;
        _brother = 0;
        _name = "root";
    }
    int setVal(int val) {
        if (val < 1 || val > 999) {
            return -1;
        }
        _val = val;
        return _val;
    }
    void setName(const std::string& val) { _name = val; };
    void addChild(TNode*& node) { _child = node; }
    void addBrother(TNode*& node) { _brother = node; }
    bool check(TNode& root);
};

void printTree(const TNode& tree, int ident);

#endif
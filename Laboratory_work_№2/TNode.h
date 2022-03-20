#ifndef TNODE_H
#define TNODE_H
#include <iostream>
#include <string>
#include <vector>

class TNode {
   protected:
    int _areaSize;
    std::string _areaName;
    std::vector<TNode*> _chlids;

   public:
    TNode() { _areaName = "Земля"; };
    ~TNode(){};
    void setSize(int newAreaSize);
    void setName(std::string newAreaName);
    int areaSize();
    std::string areaName();
    std::vector<TNode*> childs();
    TNode* addChild(const int& newAreaSize, const std::string& newAreaName);
};

#endif
#include "TNode.h"

void TNode::setSize(int newAreaSize) { _areaSize = newAreaSize; }

int TNode::childSize() {
    int size = 0;
    for (auto& elem : _chlids) {
        size += elem->areaSize();
    }
    return size;
}

void TNode::setName(std::string newAreaName) { _areaName = newAreaName; }

int TNode::areaSize() { return _areaSize; }

std::string TNode::areaName() { return _areaName; }

std::vector<TNode*> TNode::childs() { return _chlids; }

TNode* TNode::addChild(const int& newAreaSize, const std::string& newAreaName) {
    TNode* newNode = new TNode();
    newNode->setSize(newAreaSize);
    newNode->setName(newAreaName);
    _chlids.push_back(newNode);
    return newNode;
}
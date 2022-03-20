#include "TNode.h"

void TNode::setValue(char newAreaSize) {
	_areaSize = newAreaSize - '0';
}

TNode* TNode::addChild(int newAreaSize) {
	TNode* newNode = new TNode();
	newNode->setValue(newAreaSize);
	_chlids.push_back(newNode);
	return newNode;
}

int TNode::areaSize() {
	return _areaSize;
}

std::vector<TNode*> TNode::childs() {
	return _chlids;
};
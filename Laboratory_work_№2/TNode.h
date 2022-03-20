#ifndef TNODE_H
#define TNODE_H
#include <vector>
#include <iostream>
#include <string>

class TNode {
protected:
	int _areaSize;
	std::vector<TNode*> _chlids;
public:
	TNode() { _areaSize = 0; };
	~TNode() {};
	void setValue(char newAreaSize);
	TNode* addChild(int newAreaSize);
	int areaSize();
	std::vector<TNode*> childs();
};

#endif 
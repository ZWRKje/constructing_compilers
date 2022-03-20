#define _CRT_SECURE_NO_WARNINGS

#include "TNode.h"
#include <stack>
#include <fstream>

enum tCondition { W, S, E };
FILE* pFile;
TNode root;
TNode* parent = &root;
TNode* lval = &root;
std::stack<TNode*> st;


void nextCh(std::ifstream& in, char& ch) {
	in >> ch;
}

enum tCondition change(enum tCondition cond, char ch) {
	switch (cond) {
	case W: {
		if (isdigit(ch)) {
			lval = parent->addChild(ch);
			return W;
		}
		if (ch == '{') {
			st.push(parent);
			parent = lval;
			return W;
		}
		if (ch == '}') {
			if (!st.empty()) {
				parent = st.top();
				st.pop();
			}
			else return S;
			return W;
		}
		if (ch == '\n') {
			if (!st.empty()) 
				return E;
			else
				return S;
		}
	}
	case E: {
		std::cout << "Синтаксическая ошибка!! \n";
		return S;
	}
	case S: {
		return S;
	}
	default: return E;
	};

}

void printTree(TNode& elem, int ident) {
	TNode* child;
	std::cout << std::string(ident++, ' ') << elem.areaSize() << std::endl;
	for (auto& example : elem.childs()) {
		child = example;
		printTree(*child, ident);
	}
}



int main() {
	enum tCondition c = W;
	char ch;
	std::ifstream in("a.txt");
	if (!in.is_open()) return 1;

	while (c != S) {
		nextCh(in, ch);
		c = change(c, ch);
	}
	printTree(root, 0);
	return (0);

	return 0;
}
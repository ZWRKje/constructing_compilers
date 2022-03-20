#define _CRT_SECURE_NO_WARNINGS

#include "TNode.h"
#include <stack>
#include <fstream>
#include <locale>

enum tCondition { W, N, A, S, E };
FILE* pFile;
TNode root;
TNode* parent = &root;
TNode* lval = &root;
std::stack<TNode*> st;

void nextCh(std::ifstream& in, char& ch) {
	in >> ch;
}

//void nextArea(std::ifstream& in, std::string& ch) {
//	char smb;
//	int count = 0;
//
//	std::string name = "";
//	std::string buf = "";
//	int size = 0;
//	bool flag = false;
//
//	while (count != 2) {
//		in.get(smb);
//		if (smb == '|') {
//			count++;
//			continue;
//		}
//		if (smb == ':') {
//			flag = true;
//			continue;
//		}
//		if (flag) { // rework
//			buf += smb;
//		}
//		else name += smb;
//	};
//	std::cout << name;
//	std::cout << buf;
//	size = std::stoi(buf);
//
//}

enum tCondition change(enum tCondition cond, char ch) {
	static std::string name = "";
	static std::string buf = "";
	static int size = 0;
	if (name == "Область1") {
		int a = 0;
	}
	switch (cond) {
	case W: {
		if (ch == '|') {
			return N;
		}
		if (ch == '\n') {
			return S;
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
	}
	case N: {
		if (ch != ':') {
			name += ch;
			return N;
		}
		if (ch == ':') {
			return A;
		}

	}
	case A: {
		if (ch != '|') {
			buf += ch;
			return A;
		}
		if (ch == '|') {
			size = std::stoi(buf);
			lval = parent->addChild(size, name);
			buf = name = "";
			size = 0;
			return W;
		}
	}
	case S:{
		return S;
	}
	default: break;
	}
};

void printTree(TNode& elem, int ident) {
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
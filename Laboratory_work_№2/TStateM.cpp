#include "TStateM.h"

TStateM::TStateM() {
    _cond = START;
    _parent = &_root;
    _lval = &_root;
}

TNode TStateM::root() { return _root; }

tCondition TStateM::cond() { return tCondition(_cond); }

void TStateM::change(char ch) {
    static char prev = ' ';
    static std::string number = "";
    static std::string name = "";
    int size = 0;
    if (dic.find(ch) == dic.end()) {
        std::cout << "Недопустимы символ \n";
        _cond = ERROR;
        return;
    }
    switch (_cond) {
        case START: {
            if (ch == '{') {
                prev = ch;
                st.push(_parent);
                _parent = _lval;
                _cond = WORD;
                break;
            }
            _cond = ERROR;
            break;
        }
        case WORD: {
            if (ch == ':') {
                _cond = NUMBER;
                break;
            }
            if (ch >= 'А' && ch <= 'я' || ch <= '9' && ch >= '0') {
                name += ch;
                break;
            }
            if (prev == '{' && ch == '}') {
                _cond = ERROR;
                break;
            }
            if (ch == '}' && !st.empty()) {
                prev = ' ';
                _parent = st.top();
                st.pop();
                break;
            }
            if (ch == '\n') {
                _root.setSize(_root.childSize());
                _cond = STOP;
                break;
            }
            _cond = ERROR;
            break;
        }
        case NUMBER: {
            if (ch <= '9' && ch >= '0') {
                number += ch;
                break;
            }
            if (ch >= 'А' && ch <= 'я') {
                _cond = WORD;
                size = std::stoi(number);
                _lval = _parent->addChild(size, name);
                number = name = "";
                size = 0;
                name += ch;
                break;
            }
            if (ch == '{') {
                if (number.empty()) {
                    _cond = ERROR;
                    break;
                }
                if (!st.empty()) {
                    _cond = WORD;
                    size = std::stoi(number);
                    _lval = _parent->addChild(size, name);
                    st.push(_lval);
                    _parent = _lval;
                    number = name = "";
                    size = 0;
                    break;
                } else {
                    _cond = ERROR;
                    break;
                }
                _cond = START;
                break;
            }
            if (ch == '}') {
                if (number.empty()) {
                    _cond = ERROR;
                    break;
                }
                if (!st.empty()) {
                    _parent = st.top();
                    st.pop();
                    size = std::stoi(number);
                    _lval = _parent->addChild(size, name);
                    if (st.empty())
                        _parent = &_root;
                    else
                        _parent = st.top();
                    number = name = "";
                    size = 0;
                    prev = ' ';
                } else {
                    _root.setSize(_root.childSize());
                    _cond = STOP;
                    break;
                }
                _cond = WORD;
                break;
            }
            _cond = ERROR;
            break;
        }
        default:
            break;
    }
}

void TStateM::printTree(TNode elem, int ident) {
    TNode* child;
    std::cout << std::string(ident++, ' ') << elem.areaName() << ": ";
    std::cout << elem.areaSize() << std::endl;
    for (auto& example : elem.childs()) {
        child = example;
        printTree(*child, ident);
    }
}

void TStateM::isRealy(TNode elem) {
    TNode* child;
    int size = 0;
    if (!elem.childs().empty()) {
        for (auto& examale : elem.childs()) {
            size += examale->areaSize();
        }
        if (elem.areaSize() != size) {
            _cond = ERROR;
            return;
        }
    }

    for (auto& example : elem.childs()) {
        child = example;
        isRealy(*child);
    }
}
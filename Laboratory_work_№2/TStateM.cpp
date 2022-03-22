#include "TStateM.h"

TStateM::TStateM() {
    _cond = W;
    _parent = &_root;
    _lval = &_root;
}

void TStateM::change(char ch) {
    static std::string name = "";
    static std::string buf = "";
    static int size = 0;
    if (dic.find(ch) == dic.end()) {
        std::cout << "Недопустимы символ \n";
        _cond = E;
        return;
    }
    switch (_cond) {
        case W: {
            if (ch == '|') {
                _cond = N;
                break;
            }
            if (ch == '\n') {
                _cond = S;
                break;
            }
            if (ch == '{') {
                st.push(_parent);
                _parent = _lval;
                _cond = W;
                break;
            }
            if (ch == '}') {
                if (!st.empty()) {
                    _parent = st.top();
                    st.pop();
                } else {
                    _cond = S;
                    break;
                }
                _cond = W;
                break;
            }
        }
        case N: {
            if (ch != ':') {
                name += ch;
                _cond = N;
                break;
            }
            if (ch == ':') {
                _cond = A;
                break;
            }
        }
        case A: {
            if (ch != '|') {
                buf += ch;
                _cond = A;
                break;
            }
            if (ch == '|') {
                size = std::stoi(buf);
                _lval = _parent->addChild(size, name);
                buf = name = "";
                size = 0;
                _cond = W;
                break;
            }
        }
        case S: {
            _cond = S;
            break;
        }
        default:
            break;
    }
}

TNode TStateM::root() { return _root; }
tCondition TStateM::cond() { return tCondition(_cond); }
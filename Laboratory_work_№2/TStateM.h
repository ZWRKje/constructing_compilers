#ifndef TSTATE_M
#define TSTATE_M
#include <set>
#include <stack>

#include "TNode.h"

enum tCondition { W, N, A, S, E };

class TStateM {
   private:
    std::set<int> dic{
        'А', 'а', 'Б', 'б', 'В', 'в', 'Г', 'г', 'Д', 'д', 'Е', 'е', 'Ё', 'ё',
        'Ж', 'ж', 'З', 'з', 'И', 'и', 'Й', 'й', 'К', 'к', 'Л', 'л', 'М', 'м',
        'Н', 'н', 'О', 'о', 'П', 'п', 'Р', 'р', 'С', 'с', 'Т', 'т', 'У', 'у',
        'Ф', 'ф', 'Х', 'х', 'Ц', 'ц', 'Ч', 'ч', 'Ш', 'ш', 'Щ', 'щ', 'Ъ', 'ъ',
        'Ы', 'ы', 'Ь', 'ь', 'Э', 'э', 'Ю', 'ю', 'Я', 'я', ':', '|', '{', '}',
        '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\n'};

    enum tCondition _cond;
    TNode _root;
    TNode* _parent;
    TNode* _lval;
    std::stack<TNode*> st;

   public:
    TStateM();
    ~TStateM(){};
    TNode root();
    tCondition cond();
    void change(char ch);
};

#endif
#ifndef TINPUTM_H
#define TINPUTM_H

#include <vector>
#include "TStateM.h"

class TInputM {
private:
	std::vector<int> _outerCall;
	std::vector<int> _innerCall;
	std::vector<int> _curQue;
	TStateM* _elevator;
public:
	TInputM(TStateM& elevator);
	~TInputM();
	int dest();
	bool data(int num);

};

#endif 
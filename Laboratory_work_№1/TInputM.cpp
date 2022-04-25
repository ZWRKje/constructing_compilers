#include "TInputM.h"
#include <iostream>
#include <string>
#include <algorithm>

TInputM::TInputM(TStateM& elevator) {
	_elevator = &elevator;
};

TInputM::~TInputM() {};


bool TInputM::data(int num) {
	if (num == -1) {
		std::cout << "Лифт ждёт нажатий на кнопки на " << _elevator->getCurPoz() << " этаже " << std::endl;
	}
	std::string input = "";
	std::string output = "";

	std::cout << "Нажатие кнопки на внешней панели: ";
	std::getline(std::cin, input);

	for (int i = 0; i < input.size(); i++) {
		if (!isdigit(input[i])) {
			return false;
		}
		else {
			_outerCall.push_back(input[i] - '0');
		}
	}
	std::sort(_outerCall.begin(), _outerCall.end());

	std::cout << "Нажатие кнопки на внутреней панели: ";
	std::getline(std::cin, output);
	for (int i = 0; i < output.size(); i++) {
		if (!isdigit(output[i])) {
			return false;
		}
		else {
			_innerCall.push_back(output[i] - '0');
		}
	}
	std::sort(_innerCall.begin(), _innerCall.end());
	return true;
}

//ПАМАГИТЕ!!!!!!!

int TInputM::dest() {
	if (_elevator->getDir() == UP) {
		if (!_innerCall.empty()) {
			return _innerCall[0];
		}
		else {
			return _outerCall.back();
		}
	}

	if (_elevator->getDir() == DOWN) {
		for (const auto& example : _outerCall) {
			if (example < _elevator->getCurPoz()) {
				_curQue.push_back(example);
				_outerCall.erase(_outerCall.begin() + _outerCall.size() - 1);
			}
		}
		for (const auto& example : _innerCall) {
			if (example < _elevator->getCurPoz()) {
				_curQue.push_back(example);
				_innerCall.erase(_innerCall.begin() + _innerCall.size() - 1);
			}
		}
		std::sort(_curQue.begin(), _curQue.end());
		return _curQue.back();;
	}

	if (_elevator->getDir() == STOP) {
		if (!_curQue.empty()) {
			auto it = std::find(_curQue.begin(), _curQue.end(), _elevator->getCurPoz());
			if (it != _curQue.end()) _curQue.erase(it);

			it = std::find(_innerCall.begin(), _innerCall.end(), _elevator->getCurPoz());
			if (it != _innerCall.end()) _innerCall.erase(it);

			it = std::find(_outerCall.begin(), _outerCall.end(), _elevator->getCurPoz());
			if (it != _outerCall.end()) _outerCall.erase(it);

			if (!_curQue.empty()) {
				return _curQue.back();
			}
			else {
				return -1;
			}
		}
		if (!_innerCall.empty()) {
			auto it = std::find(_innerCall.begin(), _innerCall.end(), _elevator->getCurPoz());
			if (it != _innerCall.end()) _innerCall.erase(it);
			if (!_innerCall.empty()) {
				return _innerCall.front();
			}
			else {
				return -1;
			}

		}
		else {
			auto it = std::find(_outerCall.begin(), _outerCall.end(), _elevator->getCurPoz());
			if (it != _outerCall.end()) _outerCall.erase(it);
			if (!_outerCall.empty()) {
				return _outerCall.back();
			}
			else {
				return -1;
			}
		}
	}
}
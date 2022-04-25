#include "TStateM.h"
#include <iostream>

TStateM::TStateM() {
	_state = FIRST_S;
	_curPoz = 1;
}

TStateM::~TStateM() {}


void TStateM::work(int input) {
	// В STOP BREAK по ERROR INPUT
	switch (_state) {
		// Состояния первого этажа
	case FIRST_S: {
		std::cout << "Лифт стоит на первом этаже" << std::endl;
		_direction = STOP;
		_curPoz = 1;
		if (input >= 2 && input <= 8) {
			_direction = UP;
			_state = FIRST_U;
			break;
		}
		break;
	}
	case FIRST_U: {
		std::cout << "Лифт едет вверх с первого этажа на второй " << std::endl;
		_direction = UP;
		_curPoz = 1;
		if (input >= 3 && input <= 8) {
			_direction = UP;
			_state = SECOND_U;
			break;
		}
		if (input == 2) {
			_state = SECOND_S;
			break;
		}
		break;
	}
				// Состояния второго этажа
	case SECOND_U: {
		std::cout << "Лифт едет вверх со второго этажа на третий " << std::endl;
		_direction = UP;
		_curPoz = 2;
		if (input == 3) {
			_state = THIRD_S;
			break;
		}
		if (input >= 4 && input <= 8) {
			_direction = UP;
			_state = THIRD_U;
			break;
		}
		break;
	}
	case SECOND_S: {
		std::cout << "Лифт стоит на втором этаже" << std::endl;
		_direction = STOP;
		_curPoz = 2;
		if (input >= 3 && input <= 8) {
			_direction = UP;
			_state = SECOND_U;
			break;
		}
		if (input == 1) {
			_direction = DOWN;
			_state = SECOND_D;
			break;
		}
		break;
	}
	case SECOND_D: {
		std::cout << "Лифт едет вниз с второго этажа на первый " << std::endl;
		_direction = DOWN;
		_curPoz = 2;
		if (input == 1) {
			_state = FIRST_S;
			break;
		}
		break;
	}
				 // Состояния третьего этажа
	case THIRD_U: {
		std::cout << "Лифт едет вверх с третьего этажа на четвёртый " << std::endl;
		_direction = UP;
		_curPoz = 3;
		if (input == 4) {
			_state = FOUR_S;
			break;
		}
		if (input >= 5 && input <= 8) {
			_direction = UP;
			_state = FOUR_U;
			break;
		}
		break;
	}
	case THIRD_S: {
		std::cout << "Лифт стоит на третьем этаже" << std::endl;
		_direction = STOP;
		_curPoz = 3;
		if (input >= 4 && input <= 8) {
			_direction = UP;
			_state = THIRD_U;
			break;
		}
		if (input <= 2 && input >= 1) {
			_direction = DOWN;
			_state = THIRD_D;
			break;
		}
		break;
	}
	case THIRD_D: {
		std::cout << "Лифт едет вниз с третьего этажа на второй " << std::endl;
		_direction = DOWN;
		_curPoz = 3;
		if (input == 1) {
			_state = SECOND_D;
			break;
		}
		if (input == 2) {
			_state = SECOND_S;
			break;
		}
		break;
	}
				// Состояния четвёртого этажа
	case FOUR_U: {
		std::cout << "Лифт едет вверх с четвёртого этажа на пятый " << std::endl;
		_direction = UP;
		_curPoz = 4;
		if (input == 5) {
			_state = FIFTH_S;
			break;
		}
		if (input >= 6 && input <= 8) {
			_direction = UP;
			_state = FIFTH_U;
			break;
		}
		break;
	}
	case FOUR_S: {
		std::cout << "Лифт стоит на четвёртом этаже" << std::endl;
		_direction = STOP;
		_curPoz = 4;
		if (input >= 5 && input <= 8) {
			_direction = UP;
			_state = FOUR_U;
			break;
		}
		if (input <= 3 && input >= 1) {
			_direction = DOWN;
			_state = FOUR_D;
			break;
		}
		break;
	}
	case FOUR_D: {
		std::cout << "Лифт едет вниз с четвёртого этажа на третий " << std::endl;
		_direction = DOWN;
		_curPoz = 4;
		if (input >= 1 && input <= 2) {
			_direction = DOWN;
			_state = THIRD_D;
			break;
		}
		if (input == 3) {
			_state = THIRD_S;
			break;
		}
		break;
	}
			   // Состояния пятого этажа
	case FIFTH_U: {
		std::cout << "Лифт едет вверх с пятого этажа на шестой " << std::endl;
		_direction = UP;
		_curPoz = 5;
		if (input == 6) {
			_state = SIXTH_S;
			break;
		}
		if (input >= 7 && input <= 8) {
			_direction = UP;
			_state = SIXTH_U;
			break;
		}
		break;
	}
	case FIFTH_S: {
		std::cout << "Лифт стоит на пятом этаже" << std::endl;
		_direction = STOP;
		_curPoz = 5;
		if (input >= 6 && input <= 8) {
			_direction = UP;
			_state = FIFTH_U;
			break;
		}
		if (input <= 4 && input >= 1) {

			_direction = DOWN;
			_state = FIFTH_D;
			break;
		}
		break;
	}
	case FIFTH_D: {
		std::cout << "Лифт едет вниз с пятого этажа на четвёртый " << std::endl;
		_direction = DOWN;
		_curPoz = 5;
		if (input >= 1 && input <= 3) {
			_direction = DOWN;
			_state = FOUR_D;
			break;
		}
		if (input == 4) {
			_state = FOUR_S;
			break;
		}
		break;
	}
				// Состояния шестого этажа
	case SIXTH_U: {
		std::cout << "Лифт едет вверх с шестого этажа на седьмой " << std::endl;
		_direction = UP;
		_curPoz = 6;
		if (input == 7) {
			_state = SEVENTH_S;
			break;
		}
		if (input == 8) {
			_direction = UP;
			_state = SEVENTH_U;
			break;
		}
		break;
	}
	case SIXTH_S: {
		std::cout << "Лифт стоит на шестом этаже" << std::endl;
		_direction = STOP;
		_curPoz = 6;
		if (input <= 7 && input >= 8) {
			_direction = UP;
			_state = SIXTH_U;
			break;
		}
		if (input <= 5 && input >= 1) {
			_direction = DOWN;
			_state = SIXTH_D;
			break;
		}
		break;
	}
	case SIXTH_D: {
		std::cout << "Лифт едет вниз с шестого этажа на пятый " << std::endl;
		_direction = DOWN;
		_curPoz = 6;
		if (input >= 1 && input <= 4) {
			_direction = DOWN;
			_state = FIFTH_D;
			break;
		}
		if (input == 5) {
			_state = FIFTH_S;
			break;
		}
		break;
	}
				// Состояния седьмого этажа
	case SEVENTH_U: {
		std::cout << "Лифт едет вверх с седьмого этажа на восьмой " << std::endl;
		_direction = UP;
		_curPoz = 7;
		if (input == 8) {
			_state = EIGHT_S;
			break;
		}
		break;
	}
	case SEVENTH_S: {
		std::cout << "Лифт стоит на седьмом этаже" << std::endl;
		_direction = STOP;
		_curPoz = 7;
		if (input == 8) {
			_direction = UP;
			_state = SEVENTH_U;
			break;
		}
		if (input <= 6 && input >= 1) {
			_direction = DOWN;
			_state = SEVENTH_D;
			break;
		}
		break;
	}
	case SEVENTH_D: {
		std::cout << "Лифт едет вниз с седьмого этажа на шестой " << std::endl;
		_direction = DOWN;
		_curPoz = 7;
		if (input >= 1 && input <= 5) {
			_direction = DOWN;
			_state = SIXTH_D;
			break;
		}
		if (input == 6) {
			_state = SIXTH_S;
			break;
		}
		break;
	}
				  // Состояния восьмого этажа
	case EIGHT_S: {
		std::cout << "Лифт стоит на восьмом этаже" << std::endl;
		_direction = STOP;
		_curPoz = 8;
		if (input <= 7 && input >= 1) {
			_direction = DOWN;
			_state = EIGHT_D;
			break;
		}
		break;
	}
	case EIGHT_D: {
		std::cout << "Лифт едет вниз с восьмого этажа на седьмой " << std::endl;
		_direction = DOWN;
		_curPoz = 8;
		if (input >= 1 && input <= 6) {
			_direction = DOWN;
			_state = SEVENTH_D;
			break;
		}
		if (input == 7) {
			_state = SEVENTH_S;
			break;
		}
		break;
	}
	}
}

int TStateM::getCurPoz() {
	return _curPoz;
}

Direction TStateM::getDir() {
	return _direction;
}

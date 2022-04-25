#ifndef TSTATEM_H
#define  TSTATEM_H
#include <vector>

enum State {
	// Состояния первого этажа
	FIRST_U,
	FIRST_S,

	// Состояния второго этажа
	SECOND_U,
	SECOND_S,
	SECOND_D,

	// Состояния третьего этажа
	THIRD_U,
	THIRD_S,
	THIRD_D,

	// Состояния четвёртого этажа
	FOUR_U,
	FOUR_S,
	FOUR_D,

	// Состояния пятого этажа
	FIFTH_U,
	FIFTH_S,
	FIFTH_D,

	// Состояния шестого этажа
	SIXTH_U,
	SIXTH_S,
	SIXTH_D,

	// Состояния седьмого этажа
	SEVENTH_U,
	SEVENTH_S,
	SEVENTH_D,

	// Состояния восьмого этажа
	EIGHT_S,
	EIGHT_D

};

enum Direction {STOP, UP, DOWN};

class TStateM {
private:
	State _state = FIRST_S;
	int _curPoz;
	Direction _direction = STOP;
public:
	TStateM();
	~TStateM();
	void work(int iput);
	int getCurPoz();
	Direction getDir();
};

#endif 
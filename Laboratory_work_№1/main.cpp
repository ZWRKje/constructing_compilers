#include "TStateM.h"
#include "TInputM.h"
#include <locale>
#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	TStateM elevator;
	TInputM reader(elevator);
	int num = -1;
	while (true) {
		if (reader.data(num)) {
			num = reader.dest();
			if (num == -1) {
				continue;
			}
			elevator.work(num);
		}
		else {
			std::cout << "Неверные входные данные" << std::endl;
			return 1;
		};
	}

	return 0;
}
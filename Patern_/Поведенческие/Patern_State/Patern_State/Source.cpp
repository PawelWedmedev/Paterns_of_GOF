#include"Header.h"


void main()
{
	BaseState *state = new NormalState; // создаем базовое состояние ( нормальное состояние)
	Car car(state);// передаем это состояние в качестве первоначального в конструктор
	car.UseCar();
}


#pragma once
#include<iostream>
#include <windows.h>
#include<typeinfo>
using namespace std;

// В патерне State мы само состояние(или варианты состояний) выносим в отдельный класс И уже в нем что либо 
// меняем или добавляем.Сколько состояний в системе столько нужно делать и классов, на каждое состояние свой класс!!!!
// делаеться один абстрактный класс и от него state1, state2, state3... надо 4 состояние - добавили еще один класс, 5 состояние- класс...

class Car;
class BaseState// абстрактный класс - базовый для всех состояний
{
public:
	virtual void GetNextState(Car& car) = 0;// метод переводит объект в новое состояние ( в нашем случае объект автомобиль по ссылке)
	// каждый раз как состояние объекта будет меняться мы будев вызывать метод GetNextState(), и этот метод будет переводить объект в новое состояние
	virtual void Report(Car& car) = 0;// метод сообщает что делаеться с нашим объектом
};

class Car
{
protected:
	BaseState* _state;// состояние автомобиля
public:
	int _fuel;// количество топлива
	Car()// конструктор без параметров - начальное состояние
	{
		_state = NULL;
		_fuel = 50;
	}
	Car(BaseState* state)
	{
		_state = state;
		_fuel = 50;
	}

	void UseCar()// главный метод -состояния объекта которого мы отслеживаем ((контекст)- в нашем случае автомобиль) 
	{
		while (_state)	
		{
			_state->Report(*this);
			Sleep(500);
		}// пока наш автомобиль находится в нормальном состоянии и _state инициализирован мы для 
		// автомобиля вызываем метод Report() параметр в который должны передать Car.
		// Мы находимся в классе Car поэтому передаем *this.
	}

	void SetState(BaseState* state)// метод изменяет состояние автомобиля
	{
		_state = state;
	}
};

// *********************************************** теперь пишем классы состояний

class NormalState : public BaseState
{
	public:
		virtual void GetNextState(Car& car);
		virtual void Report(Car& car);
};

class OutOfFuelState : public BaseState
{
public:
	virtual void GetNextState(Car& car);
	virtual void Report(Car& car);
};

class RefuelState : public BaseState
{
public:
	virtual void GetNextState(Car& car);
	virtual void Report(Car& car);
};

// ************************************ реализация виртуальных методов для каждого класса состояния:

// Реализация для класса NormalState:
void  NormalState::GetNextState(Car &car)
{
	car.SetState(new OutOfFuelState);// передаем в качестве параметра следующее состояние
}

void  NormalState::Report(Car &car)
{
	cout << " Car is driving " << car._fuel << " "<<typeid(*this).name() << endl;
	while (car._fuel > 0)
	{
		Sleep(1);
		car._fuel -= 5;
		cout << " Car is driving " << car._fuel << " "<<typeid(*this).name() << endl;
	}
	// когдда закончиться бензин мы переходим в новое (следующее) состояние
	NormalState::GetNextState(car); // вызываем метод для перехода в новое состояние 
}


// Реализация для класса OutOfFuelState:
void  OutOfFuelState::GetNextState(Car &car)
{
	car.SetState(new RefuelState);
}

void  OutOfFuelState::Report(Car& car)
{
	cout << " Car is stopped at gas station" << " " << typeid(*this).name()<< endl;
	// все бензин кончился мы перешли в состояние "нет бензина - стоим"
	OutOfFuelState::GetNextState(car);
}


// Реализация для класса RefuelState:
void  RefuelState::GetNextState(Car& car)
{
	// заправились и перходим в нормальное (сдедующее состояние)
	car.SetState(new NormalState);
	car._fuel = 50;
}

void  RefuelState::Report(Car& car)
{
	cout << " Car is refuel at gas station" << " " << typeid(*this).name() << endl;
	RefuelState::GetNextState(car);
}
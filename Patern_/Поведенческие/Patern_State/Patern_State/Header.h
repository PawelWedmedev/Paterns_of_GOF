#pragma once
#include<iostream>
#include <windows.h>
#include<typeinfo>
using namespace std;

// � ������� State �� ���� ���������(��� �������� ���������) ������� � ��������� ����� � ��� � ��� ��� ���� 
// ������ ��� ���������.������� ��������� � ������� ������� ����� ������ � �������, �� ������ ��������� ���� �����!!!!
// ��������� ���� ����������� ����� � �� ���� state1, state2, state3... ���� 4 ��������� - �������� ��� ���� �����, 5 ���������- �����...

class Car;
class BaseState// ����������� ����� - ������� ��� ���� ���������
{
public:
	virtual void GetNextState(Car& car) = 0;// ����� ��������� ������ � ����� ��������� ( � ����� ������ ������ ���������� �� ������)
	// ������ ��� ��� ��������� ������� ����� �������� �� ����� �������� ����� GetNextState(), � ���� ����� ����� ���������� ������ � ����� ���������
	virtual void Report(Car& car) = 0;// ����� �������� ��� ��������� � ����� ��������
};

class Car
{
protected:
	BaseState* _state;// ��������� ����������
public:
	int _fuel;// ���������� �������
	Car()// ����������� ��� ���������� - ��������� ���������
	{
		_state = NULL;
		_fuel = 50;
	}
	Car(BaseState* state)
	{
		_state = state;
		_fuel = 50;
	}

	void UseCar()// ������� ����� -��������� ������� �������� �� ����������� ((��������)- � ����� ������ ����������) 
	{
		while (_state)	
		{
			_state->Report(*this);
			Sleep(500);
		}// ���� ��� ���������� ��������� � ���������� ��������� � _state ��������������� �� ��� 
		// ���������� �������� ����� Report() �������� � ������� ������ �������� Car.
		// �� ��������� � ������ Car ������� �������� *this.
	}

	void SetState(BaseState* state)// ����� �������� ��������� ����������
	{
		_state = state;
	}
};

// *********************************************** ������ ����� ������ ���������

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

// ************************************ ���������� ����������� ������� ��� ������� ������ ���������:

// ���������� ��� ������ NormalState:
void  NormalState::GetNextState(Car &car)
{
	car.SetState(new OutOfFuelState);// �������� � �������� ��������� ��������� ���������
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
	// ������ ����������� ������ �� ��������� � ����� (���������) ���������
	NormalState::GetNextState(car); // �������� ����� ��� �������� � ����� ��������� 
}


// ���������� ��� ������ OutOfFuelState:
void  OutOfFuelState::GetNextState(Car &car)
{
	car.SetState(new RefuelState);
}

void  OutOfFuelState::Report(Car& car)
{
	cout << " Car is stopped at gas station" << " " << typeid(*this).name()<< endl;
	// ��� ������ �������� �� ������� � ��������� "��� ������� - �����"
	OutOfFuelState::GetNextState(car);
}


// ���������� ��� ������ RefuelState:
void  RefuelState::GetNextState(Car& car)
{
	// ����������� � �������� � ���������� (��������� ���������)
	car.SetState(new NormalState);
	car._fuel = 50;
}

void  RefuelState::Report(Car& car)
{
	cout << " Car is refuel at gas station" << " " << typeid(*this).name() << endl;
	RefuelState::GetNextState(car);
}
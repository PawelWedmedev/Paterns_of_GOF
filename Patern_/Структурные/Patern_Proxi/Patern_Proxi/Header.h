#pragma once
#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

class Driver
{
	string _name;
	int _ege;
public:
	int GetAge()
	{
		return _ege;
	}
	Driver(string name = "No", int ege = 0)
	{
		_name = name;
		_ege = ege;
	}

}; 

//класс №0
// Создоем базовый тип, в котором объявляем метод который нам нужно доработать в классе Car
class BaseCar
{
	public:
	virtual void DriveCar() = 0;
};

// класс №1
// класс car имеет метод DriveCar() в котором нам нужно сделать проверку возраста водителя.
// зайти и поменять сам метод в классе мы не можем!!!!
//**************************
// Алгоритм:
//1.Наследуем класс BaseCar.

class Car :public BaseCar   
{
	Driver _dr;
public:
	Car(Driver dr)
	{
		_dr = dr;
	}
	virtual void DriveCar()
	{
		cout << "The car is driwing\n";
	}

};
//класс №2
// отдельный класс где мы будем переопределять метод DriveCar()
class ProxyCar :public BaseCar
{
protected:
	Driver _driver; // поле из класса в котором нужно поменять метод (в нашем случае Car)Dependens injection
	BaseCar* car;	// объект базового типа
public:
	ProxyCar(Driver driver)
	{
		_driver = driver;
		car = new Car(driver); // мы создаем новый объект класса Car 
	}

	virtual void DriveCar()// реализация метода так как нам нужно
	{
		if (_driver.GetAge()<= 20)
			cout << "Driver is not allowed to driwe" << endl;
		else cout << "*******************\n";
	}
};





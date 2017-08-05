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

//����� �0
// ������� ������� ���, � ������� ��������� ����� ������� ��� ����� ���������� � ������ Car
class BaseCar
{
	public:
	virtual void DriveCar() = 0;
};

// ����� �1
// ����� car ����� ����� DriveCar() � ������� ��� ����� ������� �������� �������� ��������.
// ����� � �������� ��� ����� � ������ �� �� �����!!!!
//**************************
// ��������:
//1.��������� ����� BaseCar.

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
//����� �2
// ��������� ����� ��� �� ����� �������������� ����� DriveCar()
class ProxyCar :public BaseCar
{
protected:
	Driver _driver; // ���� �� ������ � ������� ����� �������� ����� (� ����� ������ Car)Dependens injection
	BaseCar* car;	// ������ �������� ����
public:
	ProxyCar(Driver driver)
	{
		_driver = driver;
		car = new Car(driver); // �� ������� ����� ������ ������ Car 
	}

	virtual void DriveCar()// ���������� ������ ��� ��� ��� �����
	{
		if (_driver.GetAge()<= 20)
			cout << "Driver is not allowed to driwe" << endl;
		else cout << "*******************\n";
	}
};





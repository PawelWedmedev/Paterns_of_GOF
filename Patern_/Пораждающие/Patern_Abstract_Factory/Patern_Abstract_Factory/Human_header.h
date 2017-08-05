#pragma once
#include"Header.h"

// прототип виртуальной фабрики 
// реальные классы наследуют абстрактные

class Peasant :public UnitC// крестьянин
{
protected:
	int _health;
public:
	Peasant()
	{
		_health = rand() % 50 + 50;
	}
	void Work()
	{
		cout << typeid(Peasant).name() << " works...\n";
	}
};

class Palladin :public UnitB// рыцарь
{
protected:
	int _health, _attack, _defend;
public:
	Palladin()
	{
		_health = rand() % 80 + 20;
		_attack = rand() % 50 + 50;
		_defend = rand() % 10 + 40;
	}
	void Protect(UnitC* pe)
	{
		cout << typeid(Palladin).name() << " protect..." << typeid(Peasant).name() << " from berserkers \n";
	}
};


class Mage :public UnitA// волшебник
{
protected:
	int _health, _attack, _defend;
public:
	Mage()
	{
		_health = rand() % 80 + 20;
		_attack = rand() % 500 + 600;
		_defend = rand() % 10 + 40;
	}
	void Rule(UnitB* pa)
	{
		cout << typeid(Mage).name() << " rules ower" << typeid(Palladin).name() << " against orc \n";
	}

};

//  Class Product2  (наследник №2 абстрактной фабрики )
//класс через virtual выполняет методы Create абстрактной фабрики(т.е создает людей 3х иерархий)

class HumanFactory : public AbstractFactory // реальная фабрика людей
{
public:
	UnitC* CreateUnitC() // метод create product 3 абстрактной фабрики 
						 // создание крестьянина
	{
		return new Peasant();
	}

	UnitB* CreateUnitB() // метод create product 2 абстрактной фабрики
						 // создание рыцаря
	{
		return new Palladin();
	}

	UnitA* CreateUnitA() // метод create product 1 абстрактной фабрики
						 // создание волшебника
	{
		return new Mage();
	}

};

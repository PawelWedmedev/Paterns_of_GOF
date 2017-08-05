#pragma once
#include"Header.h"

// прототип виртуальной фабрики 
// реальные классы наследуют абстрактные

class Slave :public UnitC// раб 
{
protected:
	int _health;
public:
	Slave()
	{
	_health = rand() % 20 + 50;
	}
	void Work()
	{
		cout << typeid(Slave).name() << " works...\n";
	}
};

class Berserk :public UnitB // воин
{
protected:
	int _health, _attack, _defend;
public:
	Berserk()
	{
		_health = rand() % 100 + 20;
		_attack = rand() % 500 + 50;
		_defend = rand() % 100 + 40;
	}
	void Protect(UnitC* sl)
	{
		cout << typeid(Berserk).name() << " protect..." << typeid(Slave).name() << " from palladin \n";
	}
};

class Shaman :public UnitA  // маг 
{
protected:
	int _health, _attack, _defend;
public:
	Shaman()
	{
		_health = rand() % 30 + 20;
		_attack = rand() % 50 + 600;
		_defend = rand() % 100 + 40;
	}
	void Rule(UnitB* ber)
	{
		cout << typeid(Shaman).name() << " rules ower" << typeid(Berserk).name() << " against  \n";
	}
};

//  Class Product1 (наследник №1 абстрактной фабрики)
//класс через virtual выполняет методы Create абстрактной фабрики (т.е создает орков 3х иерархий)

class OrkFactory : public AbstractFactory // реальная фабрика орков
{
public:
	UnitC* CreateUnitC() // метод create product 3 абстрактной фабрики
						 // создание раба
	{
		return new Slave();
	}
	UnitB* CreateUnitB() // метод create product 2 абстрактной фабрики
						 // создание воина
	{
		return new Berserk();
	}
	UnitA* CreateUnitA() // метод create product 1 абстрактной фабрики
						 // создание колдуна
	{
		return new Shaman();
	}
};
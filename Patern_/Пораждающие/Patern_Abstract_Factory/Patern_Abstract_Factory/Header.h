#pragma once
#include<iostream>
#include<typeinfo>
#include<ctime>
using namespace std;


class UnitC // самый низкий ранг (create product 3)
{// здесь можно описать поля и сделать конструктор который будет через 
	// наследование передаваться всем последующим методам
	// ( здоровье раба и крестьянина), но они будут одинаковы.
public:
	virtual void Work()=0;
};

class UnitB // средний ранг (create product 2)
{
public:
	virtual void Protect(UnitC* c)=0;
};

class UnitA // самый высокий ранг (create product 1)
{
public:
	virtual void Rule(UnitB* b)=0;
};


class AbstractFactory// абстрактная фабрика - предлагает механизм создания, 
	//а каждая конкретная фабрика,которая наследует абстрактную, 
	//решает вопрос создания по своему: (одна делает людей, втоорая орков)	
{
public:
	virtual UnitA* CreateUnitA() = 0;// чисто виртуальные  методы (create product 1)
	virtual UnitB* CreateUnitB() = 0;//...
	virtual UnitC* CreateUnitC() = 0;//...
};

// класс клиент- сложная подсистема (агрегация, композиция)
//в данном случае агрегация

class Client// потребляет все что созданно патерном, задача этого класса получить в свое распоряжение объекты
	// созданные конкретными фабриками (люди и орки)
	// работает с абстрактными классами
{
protected:
	UnitA* oa;// полями класса являються обекты-поля абстрактной фабрики (указатели) 
	UnitB* ob;
	UnitC* oc;
public:
	Client(AbstractFactory* f)// получает объект абстрактной фабрики (указатель).Конструктор клиента.
	{
		oa = f->CreateUnitA();// идем в метод CreateUnitA() человеческой фабрики
							  // далее в класс волшебника(делаем нового волшебника)
		ob = f->CreateUnitB();//... рыцаря
		oc = f->CreateUnitC();//... крестьянина
	}
	void Run()
	{
		oc->Work();  // вызываем виртуальный метод кресьтянина ( или раба в зависимости
		// от того какой создан клиент, человек или орк).
		ob->Protect(oc);
		oa->Rule(ob);
	}

};
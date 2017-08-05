#pragma once
#include"Header.h"

// �������� ����������� ������� 
// �������� ������ ��������� �����������

class Peasant :public UnitC// ����������
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

class Palladin :public UnitB// ������
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


class Mage :public UnitA// ���������
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

//  Class Product2  (��������� �2 ����������� ������� )
//����� ����� virtual ��������� ������ Create ����������� �������(�.� ������� ����� 3� ��������)

class HumanFactory : public AbstractFactory // �������� ������� �����
{
public:
	UnitC* CreateUnitC() // ����� create product 3 ����������� ������� 
						 // �������� �����������
	{
		return new Peasant();
	}

	UnitB* CreateUnitB() // ����� create product 2 ����������� �������
						 // �������� ������
	{
		return new Palladin();
	}

	UnitA* CreateUnitA() // ����� create product 1 ����������� �������
						 // �������� ����������
	{
		return new Mage();
	}

};

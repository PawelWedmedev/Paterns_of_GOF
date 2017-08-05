#pragma once
#include"Header.h"

// �������� ����������� ������� 
// �������� ������ ��������� �����������

class Slave :public UnitC// ��� 
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

class Berserk :public UnitB // ����
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

class Shaman :public UnitA  // ��� 
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

//  Class Product1 (��������� �1 ����������� �������)
//����� ����� virtual ��������� ������ Create ����������� ������� (�.� ������� ����� 3� ��������)

class OrkFactory : public AbstractFactory // �������� ������� �����
{
public:
	UnitC* CreateUnitC() // ����� create product 3 ����������� �������
						 // �������� ����
	{
		return new Slave();
	}
	UnitB* CreateUnitB() // ����� create product 2 ����������� �������
						 // �������� �����
	{
		return new Berserk();
	}
	UnitA* CreateUnitA() // ����� create product 1 ����������� �������
						 // �������� �������
	{
		return new Shaman();
	}
};
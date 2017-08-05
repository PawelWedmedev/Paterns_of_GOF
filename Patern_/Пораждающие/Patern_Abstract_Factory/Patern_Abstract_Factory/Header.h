#pragma once
#include<iostream>
#include<typeinfo>
#include<ctime>
using namespace std;


class UnitC // ����� ������ ���� (create product 3)
{// ����� ����� ������� ���� � ������� ����������� ������� ����� ����� 
	// ������������ ������������ ���� ����������� �������
	// ( �������� ���� � �����������), �� ��� ����� ���������.
public:
	virtual void Work()=0;
};

class UnitB // ������� ���� (create product 2)
{
public:
	virtual void Protect(UnitC* c)=0;
};

class UnitA // ����� ������� ���� (create product 1)
{
public:
	virtual void Rule(UnitB* b)=0;
};


class AbstractFactory// ����������� ������� - ���������� �������� ��������, 
	//� ������ ���������� �������,������� ��������� �����������, 
	//������ ������ �������� �� ������: (���� ������ �����, ������� �����)	
{
public:
	virtual UnitA* CreateUnitA() = 0;// ����� �����������  ������ (create product 1)
	virtual UnitB* CreateUnitB() = 0;//...
	virtual UnitC* CreateUnitC() = 0;//...
};

// ����� ������- ������� ���������� (���������, ����������)
//� ������ ������ ���������

class Client// ���������� ��� ��� �������� ��������, ������ ����� ������ �������� � ���� ������������ �������
	// ��������� ����������� ��������� (���� � ����)
	// �������� � ������������ ��������
{
protected:
	UnitA* oa;// ������ ������ ��������� ������-���� ����������� ������� (���������) 
	UnitB* ob;
	UnitC* oc;
public:
	Client(AbstractFactory* f)// �������� ������ ����������� ������� (���������).����������� �������.
	{
		oa = f->CreateUnitA();// ���� � ����� CreateUnitA() ������������ �������
							  // ����� � ����� ����������(������ ������ ����������)
		ob = f->CreateUnitB();//... ������
		oc = f->CreateUnitC();//... �����������
	}
	void Run()
	{
		oc->Work();  // �������� ����������� ����� ����������� ( ��� ���� � �����������
		// �� ���� ����� ������ ������, ������� ��� ���).
		ob->Protect(oc);
		oa->Rule(ob);
	}

};
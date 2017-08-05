#pragma once
# include<iostream>
# include<string>
# include<vector>
using namespace std;

class PC
{
	vector <string> parts;
public:
	void AddPart(string part)
	{
		parts.push_back(part);
	}
	void Show()
	{
		cout << "System block: " << endl;
		for (int i(0);i < parts.size();i++)
		{
			cout << parts[i] << endl;
		}
	}
};

class ABuilder
{
public:
	virtual void BuildCPU() = 0;
	virtual void BuildMB() = 0;
	virtual void BuildRAM() = 0;
	virtual void BuildHDD() = 0;
	virtual PC GetPC() = 0;
};

class Builder1 : public ABuilder
{
	PC pc1;
public:
	void BuildCPU()
	{
		pc1.AddPart("Intel");// �������� ����� ADD ������ �� ������� ��������� ������ � ����������
		// ��� ������ � ������
	}
	void BuildMB()
	{
		pc1.AddPart("MB-Asus");
	}
	void BuildRAM()
	{
		pc1.AddPart("DDR3200");
		pc1.AddPart("DDR3200"); 
	}
	void BuildHDD()
	{
		pc1.AddPart("Samsung 1000");
	}
	
	PC GetPC()
	{
		return pc1;
	}
};


class Builder2 : public ABuilder
{
	PC pc1;
public:
	void BuildCPU()
	{
		pc1.AddPart("Intel Core i7");
	}
	void BuildMB()
	{
		pc1.AddPart("MB-Asus");
	}
	void BuildRAM()
	{
		pc1.AddPart("DDR4200");
	}
	void BuildHDD()
	{
		pc1.AddPart("Samsung evo 998");
	}

	PC GetPC()
	{
		return pc1;
	}
};

class Builder3 : public ABuilder
{
	PC pc1;
public:
	void BuildCPU()
	{
		pc1.AddPart("AMD");// �������� ����� ADD ������ �� ������� ��������� ������ � ����������
		// ��� ������ � ������
	}
	void BuildMB()
	{
		pc1.AddPart("MB-Asus");
	}
	void BuildRAM()
	{
		pc1.AddPart("DDR4200");
		pc1.AddPart("DDR4200");
	}
	void BuildHDD()
	{
		pc1.AddPart("Samsung ssd evo-500");
	}

	PC GetPC()
	{
		return pc1;
	}
};


// ����� ����� �� ������� ��������� ������������ ������� ������� ��� ������ �������� � CreatePC � ���� �� ���
class Director
{
	// � ���� ������ � ������ PC CreatePC() �� ����� �������� ������ ������ Builder(1,2,..)����� ��������->
	// �� ������� ������� ���� builder��, ��� �� � ����������� �� ����� ���� ����������,
	//��� ����� ������ ��������� ����� if( ������ ���� � ���� ����� �� ������� 2� ��� 3 � 4...)
public:
	PC CreatePC(ABuilder* builder) // ����� ��������� ��������� ������������ ������ (builder=b1)
	{
		builder->BuildCPU();// �� ����� ��������� ������������ ������ �������� ������...
		builder->BuildMB();
		builder->BuildRAM();
		builder->BuildHDD();
		return builder->GetPC();
	}
};

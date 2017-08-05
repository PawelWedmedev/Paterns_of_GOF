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
		pc1.AddPart("Intel");// вызываем метод ADD класса РС который принимает строку и записываем
		// эту строку в вектор
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
		pc1.AddPart("AMD");// вызываем метод ADD класса РС который принимает строку и записываем
		// эту строку в вектор
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


// класс каким то образом управляет очередностью вызовов методов или когото вызывает в CreatePC а кого то нет
class Director
{
	// в этом классе в методе PC CreatePC() мы можем вызывать методы класса Builder(1,2,..)через оператор->
	// по порядку вызывая всех builderов, или же в зависимости от каких либо параметров,
	//или полей класса директора через if( вызвал один и если чтото то вызываю 2й или 3 и 4...)
public:
	PC CreatePC(ABuilder* builder) // метод принимает указатель абстрактного класса (builder=b1)
	{
		builder->BuildCPU();// от имени указателя абстрактного класса вызываем методы...
		builder->BuildMB();
		builder->BuildRAM();
		builder->BuildHDD();
		return builder->GetPC();
	}
};

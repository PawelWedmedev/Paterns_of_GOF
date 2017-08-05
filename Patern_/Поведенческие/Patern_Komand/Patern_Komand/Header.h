#pragma once
#include<iostream>
# include<vector>
using namespace std;

// ����� ������� ����������� -  ���� ����������� �������� ����������� �������!!!

class Calculator// ����� ������� - ���������� � ����������� ������
{
	double _result;
public:
	Calculator()
	{
		_result = 0;
	}
	void Action(char operators, double operand) // ����� ������� ��������� � �������� ��� �������� 
	{
		switch (operators)
		{
		case '+': _result += operand; 
			break;
		case '-': _result -= operand;
			break;
		case '*': _result *= operand;
			break;
		case '/': _result /= operand;
			break;
		}
		cout << "Result = " << _result<<endl;
	}
};

// ����������� ���� - �������
class Comand//  ����������� ����� � ������� ����������� ��������� ������ ������� ���������� ����� �����������
{
public:
	virtual void Execute() = 0;		// ��������� �������
	virtual void UnExecute() = 0;	// �������� ���������� �������
};

// �������� ����� - �������
class CalcComand : public Comand // � ���� ������ ����� ��������� ������������� ��������
{
	char _operators;	// ����� �������� �������(+,-,*,/)
	double _operand;	
	Calculator* _calculator; // ������ ������ (��������) ���������� �������
public:
	CalcComand(Calculator *calculator, char operators, double operand)
	{
		_operators = operators;
		_calculator = calculator;
		_operand = operand;
	}

	void SetOperanD(double operand)
	{
		_operand = operand;
	}

	void SetOperaTors(char operators)
	{
		_operators = operators;
	}

	virtual void  Execute() // ���������� ������ Execute() ����� ������ ���������������� ������ ������� ������ ���������
	{
		_calculator->Action(_operators, _operand);// ���������� � ������������ � ����������� � �������� Action()
	}

	virtual void  UnExecute()	// �������� ���������� �������(�� ������ ��������� �������� ��������  Execute() )
	{
		char undo;
		switch (_operators)
		{
		case'+':undo = '-'; break;
		case'-':undo = '+'; break;
		case'*':undo = '/'; break;
		case'/':undo = '*'; break;
		}
		_calculator->Action(undo, _operand);	// �������� ��������(char undo) �������� ( ������� �� _operators � undo ����������� ��������������� ������)
	}
};

// ����� ������ (���������� �����)
// ����� ������� ������ ������ ���������� ������� � ������ Compute() � ������������� ����������
class User
{
	int _ops;	// c������ ������
	Calculator _calculator;
	vector<Comand*> commands;
public:
	User()
	{
		_ops = 0;
	}
	void Compute(char _operators, double operand) // ����� ����������
	{
		Comand* command = new CalcComand(&_calculator,_operators, operand);
		command->Execute();
		_ops++;// ����������� ��������� ������ ������� ���������
		commands.push_back(command);// � ������� ���������� ������� � ������ 
	}

	void Undo(int count)// ������ ������� (�������� - ���������� ������)
	{
		cout << "Undo " << count << " command(s) " << endl;
		for (int i(0);i < count;i++)
		{
			if (_ops > 0)// ���� ���������� ���������� ������ ����� 0 ��...
			{
				commands[--_ops]->UnExecute();	// ...�������� � ������� �� ������� ���������� ������� ����� UnExecute()
				cout << "Undo "<<i+1<<" comand\n";
			}
		}
	}

	void Redo(int count)// �������� ��������� �������
	{
		cout << "Redo " << count << " command(s) " << endl;
		for (int i(0);i < count;i++)
		{
			if (_ops <= commands.size())// ���� ���� ����������� �������
			{
				commands[_ops++]->Execute();
				cout << "Redo " << i + 1 << " comand\n";
			}
		}
	}
};
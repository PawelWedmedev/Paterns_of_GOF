#pragma once
#include<iostream>
# include<vector>
using namespace std;

// Самое главное достоинство -  есть возможность отменить выполненную команду!!!

class Calculator// класс ресивер - получатель и выполнятель команд
{
	double _result;
public:
	Calculator()
	{
		_result = 0;
	}
	void Action(char operators, double operand) // метод который выполняет и получает все действия 
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

// абстрактный клас - команда
class Comand//  абстрактный класс в котором представлен интерфейс команд которые необходимо будет реализовать
{
public:
	virtual void Execute() = 0;		// выполнить команду
	virtual void UnExecute() = 0;	// отменить предыдущую команду
};

// реальный класс - команда
class CalcComand : public Comand // в этом классе будем выполнять арфметические операции
{
	char _operators;	// будем заносить команду(+,-,*,/)
	double _operand;	
	Calculator* _calculator; // объект класса (ресивера) получателя запроса
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

	virtual void  Execute() // реализация метода Execute() путем вызова соответствующего метода объекта класса рессивера
	{
		_calculator->Action(_operators, _operand);// обращаемся к калькулятору с параметрами и вызываем Action()
	}

	virtual void  UnExecute()	// отменить предыдущую команду(он должен выполнить действие обратное  Execute() )
	{
		char undo;
		switch (_operators)
		{
		case'+':undo = '-'; break;
		case'-':undo = '+'; break;
		case'*':undo = '/'; break;
		case'/':undo = '*'; break;
		}
		_calculator->Action(undo, _operand);	// передаем параметр(char undo) обратный ( смотрим на _operators и undo присваиваем противоположный символ)
	}
};

// класс клиент (вызывающий класс)
// здесь создаем объект класса конкретной команды в методе Compute() и устанавливаем получателя
class User
{
	int _ops;	// cчетчик команд
	Calculator _calculator;
	vector<Comand*> commands;
public:
	User()
	{
		_ops = 0;
	}
	void Compute(char _operators, double operand) // метод вычисления
	{
		Comand* command = new CalcComand(&_calculator,_operators, operand);
		command->Execute();
		_ops++;// увеличиваем колчество команд которое выполнили
		commands.push_back(command);// и заносим выполненые команды в вектор 
	}

	void Undo(int count)// отмена команды (параметр - количество команд)
	{
		cout << "Undo " << count << " command(s) " << endl;
		for (int i(0);i < count;i++)
		{
			if (_ops > 0)// если количество выполненых команд болше 0 то...
			{
				commands[--_ops]->UnExecute();	// ...вызываем в векторе по индексу предыдущей команды метод UnExecute()
				cout << "Undo "<<i+1<<" comand\n";
			}
		}
	}

	void Redo(int count)// повторно выполнить команду
	{
		cout << "Redo " << count << " command(s) " << endl;
		for (int i(0);i < count;i++)
		{
			if (_ops <= commands.size())// если есть проделанные команды
			{
				commands[_ops++]->Execute();
				cout << "Redo " << i + 1 << " comand\n";
			}
		}
	}
};
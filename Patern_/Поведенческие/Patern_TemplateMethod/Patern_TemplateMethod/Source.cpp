#include"Header.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	// создаем объекты 
	Base *base1 = new One;
	Base *base2 = new Two;
	// вызываем метод от имени объекта первого класса со стандарными методами и с переопределенными
	base1->Execute();
	cout << endl;
	cout << "************************\n";
	// вызываем метод от имени объекта второго класса со стандарными методами и с переопределенными
	base2->Execute();
	cout << endl;
}
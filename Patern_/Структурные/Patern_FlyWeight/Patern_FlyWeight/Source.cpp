#include"Header.h"



void main()
{
	/*srand(time(NULL));
	Symbol s('r');
	s.Display(20, "blue");*/

	string text = "lazy dog is sleeping on the wet straw ";// в предложении 27 букв, записыватс€ будут только в
	//единичном экземпл€ре

	CharFactory factory;
	BaseSymbol* c;

	ofstream out("text.html");

	for (string::iterator it =text.begin();it != text.end();it++)
	{
		c = factory.GetSymbol(*it); //присваиваем указателю с класса BaseSymbol разименованный итератор который 
									//возврашает символ строки
		cout << (c->GetChar()); // выводим символ на экран
		
		out << c->Display(20,"red"); // зыписываем в файл
	}
	cout <<endl<< factory.GetPoolSize() << endl;// провер€ем количество единичных символов в pool
	out.close();

}
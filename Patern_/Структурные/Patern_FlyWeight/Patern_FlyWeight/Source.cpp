#include"Header.h"



void main()
{
	/*srand(time(NULL));
	Symbol s('r');
	s.Display(20, "blue");*/

	string text = "lazy dog is sleeping on the wet straw ";// � ����������� 27 ����, ����������� ����� ������ �
	//��������� ����������

	CharFactory factory;
	BaseSymbol* c;

	ofstream out("text.html");

	for (string::iterator it =text.begin();it != text.end();it++)
	{
		c = factory.GetSymbol(*it); //����������� ��������� � ������ BaseSymbol �������������� �������� ������� 
									//���������� ������ ������
		cout << (c->GetChar()); // ������� ������ �� �����
		
		out << c->Display(20,"red"); // ���������� � ����
	}
	cout <<endl<< factory.GetPoolSize() << endl;// ��������� ���������� ��������� �������� � pool
	out.close();

}
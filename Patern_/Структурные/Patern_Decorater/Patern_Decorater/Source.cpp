#include"Header.h"



void main()
{
	setlocale(LC_ALL, "Rus");
	

	Text *t = new Text;// ������� ������ ������ 
	t->SetText(" Hello world!!!!! ");// ������������� ����� Seter ��� �����
	t->Display();
	cout << endl;
	cout << "******** �� �������� ******************\n";

	Text* tbold = new BoldDecorator(t);// �������� � �������� ��������� ������������ ��� ������ t( �.� ����� Hello world!!!!!)
	tbold->Display();// ������� ������ tbold - ������ �����
	cout << endl;

	Text* titalic = new ItalicDecorator(tbold);// ����� ��������� � ��� b �����(tbold) �� �������� � ����������� ����� ���������� ������
	titalic->Display();// ������� ������ ����� ��� � ���������
	cout << endl;

	Text* tbig = new BigDecorator(titalic);// ������ ������ ������ � ��������� ����� ��� � �������
	tbig->Display();
	cout << endl;

	cout << "********* ����� ����� ������� *****************\n";
	Text *t1 = new Text;
	t1->SetText("Big litl sity");
	t1->Display();
	cout << endl;
	Text* t1big = new BigDecorator(t1);
	t1big->Display();


	tbig->CreateFileW(tbig->GetText());// ���������� ����� ��� ��������
}
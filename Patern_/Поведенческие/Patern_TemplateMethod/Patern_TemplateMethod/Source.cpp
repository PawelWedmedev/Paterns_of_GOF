#include"Header.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	// ������� ������� 
	Base *base1 = new One;
	Base *base2 = new Two;
	// �������� ����� �� ����� ������� ������� ������ �� ����������� �������� � � �����������������
	base1->Execute();
	cout << endl;
	cout << "************************\n";
	// �������� ����� �� ����� ������� ������� ������ �� ����������� �������� � � �����������������
	base2->Execute();
	cout << endl;
}
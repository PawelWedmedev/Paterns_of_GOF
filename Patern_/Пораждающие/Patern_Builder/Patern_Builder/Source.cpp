#include "Header.h"



void main()
{
	Director* dir = new Director();// ������� ������ ���������
	ABuilder* b1 = new Builder1();// ... � ����� ����������(���� ���������)
	ABuilder* b2 = new Builder2();
	ABuilder* b3 = new Builder3();


	// pc1 = �������� ����� ������ ��������...( � �������� ��������� �������� ��������� b3)
	PC pc1 = dir->CreatePC(b3); // ...���� � ����� �������� (builder->BuildCPU()), 
	//����� � ����� Builder1 (BuildCPU())- � ��� ������ ���������(��� ��� "������",
	//����� � ����� PC (pc1.AddPart("Intel")), � ���������� � ������.
	pc1.Show();

}
#include"Header.h"



void main()
{
	

	Chater* ch1 = new Chater("Vasya"); // ������ ���������� ���� 
	Chater* ch2 = new Chater("Vitya");
	Chater* ch3 = new Chater("Vofchik");
	Chater* ch4 = new Chater("Valerik");

	ABmediator* m1 = new Mediater();// ������� ��������(������������ ���������)

	m1->AddChater(ch1);// ��������� ������� � �������� ( ������� � ������ )(����� ���� �� � ����� ����)
	m1->AddChater(ch2);
	m1->AddChater(ch3); 
	m1->AddChater(ch4);

	ch1->Send_Message(m1,"Hello!");
	//1. ����� ��������� �� ������ Vasya � ���� � ����� Send_Message() ������ Chater
	//2. ����� ��������� � ����������  ������������ ������ TransferMessage() � ������ Mediator
	//3. ����� ������������ � ����� �� ��������� ������� (����� �������� �� �������� ��������� ������ ����) 
	//	 �������� �����  Receive_Message() ������ Chater � ������� cout.
	cout << "**************************************\n";
	ch3->Send_Message(m1, "<World>");

}
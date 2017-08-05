#include"Header.h"

void main()
{
	
	Card card1 (111, 10000);	// ������ ����� (�������� ������ � �����)
	Card card2 (222, 1000);
	Card card3 (333, 15000);
	Card card4 (444, 155500);
	Card card5 (555, 10);

	Bank bank1;					// ������ ����� 
	Bank bank2;

	bank1.AddCard(&card1);		// ��������� � ������ ���� ��������
	bank1.AddCard(&card2);
	bank1.AddCard(&card3);
	bank1.AddCard(&card4);
	bank1.AddCard(&card5);

	ATM atm(&bank1);			// ������ ��������(� ����� ������ �������� ����� �1)
	
	bank1.Show();				// ������� �� ����� ��� �������� ����� �1

	cout << "********** No facade *********\n";

	int res =atm.InsertCard(&card2);	// ��������� ���� �������� � ��������� �� ��� � �� �������������� ����� (���� ��� �� �� ����� ���������� 0)
	if (res == 0)
	{
		res = atm.RequestBallans(&card2); // ��������� ������� ������� �� ����� (��� ������� ������� ����� ���������� 0)
		if (res == 0) // ���� ��� �� � �������� ����...
			atm.GetMoney(&card2); // ...������ ������
	}
	card2.Show();
	cout << endl;

	cout << "********** Facade *********\n";
	
	ATMFacade fasade(&bank1);
	fasade.ClientAction(&card5);// ��� ������ �� ����������� ������� �� �������� � ���� � �������� ����������
	
}
#include"Header.h"



void main()
{
	setlocale(LC_ALL, "Rus");
	RealShop s1("Shop1");			// ��������
	RealShop s2("Shop2");
	RealShop s3("Shop3");
	RealShop s4("Shop4");
	
	Product product1("BMW", 50000); // ������� ������� ������� 4 ��������

	product1.Subscriber(&s1);		// ���������� �� ��� ��������(������� � ������ ����������� )
	product1.Subscriber(&s2);
	product1.Subscriber(&s3);

	//***************************   // ������ �������� �����!!!
	product1.ChengePrise(49999);	// ���������� ���� ������ ( ������ ���� � ������ ���) 
	product1.NotifyAll();			// ��������� ��� ��������� ����
	//***************************
	cout << endl;
	cout << "****** ��������� ������� � 2 ***************\n";
	product1.Unsubscriber(&s2);		// ���������� �� ��������� ���� ��� �2
	product1.ChengePrise(499);      // ������ ���� 
	product1.NotifyAll();			// ��������� ��� ��������� ����
	cout << endl;
	cout << "****** ��������� ���� ��� ������� � 2 ***************\n";
	s2.Notify(56000);				// ������ ��� ��� �2 ������������ ����(�� ������ �� ���������)
	cout << endl;
	cout << "****** ���� ��������� ����� ������ ���� ***************\n";
	product1.ChengePrise(65000);
	product1.NotifyAll();
	cout << endl;
	cout << "****** ��������� ������� �2 ����� � ���������� ***************\n";
	product1.Subscriber(&s2);
	product1.NotifyAll();
	cout << endl;
}

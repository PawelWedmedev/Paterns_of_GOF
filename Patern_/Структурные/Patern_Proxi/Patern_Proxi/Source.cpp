#include"Header.h"



void main()
{
	srand(time(NULL));
	 
	// � ��� ���� �������� �������� �� ����� ������ ��� � ����� Car �������� ��� ��������
	// ��� � ����� ����� ProxyCar � ���� �� ����� �� ��� ��� ��� �����

	Driver d1("Vasya", 30);
	//Car car(d1);
	//car.DriveCar(); // ����������� ����� ������ Car 
	ProxyCar pc(d1); 
	pc.DriveCar();  // �������� ��� ����� (������������)

}
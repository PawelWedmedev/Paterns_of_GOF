#include"Header.h"


void main()
{
	BaseState *state = new NormalState; // ������� ������� ��������� ( ���������� ���������)
	Car car(state);// �������� ��� ��������� � �������� ��������������� � �����������
	car.UseCar();
}


#include"Header.h"


void main()
{
	Singleton * s1 = Singleton::GetInstans();	// �������� static ����� �� ����� ������ (Singleton::GetInstans()) 
												//(:: ������ ��� ����� static )
	Singleton * s2 = Singleton::GetInstans();   // ��� ��������� ������� ������� ����� ��� �� ���������� 

}
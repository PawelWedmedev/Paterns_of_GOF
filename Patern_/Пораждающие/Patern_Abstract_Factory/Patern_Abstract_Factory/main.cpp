#include"Header.h"
#include"Human_header.h"
#include"Orcs_header.h"


void main()
{
	srand(time(NULL));


	HumanFactory* hf = new HumanFactory();// ������� ������� �����
	Client* ch = new Client(hf);// �������� �� � ����������� ������� � �������
								// ������� � ����������� ������������ �������
	ch->Run();// �������� � ������� ����� 
	


}
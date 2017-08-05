#include"Header.h"



void main()
{
	srand(time(NULL));

	Handler_500* h500 = new Handler_500(10);
	Handler_100* h100 = new Handler_100(50);
	Handler_50*  h50  = new Handler_50(100);

	//������������� ���������� ����������� ����� 500(100) ������ - (h100) ��� (h50)
	h500->SetHandler(h100); //������� ������ h500 ����� SetHandler() ������ � ����� ����� ������������,
							//������ � ����� _next 
 	h100->SetHandler(h50);

	Request rq(600); // ������� ������ ������� � ������
	h500->HandlerRequest(&rq); // �������� ��������� �� ������� (h500) �����������
	rq.Show();

}
#include"Header.h"



void main()
{
	

	EmailSender *es = new EmailSender();// ������� e-mail sender
	Messege *msg = new Messege(es, "To Mr.midved", "Come in");// ������� ��� � ���������, ��������� ,���������
	msg->Send();// � ������ msg ��������� EmailSender es , ������� ��������� ����� Send() �� ������ EmailSender
	cout << "*************************\n";
	MsmqSender *gs = new MsmqSender();// ���� � ���� ��������� ��������� ����� ������ Msmq
	msg->SetSender(gs);// ����� ����� ������ � msg(�������) ������ �������� �� gs, ��� ���� ��������� �� ����������
	msg->Send();
	cout << "*************************\n";
	WebServiceSender *ws = new WebServiceSender();
	msg->SetSender(ws);
	msg->Send();
	cout << "*************************\n";
	// ����� ������ Send() �� ���������, ������� ��� ����� ��������� � ����� � ������ ������ ������ �������� ����� Seter!!!

	cout << "**********SUPER email messege!!!!***************\n";
	SuperMessage *sm = new SuperMessage(es,"To Mr.midved","Come in",1);// ���� ����� ������ �� �������� 1
	sm->Send();

	cout << "**********SUPER WEBservice messege!!!!***************\n";
	WebServiceSender* wsSuper = new WebServiceSender();
	sm->SetSender(wsSuper);
	sm->Send();
	
}
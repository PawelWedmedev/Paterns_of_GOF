#include"Header.h"



void main()
{
	

	EmailSender *es = new EmailSender();// создаем e-mail sender
	Messege *msg = new Messege(es, "To Mr.midved", "Come in");// пеедаем его в сообщение, заголовок ,сообщение
	msg->Send();// в объект msg подсунули EmailSender es , поэтому вызываеем метод Send() из класса EmailSender
	cout << "*************************\n";
	MsmqSender *gs = new MsmqSender();// если я хочу отправить сообщение через службу Msmq
	msg->SetSender(gs);// через сетер меняем в msg(меседже) службу отправки на gs, при этом сообщение не изминилось
	msg->Send();
	cout << "*************************\n";
	WebServiceSender *ws = new WebServiceSender();
	msg->SetSender(ws);
	msg->Send();
	cout << "*************************\n";
	// вызов метода Send() не меняеться, поэтому его можно запустить в цикле и менять только службы отправки через Seter!!!

	cout << "**********SUPER email messege!!!!***************\n";
	SuperMessage *sm = new SuperMessage(es,"To Mr.midved","Come in",1);// тоже самое только со статусом 1
	sm->Send();

	cout << "**********SUPER WEBservice messege!!!!***************\n";
	WebServiceSender* wsSuper = new WebServiceSender();
	sm->SetSender(wsSuper);
	sm->Send();
	
}
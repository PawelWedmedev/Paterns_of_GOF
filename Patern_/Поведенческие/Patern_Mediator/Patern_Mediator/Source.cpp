#include"Header.h"



void main()
{
	

	Chater* ch1 = new Chater("Vasya"); // делаем участников чата 
	Chater* ch2 = new Chater("Vitya");
	Chater* ch3 = new Chater("Vofchik");
	Chater* ch4 = new Chater("Valerik");

	ABmediator* m1 = new Mediater();// создаем медиатор(пересылатель сообщений)

	m1->AddChater(ch1);// добавляем чатеров в медиатор ( заносим в вектор )(можно было бы и через цикл)
	m1->AddChater(ch2);
	m1->AddChater(ch3); 
	m1->AddChater(ch4);

	ch1->Send_Message(m1,"Hello!");
	//1. берем сообщение от чатера Vasya и идем в метод Send_Message() класса Chater
	//2. затем переходим в реализацию  виртуального метода TransferMessage() в классе Mediator
	//3. затем передвигаясь в цикле по коллекции чатеров (после проверки на отправку сообщения самому себе) 
	//	 вызываем метод  Receive_Message() класса Chater и выводим cout.
	cout << "**************************************\n";
	ch3->Send_Message(m1, "<World>");

}
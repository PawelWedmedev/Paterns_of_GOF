#include"Header.h"



void main()
{
	setlocale(LC_ALL, "Rus");
	

	Text *t = new Text;// создаем объект строки 
	t->SetText(" Hello world!!!!! ");// устанавливаем через Seter сам текст
	t->Display();
	cout << endl;
	cout << "******** по очередно ******************\n";

	Text* tbold = new BoldDecorator(t);// передаем в качестве параметра конструктора наш объект t( т.е текст Hello world!!!!!)
	tbold->Display();// сделали объект tbold - жирный текст
	cout << endl;

	Text* titalic = new ItalicDecorator(tbold);// потом обернутый в тег b текст(tbold) мы передаем в конструктор класа наклонного текста
	titalic->Display();// сделали жирный текст еще и наклонным
	cout << endl;

	Text* tbig = new BigDecorator(titalic);// теперь делаем жирный и наклонный текст еше и большим
	tbig->Display();
	cout << endl;

	cout << "********* новый текст большой *****************\n";
	Text *t1 = new Text;
	t1->SetText("Big litl sity");
	t1->Display();
	cout << endl;
	Text* t1big = new BigDecorator(t1);
	t1big->Display();


	tbig->CreateFileW(tbig->GetText());// записываем текст для браузера
}
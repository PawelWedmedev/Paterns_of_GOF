#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<windows.h>
using namespace std;

// реализация патерна каждый раЗ разная
// 1. Позволяет создать простой интерфейс для сложной системы
// 2. Полезен тогда когда между подсистемами из которых состоит сложная система существует много связей
// 3. Вместо одной сложной системы мы делаем несколько простых систем
// Самая простая методолоия реализации патерна - это  обвертка:
// мы создаем путем наследования от сложного класса свой производный класс, 
// в этом классе создаем метод в которром вызываем все методы базового класса в той очереди как нужно(обеспечивая непрерывное взаимодействие)
// и уже вызываем только один метод(как в AF- Client)

class Card
{
	int _pin;
	int _ballans;
public:
	Card(int pin, int ballans)
	{
		SetPin(pin);
		SetBallans(ballans);
	}

	void SetBallans(int ballans)
	{
		_ballans = ballans;
	}
	void SetPin(int pin)
	{
		_pin = pin;
	}
	int GetBallans()
	{
		return _ballans;
	}

	int GetPin()
	{
		return _pin;
	}

	void Show()
	{
		cout << "Card:" << _pin << " curent balanse:" << _ballans << endl;
	}
};

class Bank
{
	vector<Card*> cards;// храним карточки
public:
	void AddCard(Card *c)// добавляем карточку в банк
	{
		if (c->GetBallans() > 0)
			cards.push_back(c);
	}

	void Show()// вывод на экран всех карточек банка
	{
		for_each(cards.begin(), cards.end(), [](Card* c) {c->Show();});
	}

	Card* CheckCard(Card* c)// метод проверки принадлежности карточки к банкомату
	{
		vector<Card*>::iterator it =find(cards.begin(), cards.end(), c);
		if (it != cards.end())// если итератор не равен cards.end то он указывает на найденную карточку
			return (*it);// возвращаем саму карточку
		else return NULL;
	}
};

class ATM// класс банкомат (сложная система которую будем оборачивать(Wraper) и заменять 3 метода которые в ней прописаны)
{
	Bank* _bank;
	int _money;
public:
	ATM (){}
	ATM(Bank* bank)
	{
		_bank = bank;
	}
	int InsertCard (Card* card)  // запрос ввода пинкода
	{
		Card *c=_bank->CheckCard(card); // проверяем карточку( и возврвщаем карточку Card *c= )
		if (c == NULL) // если карточка не найдена (не пренадлежит этому банку)
		{
			cout << "The card doesnt not belong to the bank" << endl;
			return -2;
		}
		// после проверки карточки вводим пинкод
		int pin;
		cout << "Enter pin code: ";
		cin >> pin;
		if (card->GetPin() != pin)
		{
			cout << "Wrong pin code!" << endl;
			return (-1);
		}
		return 0;
	}

	int RequestBallans(Card* c)// метод проверки балланса
	{
		int money;
		cout << "Enter money: ";
		cin >> money;
		if (c->GetBallans()< money)
		{
			cout << "Not manney" << endl;
			return (-1);
		}
		_money = money;
		return 0;
	}

	void GetMoney(Card* c)// метод выдать деньги
	{
		c->SetBallans(c->GetBallans() - _money);
		cout <<"Get money and card\n";
	}

};
// собственно сам класс обвертка
class ATMFacade :public ATM
{
public:
	ATMFacade(Bank* bank): ATM(bank)// наследуем конструктор производного класса
	{}
	void ClientAction(Card* card)
	{
		
		int res = InsertCard(card);	// проверяем нашу карточку в банкомате на пин и на принадлежность банку (если все ок то метод возвращает 0)
		if (res == 0)
		{
			res = RequestBallans(card); // проверяем наличие средств на карте (при наличии средств метод возвращает 0)
			if (res == 0) // если все ок и средства есть...
				GetMoney(card); // ...выдаем деньги
		}
		card->Show();
	}
};
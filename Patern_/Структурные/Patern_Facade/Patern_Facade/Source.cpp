#include"Header.h"

void main()
{
	
	Card card1 (111, 10000);	// делаем карту (передаем пинкод и сумму)
	Card card2 (222, 1000);
	Card card3 (333, 15000);
	Card card4 (444, 155500);
	Card card5 (555, 10);

	Bank bank1;					// делаем банки 
	Bank bank2;

	bank1.AddCard(&card1);		// добавляем в первый банк карточки
	bank1.AddCard(&card2);
	bank1.AddCard(&card3);
	bank1.AddCard(&card4);
	bank1.AddCard(&card5);

	ATM atm(&bank1);			// делаем банкомат(в нашем случае банкомат банка №1)
	
	bank1.Show();				// выводим на экран все карточки банка №1

	cout << "********** No facade *********\n";

	int res =atm.InsertCard(&card2);	// проверяем нашу карточку в банкомате на пин и на принадлежность банку (если все ок то метод возвращает 0)
	if (res == 0)
	{
		res = atm.RequestBallans(&card2); // проверяем наличие средств на карте (при наличии средств метод возвращает 0)
		if (res == 0) // если все ок и средства есть...
			atm.GetMoney(&card2); // ...выдаем деньги
	}
	card2.Show();
	cout << endl;

	cout << "********** Facade *********\n";
	
	ATMFacade fasade(&bank1);
	fasade.ClientAction(&card5);// все методы из предыдущего примера мы вставили в один и вызываем поочередно
	
}
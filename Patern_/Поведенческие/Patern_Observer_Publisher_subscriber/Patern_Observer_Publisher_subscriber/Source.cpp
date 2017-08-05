#include"Header.h"



void main()
{
	setlocale(LC_ALL, "Rus");
	RealShop s1("Shop1");			// магазины
	RealShop s2("Shop2");
	RealShop s3("Shop3");
	RealShop s4("Shop4");
	
	Product product1("BMW", 50000); // продукт который продают 4 магазина

	product1.Subscriber(&s1);		// ооформляем на них подписку(заносим в вектор подписчиков )
	product1.Subscriber(&s2);
	product1.Subscriber(&s3);

	//***************************   // методы вазываем парой!!!
	product1.ChengePrise(49999);	// изначально даем скидку ( меняем цену в первый раз) 
	product1.NotifyAll();			// оповещаем про изминение цены
	//***************************
	cout << endl;
	cout << "****** отписывае магазин № 2 ***************\n";
	product1.Unsubscriber(&s2);		// отписываем от изминений цены маг №2
	product1.ChengePrise(499);      // меняем цену 
	product1.NotifyAll();			// оповещаем про изминение цены
	cout << endl;
	cout << "****** фиксируем цену для магазин № 2 ***************\n";
	s2.Notify(56000);				// ставим для маг №2 фиксированую цену(он больше не подписчик)
	cout << endl;
	cout << "****** всем остальным снова меняем цену ***************\n";
	product1.ChengePrise(65000);
	product1.NotifyAll();
	cout << endl;
	cout << "****** добавляем магазин №2 снова в подписчики ***************\n";
	product1.Subscriber(&s2);
	product1.NotifyAll();
	cout << endl;
}

#include"Header.h"



void main()
{
	srand(time(NULL));
	 
	// у нас один водитель которого мы можем садить как в класс Car напрямую без проверки
	// так и через класс ProxyCar в этот же метод но так как нам нужно

	Driver d1("Vasya", 30);
	//Car car(d1);
	//car.DriveCar(); // вызываеться метод класса Car 
	ProxyCar pc(d1); 
	pc.DriveCar();  // вызываем наш метод (доработанный)

}
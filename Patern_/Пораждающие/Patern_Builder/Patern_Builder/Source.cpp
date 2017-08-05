#include "Header.h"



void main()
{
	Director* dir = new Director();// создаем нового директора
	ABuilder* b1 = new Builder1();// ... и новых строителей(наши компютеры)
	ABuilder* b2 = new Builder2();
	ABuilder* b3 = new Builder3();


	// pc1 = вызываем метод класса директор...( в качестве параметра передаем указатель b3)
	PC pc1 = dir->CreatePC(b3); // ...идем в класс директор (builder->BuildCPU()), 
	//далее в класс Builder1 (BuildCPU())- в наш первый компьютер(там его "строим",
	//потом в класс PC (pc1.AddPart("Intel")), и записываем в вектор.
	pc1.Show();

}
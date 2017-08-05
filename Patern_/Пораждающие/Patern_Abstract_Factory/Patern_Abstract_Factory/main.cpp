#include"Header.h"
#include"Human_header.h"
#include"Orcs_header.h"


void main()
{
	srand(time(NULL));


	HumanFactory* hf = new HumanFactory();// создаем фабрику людей
	Client* ch = new Client(hf);// передаем ее в конструктор клиента и создаем
								// клиента с параметрами человеческой фабрики
	ch->Run();// вызываем в клиенте метод 
	


}
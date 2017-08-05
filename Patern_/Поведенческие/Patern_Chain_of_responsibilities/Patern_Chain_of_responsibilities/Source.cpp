#include"Header.h"



void main()
{
	srand(time(NULL));

	Handler_500* h500 = new Handler_500(10);
	Handler_100* h100 = new Handler_100(50);
	Handler_50*  h50  = new Handler_50(100);

	//устанавливаем следующего обработчика после 500(100) купюры - (h100) или (h50)
	h500->SetHandler(h100); //объекту класса h500 метод SetHandler() пришел в класс через наследование,
							//вместе с полем _next 
 	h100->SetHandler(h50);

	Request rq(600); // создаем объект запроса с суммой
	h500->HandlerRequest(&rq); // начинаем двигаться от первого (h500) отработчика
	rq.Show();

}
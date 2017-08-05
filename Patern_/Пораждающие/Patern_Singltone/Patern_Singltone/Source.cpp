#include"Header.h"


void main()
{
	Singleton * s1 = Singleton::GetInstans();	// вызываем static метод от имени класса (Singleton::GetInstans()) 
												//(:: потому что метод static )
	Singleton * s2 = Singleton::GetInstans();   // при повторной попытке создать объкт уже не получиться 

}
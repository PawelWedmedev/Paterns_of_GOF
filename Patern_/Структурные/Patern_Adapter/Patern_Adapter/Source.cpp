 #include "Header.h"





void main()
{
	cout << "****************class adapter***************************\n";
	MyRectangl *mr = new MyRectangl(100, 100, 500, 800, "blue");
	mr->Show();
	cout << "****************object adapter***************************\n";
	MyRectangl2 *mr2 = new MyRectangl2(200, 200, 300, 500, "dark");
	mr2->Show();


}
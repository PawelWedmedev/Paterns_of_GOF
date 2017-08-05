#include"Header.h"

template<class T>
void SelectSort(vector<T> &v)
{
	SortStrategy<T>* strategy;
	if (v.size() % 2 == 0)
		strategy = new InsertSort<T>;
	else 
		strategy = new QuickSort<T>;
	strategy->Sort(v);	
}



void main()
{
	srand(time(NULL));


	vector <int> v;
	for (int i(0);i < 11; i++)
	{
		v.push_back(rand() % 20);
	}
	for_each(v.begin(), v.end(), [](int a) { cout << a << " " << endl;});
	SelectSort(v);
	cout << "****************\n";
	for_each(v.begin(), v.end(),[](int a){ cout <<a<<" "<<endl;});


}
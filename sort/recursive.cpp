#include <iostream>
using namespace std;



void printA(int n, int i)
{
	if(i == 7)
	{
		return ;
	}
	
	int a = n;
	while(a!=0)
	{
		cout << i;
		a--;
	}

	cout << endl;

	return printA(n,i+1);
}


int main()
{
	int n = 0;

	cin >> n;
	cout << "input value is "<< n << endl;
	
	int i = 1;
	printA(n, i);

	return -1;
}



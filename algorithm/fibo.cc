#include<iostream>
using namespace std;
int Fibo(int n)
{
	if(n == 1||n==0)
		return 1;
	else 
		return Fibo(n-1) + Fibo(n-2);
}


int main()
{
	for(int n=0;n<10;n++)
	{
	cout << Fibo(n) << endl;
	}


	return 0;
}

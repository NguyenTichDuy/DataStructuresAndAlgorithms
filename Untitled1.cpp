#include <iostream>
#include <conio.h>
using namespace std;


int main()
{
	int a;
	cin>>a;
	for(int i; i<=a;i++)
	{
		int D;
		D=a%10;
		a=a/10;
		while(a>=10)
		{
			if(D<10)
			{
				cout<<"/t"<<D;
			}
			
		};
	}
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int x=10,y=20;
	cout<<x<<"|"<<y<<endl;
	// int t=x;x=y;y=t;
	// cout<<x<<"|"<<y<<endl;
	// x=x+y;	y=x-y;	x=x-y;
	// cout<<x<<"|"<<y<<endl;
	x=x^y;
	cout<<x<<"|"<<y<<endl;
	y=x^y;
	cout<<x<<"|"<<y<<endl;
	x=x^y;
	cout<<x<<"|"<<y<<endl;
	x^=y^=x^=y;
	cout<<x<<"|"<<y<<endl;
	return 0;
}
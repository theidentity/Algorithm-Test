#include <iostream>
using namespace std;
int main()
{
	int x=5;
	int y=0;
	cout<<x<<" | "<<y<<endl;
	//Increment
	y=(~x);
	y=-y;
	cout<<x<<" | "<<y<<endl;
	return 0;
}
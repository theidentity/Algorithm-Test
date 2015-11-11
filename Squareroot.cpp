#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

class Squareroot
{
	double sqrt;
public:
	double calcSqrt(int n)
	{
		if(n<=0)
			return 0;
		else
		{
			double oldval=0;
			double newval=n;
			while(oldval!=newval)
			{
				oldval=newval;
				newval=(oldval+n/oldval)/2;
			}
			return newval;
		}
	}
};

int main()
{
	Squareroot s1;
	double val;
	val=1024;	cout<<s1.calcSqrt(val)<<" | "<<sqrt(val)<<endl;
	val=1000;	cout<<s1.calcSqrt(val)<<" | "<<sqrt(val)<<endl;
	val=1000.5268;	cout<<s1.calcSqrt(val)<<" | "<<sqrt(val)<<endl;
	val=35.8965;	cout<<s1.calcSqrt(val)<<" | "<<sqrt(val)<<endl;
	
	return 0;
}


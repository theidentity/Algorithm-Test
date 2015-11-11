#include <iostream>
#include <cstdio>
using namespace std;

class Power
{
	int base, pow;
	double res;
public:
	Power(int b = 1, int p = 0)
	{
		base = b;
		pow = p;
		res = 1;
	}

	double calcPower()
	{
		for (int i = 0; i < pow; i++)
			res = res * base;
		return res;
	}

	double calcPowerOptimal(int b,int p)
	{
		if(p<=0)
			return 1;
		else
		{
			res=calcPowerOptimal(b,p/2);
			if(p%2==0)
				res=res*res;
			else
				res=res*res*b; 
		}
		return res;
	}
};

int main()
{
	Power p1(2,10);
	cout<<p1.calcPowerOptimal(2,10)<<endl;
	return 0;
}
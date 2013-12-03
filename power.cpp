#include <iostream>
#include <assert.h>

using namespace std;

long pow(int base, int exp)
{
	if(exp == 1)
		return base;
	else
		return base * pow(base, exp-1);
}

long pow2(int base, int exp)
{
	if(exp == 1)
		return base;
	else if(exp == 0)
		return 1;
	else
		if(exp % 2 == 0)
			return pow2(base * base, exp/2);
		else
			return base * pow2(base * base, exp/2) ;
}

long pow3(int base, int exp)
{ 
	  if(exp == 1)
			    return base;
		  int x = pow2(base,exp/2);
			  if(exp%2 == 0)
					    return x*x;
				  else
						    return base*x*x;
}

int main()
{
	cout << pow(27,1232) << endl;
	int len = 144;
	cout << sizeof(len)<<endl;
	
}

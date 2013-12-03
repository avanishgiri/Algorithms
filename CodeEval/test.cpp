#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;


int main(int argc, char **argv){
	ifstream file;
	file.open(argv[1]);
	string test;
	long long limit;
	while (!file.eof()) 
	{
		getline(file, test);
		if (test.length() == 0)
           continue; //ignore all empty lines
       	else 
	       	{
			stringstream ss(test);
			ss >> limit;
			limit--;
			long long sqrtlimit = sqrt(limit);

			vector<bool> sieve(limit+1, false);

			for(long long n = 4; n <= limit; n += 2)
				sieve[n] = true;

			for(long long n=3; n <= sqrtlimit; n = n+2){
				if(!sieve[n]){
					cout << n << ",";
					for(long long m = n*n; m<=limit; m=m+(2*n))
						sieve[m] = true;
				}
			}

			long long last;
			for(long long i=limit; i >= 0; i--){
				if(sieve[i] == false){
					last = i;
					break;
				}
			}


			for(long long i=2;i<=limit;i++)
			{
				if(!sieve[i])
					if(i != last)
						cout<<i<<",";
					else
						cout<<i;
			}	
			cout<<endl;
		}
	}
}
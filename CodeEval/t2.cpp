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
	string input;
	long long limit;
	while (!file.eof()) 
	{
		getline(file, input);
		if (input.length() == 0)
        	continue; //ignore all empty lines
       	else 
	    {
			stringstream ss(input);
			ss >> limit;

			if(--limit <= 2)
				continue;

			long long sqrtlimit = sqrt(limit);
			vector<long long> answer;
			vector<bool> sieve(limit+1, false);

			for(long long n = 4; n <= limit; n += 2)
				sieve[n] = true;

			for(long long n=3; n <= sqrtlimit; n = n+2){
				if(!sieve[n]){
					for(long long m = n*n; m<=limit; m=m+(2*n))
						sieve[m] = true;
				}
			}

			cout << 2;
			for(long long i=3;i<=limit;i++)
				if(!sieve[i])
					cout << "," << i;

			cout << endl;
		}
	}
}
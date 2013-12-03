#include <iostream>
using namespace std;

int eratosthenes(int lastNumber)
{
  // initialize
  char* isPrime = new char[lastNumber+1];
  for (int i = 0; i <= lastNumber; i++)
    isPrime[i] = 1;
  // find all non-primes
  for (int i = 2; i*i <= lastNumber; i++)
    if (isPrime[i])
      for (int j = i*i; j <= lastNumber; j += i)
        isPrime[j] = 0;
  // sieve is complete, count primes
  int found = 0;
  for (int i = 2; i <= lastNumber; i++)
    if(isPrime[i])
      cout << "," << i;
  delete[] isPrime;
  return found;
}

int main(){
  eratosthenes(11);
}
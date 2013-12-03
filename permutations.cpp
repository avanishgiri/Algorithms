#include <iostream>

using namespace std;

void swap(char &c1, char& c2){
			char temp = c1;
			c1 = c2;
			c2 = temp;
}

void worker(string& s, int i, int n){
	char array[256];
	bzero(array,256);
	if(i == n)
		cout << s << endl;
	else {
		for(int j = i; j <= n; j++){
			if(!array[s[j]])
			{
				swap(s[i], s[j]);
				worker(s, i+1, n);
				swap(s[i], s[j]);
				array[s[j]] = 1;
			}
		}
	}
}

void permutations(string s){
	worker(s,0,s.length()-1);	
}

int main(){
	permutations("ABB");
}

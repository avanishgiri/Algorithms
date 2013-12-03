#include <iostream>
#include <map>

using namespace std;
int counter = 0;

int match(char c1, char c2){
	return c1 == c2 ? 0 : 1;
}

int edit_distance(string s1, string s2,map<pair<string,string>, int>& memo){
	if(memo[make_pair(s1,s2)])
		return memo[make_pair(s1,s2)];
	int i = s1.size();
	int j = s2.size();
	
	if(s1.empty())
		return memo[make_pair(s1,s2)] = 1 + j;
	if(s2.empty())
		return memo[make_pair(s1,s2)] = 1 + i;

	int opt[3];

	opt[0] = edit_distance(s1.substr(1), s2.substr(1),memo) + match(s1[0],s2[0]);
	opt[1] = edit_distance(s1.substr(1), s2,memo) + 1;
	opt[2] = edit_distance(s1, s2.substr(1),memo) + 1;

	int min = opt[0];
	for(int i = 1; i < 3; i++){
		if(opt[i] < min)
			min = opt[i];
	}
	memo[ make_pair(s1,s2) ] = min;
	return min;	
}

int edit_distance_driver(string s1, string s2){
	map<pair<string,string>,int> memo;
	return edit_distance(s1, s2, memo);
}

int main(){
	cout << edit_distance_driver("thou shalt not","you should not") << endl;
}

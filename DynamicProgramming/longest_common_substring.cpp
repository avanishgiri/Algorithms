#include <iostream>
#include <set>
using namespace std;

set<string> longest_common_substring(string s1, string s2){
	int len1 = s1.length();
	int len2 = s2.length();
	int longest_current_match = 0;
	set<string> matches;

	int matrix[len1+1][len2+1];
	
	for(int i = 0; i < len1+1; i++)
		for(int j = 0; j < len2+1; j++)
			matrix[i][j] = 0;

	for(int i = 0; i < len1; i++)
		for(int j = 0; j < len2; j++){
			if(s1[i] == s2[j]){
				int substr_length = matrix[i][j] + 1;
				matrix[i+1][j+1] = substr_length;
				if(substr_length >= longest_current_match){
					string substring = s1.substr(i-substr_length+1, substr_length);
					if(substr_length == longest_current_match)
						matches.insert(substring);
					else{
						longest_current_match = substr_length;
						matches.clear();
						matches.insert(substring);
					}
				}
			}
		}

	return matches;
}

int main(){
	set<string> matches = longest_common_substring("substraingstring", "substringastring");
	for(set<string>::iterator it = matches.begin(); it != matches.end(); it++)
		cout << *it << endl;
}

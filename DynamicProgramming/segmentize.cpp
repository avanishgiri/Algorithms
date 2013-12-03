#include <iostream>
#include <set>
using namespace std;

bool contains(const set<string>& dict, const string& s){
	return dict.find(s) != dict.end();
}

string segmentize(const string s, const set<string>& dict){
	if(contains(dict,s))
		return s;
	int len = s.size();
	for(int i = 1; i < len; i++){
		string prefix = s.substr(0,i);
		if(contains(dict,prefix)) {
			string suffix = s.substr(i);
			string segmentation = segmentize(suffix,dict);
			if(!segmentation.empty()){
				return prefix + " " + segmentation;
			}
		}
	}
	return "";
}

		

		

int main(){
	string array[] = {"h","e","ll", "o", "whatsup", "wha"};
	set<string> dict (array, array+5);
	cout << segmentize("hello",dict) << endl;
	cout << segmentize("asdfd",dict) << endl;
}

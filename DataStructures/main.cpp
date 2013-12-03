#include "h1.h"

int main(){
	Heap<string> H;
	H.insert("Hi ");
	H.insert("I guess that's just emotion");
	H.insert("fasdfadsfdfd");
	
	while(H.empty())
		cout << H.dequeue() << endl;
}

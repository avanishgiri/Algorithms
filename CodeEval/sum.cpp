#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
	ifstream in(argv[0], ifstream::in | ifstream::binary);
    in.seekg(0, ifstream::end);
    cout << (int)in.tellg(); 
}
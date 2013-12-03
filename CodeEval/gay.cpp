#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char ** argv){
ifstream file;
file.open(argv[1]);
while (!file.eof()) 
   {

       int x;
       file >> x;
       {
           if((x) % 2 == 0)
                cout << 1 << endl;
           else
                cout << 0 << endl;
       }
}
}

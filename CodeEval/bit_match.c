#include <stdio.h>

bool bit_match(int num, short p1, short p2, bool right_to_left){
	if(right_to_left){
		bit1 = num >> p1 & 1;
		bit2 = num >> p2 & 1;
	}
	return bit1 == bit2;
}

int main(){
	bit_match(85, 2, 3, true)
}
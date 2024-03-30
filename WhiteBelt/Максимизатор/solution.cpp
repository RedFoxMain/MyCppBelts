#include <iostream>

void UpdateIfGreater(int &first, int &second){
	if(first > second) { second = first; }
}

int main(){
	int a=8, b=7;
	UpdateIfGreater(a, b);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}
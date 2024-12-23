#include <iostream>

int NOD(int a, int b){
	int c = a;
	while(a%c!=0 || b%c!=0){
		c--;
	}
	return c;
}
int main(int argc, char *argv[])
{
	std::cout << NOD(100,3);
}

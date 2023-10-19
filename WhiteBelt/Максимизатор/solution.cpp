#include <iostream>

using namespace std;

void UpdateIfGreater(int first, int &second){
	if(first > second){
		second = first;
	}
}

int main(int argc, char *argv[])
{
	int first = 7;
	int second = 3;
	UpdateIfGreater(first, second);
	cout << second;
}

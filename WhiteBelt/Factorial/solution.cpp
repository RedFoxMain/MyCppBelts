#include <iostream>

using namespace std;

int factorial(int N){
	if(N==1 || N < 0){
		return 1;
	}
	return N*factorial(N-1);
}

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	cout << factorial(N);
}
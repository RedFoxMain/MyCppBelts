#include <iostream>

long factorial(int N){
	return (N <= 1)? 1 : N*factorial(N-1);
}

int main(){
        int N;
        std::cin >> N;
        std::cout << factorial(N);
}
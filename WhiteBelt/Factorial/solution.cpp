#include <iostream>

long factorial(int N){
        if(N<=1){ return 1; }
        return N*factorial(N-1);
}

int main(int argc, char *argv[])
{
        int N;
        std::cin >> N;
        std::cout << factorial(N);
}
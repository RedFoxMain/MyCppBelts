#include <iostream>

int main(){
	std::string expr, operation;
	int N, num;
	std::cin >> expr;
	std::cin >> N;
	for (size_t i = 0; i < N; ++i){
		std::cin >> operation;
		std::cin.ignore(1);
		std::cin >> num;
		expr = "(" + expr + ")" + operation + "" + std::to_string(num);
	}
	std::cout << expr << std::endl;
}
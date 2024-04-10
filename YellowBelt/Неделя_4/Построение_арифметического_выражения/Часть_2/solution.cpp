#include <iostream>
#include <deque>

int main(int argc, char *argv[]){
	std::string expr;
	char operation, current;
	int N, num;
	std::deque<std::string> deq;
	std::cin >> expr;
	deq.push_back(expr);

	std::cin >> N;
	for (int i = 0; i < N; i++){
		std::cin >> operation;
		std::cin.ignore(1);
		switch (operation){
		case '+':
			deq.push_back("+");
			current = '+';
			break;
		case '-':
			deq.push_back("-");
			current = '-';
			break;
		case '*':
			if (current == '+' || current == '-'){
				deq.push_front("(");
				deq.push_back(")");
			}
			deq.push_back("*");
			current = '*';
			break;
		case '/':
			if (current == '+' || current == '-'){
				deq.push_front("(");
				deq.push_back(")");
			}
			deq.push_back("/");
			current = '/';
			break;
		}
		std::cin >> num;
		deq.push_back(std::to_string(num));
	}
	for (auto el : deq){
		std::cout << el << " ";
	}
}
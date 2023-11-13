#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char *argv[])
{
	string expr;
	char operation, current;
	int N, num;
	deque<string> deq;
	cin >> expr;
	deq.push_back(expr);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> operation;
		cin.ignore(1);
		switch(operation){
			case '+':
				deq.push_back("+");
				current = '+';
				break;
			case '-':
				deq.push_back("-");
				current = '-';
				break;
			case '*':
				if(current == '+' || current == '-'){
					deq.push_front("(");
					deq.push_back(")");
				}
				deq.push_back("*");
				current = '*';
				break;
			case '/':
				if(current == '+' || current == '-'){
					deq.push_front("(");
					deq.push_back(")");
				}
				deq.push_back("/");
				current = '/';
				break;
		}
		cin >> num;
		deq.push_back(to_string(num));
	}
	for(auto el: deq){
		cout << el << " ";
	}
}

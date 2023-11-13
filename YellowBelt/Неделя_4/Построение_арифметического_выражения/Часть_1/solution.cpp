#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	string expr, operation;
	int N, num;
	cin >> expr;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> operation;
		cin.ignore(1);
		cin >> num;
		expr = "(" + expr + ") " + operation + " " + to_string(num);
	}
	cout << expr << endl;
}

#include <iostream>
#include <vector>

using namespace std;

void MoveStrings(vector<string> &destinations, vector<string> &source){
	destinations.insert(destinations.end(),source.begin(), source.end());
	source.clear();
}

int main(int argc, char *argv[])
{
	vector<string> source = {"banana","apple"};
	vector<string> destinations = {"carrot"};
	
	MoveStrings(destinations, source);
	
	cout << destinations.size() << endl; // 3
	cout << source.size() << endl; // 0
}

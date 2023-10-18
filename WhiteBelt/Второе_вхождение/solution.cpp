#include <iostream> 
#include <vector>

using namespace std;

int find_f(string text, char symb){
	int target = text.find(symb);
	if(target != -1){
		return text.find(symb, target+1);
	}else{
		return -2;
	}
}

int main(int argc, char *argv[])
{
	string letter = "informative film";
	string letter2 = "film";
	string letter3 = "test";
	cout << find_f(letter, 'f') << endl;
	cout << find_f(letter2, 'f') << endl;
	cout << find_f(letter3, 'f') << endl;
}

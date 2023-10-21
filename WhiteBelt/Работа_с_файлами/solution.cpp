#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	// Задания: Часть 1 и Часть 2
	string lines;
	ifstream file1("test1.txt");
	ofstream file2("copy_test1.txt");
	while (!file1.eof())
	{
		getline(file1, lines);
		file2 << lines << endl;
	}
	file1.close();
}

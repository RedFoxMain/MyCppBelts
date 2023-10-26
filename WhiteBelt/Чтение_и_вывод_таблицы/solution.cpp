#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void readFile(string &text, ifstream &file)
{
	string lines;
	getline(file, text);
	while (getline(file, lines))
	{
		text += lines + '\n';
	}
}

vector<vector<char>> makeVector(string text, int col)
{
	vector<vector<char>> data;
	vector<char> lines;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] != ',')
		{
			if (lines.size() != col)
			{
				lines.push_back(text[i]);
			}
			else
			{
				data.push_back(lines);
				lines.clear();
			}
		}
	}
	return data;
}

int main(int argc, char *argv[])
{
	string text;
	int row, col;
	ifstream file("test1.txt");

	file >> row;
	file.ignore(1, ' ');
	file >> col;

	readFile(text, file);

	for (auto vec : makeVector(text, col))
	{
		for (auto el : vec)
		{
			cout << el << " ";
		}

		cout << endl;
	}
}

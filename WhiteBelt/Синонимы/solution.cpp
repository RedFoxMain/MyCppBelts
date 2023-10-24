#include <iostream>
#include <map>
#include <set>
using namespace std;

void commands(string command, map<string, set<string>> &synonimys, set<string> &added)
{
	if (command == "ADD")
	{
		string word1, word2;
		cout << "Введите синоним: ";
		cin >> word1;
		cout << "Введите синоним: ";
		cin >> word2;

		synonimys[word1].insert(word2);
		synonimys[word2].insert(word1);

		added.insert({word1, word2});
	}
	else if (command == "COUNT")
	{
		string word;
		cout << "Введите слово: ";
		cin >> word;
		cout << synonimys[word].size() << endl;
	}
	else if (command == "CHECK")
	{
		string word1, word2;
		cout << "Введите слово: ";
		cin >> word1;
		cout << "Введите слово: ";
		cin >> word2;
		
		set<string> words = {word1, word2};
		bool isSynonimus = false;
		
		for (auto [key, values] : synonimys)
		{
			if (key == word1 || key == word2)
			{
				for (auto value : values)
				{
					if (word2 == value || word1 == value)
					{
						isSynonimus = true;
					}
				}
			}
		}
		if (isSynonimus)
		{
			cout << "Синонимы!" << endl;
		}
		else
		{
			cout << "Не синонимы!" << endl;
		}
	}
}

int main(int argc, char *argv[])
{
	int Q;
	string command;
	cin >> Q;

	map<string, set<string>> synonimys;
	set<string> added;

	for (int i = 0; i < Q; i++)
	{
		cin >> command;
		commands(command, synonimys, added);
	}
}

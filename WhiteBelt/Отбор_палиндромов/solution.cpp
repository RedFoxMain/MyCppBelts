#include <iostream>
#include <vector>
#include <set>
using namespace std;

// функция возвращает вектор палиндромов, с заданной длиной
vector<string> PalindromFilter(vector<string> words, int maxLen)
{
	vector<string> result;
	for(const auto el: words){
		if(el.size() == maxLen){
			result.push_back(el);
		}
	}
	return result;
}
// проверить палиндром ли это
bool isPalindrom(string palindrom)
{
	string pal = palindrom;
	reverse(palindrom.begin(), palindrom.end());
	if(pal==palindrom){
		return true;
	}
	return false;

}
int main(int argc, char *argv[])
{
	set<string> unique;
	
	int Q, len;
	string palindrom;
	cout << "Кол-во слов: ";
	cin >> Q;
	if (Q < 101)
	{
		for (int i = 0; i < Q; i++)
		{
			cin >> palindrom;
			if (isPalindrom(palindrom))
			{
				unique.insert(palindrom);
			}
		}
	}
	else
	{
		cout << "Кол-во слов не должно быть болше 100";
	}
	cout << "Желаемая длина: ";
        cin >> len;
	vector<string> words(unique.begin(), unique.end());
	for(const auto el: PalindromFilter(words, len)){
		cout << el << endl;
	}
}

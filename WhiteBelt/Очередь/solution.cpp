#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>

using namespace std;

void WORRY(map<int, string> &states)
{
	int people;
	cout << "Какого человека обеспокоить: ";
	cin >> people;
	if (states.count(people))
	{
		states[people] = "worry";
	}
}
void QUIET(map<int, string> &states)
{
	int people;
	cout << "Какого человека успокоить: ";
	cin >> people;
	if (states.count(people))
	{
		states[people] = "quiet";
	}
}
int WORRY_COUNT(map<int, string> &states)
{
	int count = 0;
	for (auto [people, state] : states)
	{
		if (state == "worry")
		{
			count++;
		}
	}
	return count;
}

int main(int argc, char *argv[])
{
	map<int, string> states;
	
	string command;
	int Q;
	cout << "Сколько людей в очереди: ";
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		states[i] = "quiet";
	}

	while (getline(cin, command))
	{
		if (command == "ex")
		{
			break;
		}
		else if (command == "WORRY")
		{
			WORRY(states);
		}
		else if (command == "QUIET")
		{
			QUIET(states);
		}
		else if (command == "WORRY_COUNT")
		{
			cout << WORRY_COUNT(states) << endl;
		}
		else if (command == "COME")
		{
			int k;
			cin >> k;
			if (k > 0)
			{
				for(int i = Q-k; i<Q; ++i){
					states[i]="queit";
				}
			}
			else
			{
				map<int, string> new_states;
				for(int i = 0; i < Q+k; i++){
					new_states[i] = states[i];
				}
				states = new_states;
			}
    }
	}
}

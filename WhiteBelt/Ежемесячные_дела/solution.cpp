#include <iostream>
#include <map>
#include <vector>
using namespace std;
// month
int next(int &current)
{
	map<int, int> current_mon = {
		{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
	return current_mon.at(current);
}

int main(int argc, char *argv[])
{
	map<int, vector<string>> calendar;
	int curr_mon = 1;

	string command;

	int mon = next(curr_mon); // get current month
	while (getline(cin, command))
	{
		if (command == "ex")
		{
			break;
		}
    // add things to do for the month
		if (command == "ADD")
		{
			string todo;
			vector<string> days;
			for (int i = 1; i <= mon; i++)
			{
				cout << "Задание " << mon << " " << i << ": ";
				cin >> todo;
				days.push_back(todo);
			}
			calendar.insert({curr_mon, days});
			
		}
    // move to another month
		else if (command == "NEXT")
		{
			cout << "Переход на другой месяц." << endl;
			if (curr_mon != 12)
			{
				curr_mon++;
			}
			else
			{
				curr_mon = 1;
				
			}
			mon = next(curr_mon);
			
		}
    // get information on the day
		else if (command == "DUMP")
		{
			int day;
			cout << "Введите день: ";
			cin >> day;
			for (auto el : calendar)
			{
				try{
				cout << el.second.at(day-1) << endl;
				}catch(std::out_of_range &err){
					
				}
			}
		}
		mon = next(curr_mon);
	}
}

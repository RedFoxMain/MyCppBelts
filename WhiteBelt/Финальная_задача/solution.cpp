#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;
// validate date
bool isCorrectDate(string date)
{
	vector<string> tokens;
	boost::split(tokens, date, boost::is_any_of("-"));
	if (tokens.size() == 3)
	{
		if (tokens[0].length() == 4 &&
			tokens[1].length() == 2 &&
			tokens[2].length() == 2)
		{
			try
			{
				stoi(tokens[0]);
			}
			catch (std::exception &err)
			{
				cout << "Year value is invalid: " << tokens[0] << endl;
				return false;
			}
			if (tokens[1] > "0" && tokens[1] < "13")
			{
				if (tokens[2] > "0" && tokens[2] < "32")
				{
					return true;
				}
				else
				{
					cout << "Day value is invalid: " << tokens[2] << endl;
				}
			}
			else
			{
				cout << "Month value is invalid: " << tokens[1] << endl;
			}
		}
		else
		{
			cout << "Wrong date format " << date << endl;
		}
	}
	else
	{
		cout << "Wrong date format " << date << endl;
	}
	return false;
}

int main(int argc, char *argv[])
{
	map<string, set<string>> db;

	string command;

	while (getline(cin, command))
	{
		if (command == "ex")
		{
			break;
		}

		else if (command == "ADD")
		{
			string date, event;
			cout << "Дата: ";
			getline(cin, date);
			cout << "Событие: ";
			getline(cin, event);
			if (!event.empty() && isCorrectDate(date))
			{
				db[date].insert(event);
			}
		}
		else if (command == "PRINT")
		{
			for (const auto [date, events] : db)
			{
				cout << date << ": ";
				for (const auto event : events)
				{
					cout << event << " ";
				}
				cout << endl;
			}
		}
		else if (command == "FIND")
		{
			string date;
			cout << "Введите дату: ";
			getline(cin, date);
			if (db.count(date))
			{
				for (string event : db[date])
				{
					cout << event << endl;
				}
			}
			else
			{
				cout << "Нет такой даты: " << date << endl;
			}
		}
		else if (command == "DEL")
		{
			string date, event;
			cout << "Дата: ";
			getline(cin, date);
			cout << "Событие: ";
			getline(cin, event);
			if (!date.empty() && event.empty())
			{
				if (db.count(date))
				{
					cout << "Deleted " << db[date].size() << " events" << endl;
					db.erase(date);
				}
				else
				{
					cout << "Нет такой даты!" << endl;
				}
			}
			else if (!date.empty() && !event.empty())
			{
				if (db.count(date))
				{
					if (db[date].count(event))
					{
						db[date].erase(event);
						cout << "Deleted successfully" << endl;
					}
					else
					{
						cout << "Event not found" << endl;
					}
				}
				else
				{
					cout << "Нет такой даты!" << endl;
				}
			}
		}
		else
		{
			cout << "Unknown command " << command << endl;
		}
	}
}

#include <iostream>
#include <map>
#include <set>
using namespace std;

using Notes = std::map<int, std::set<std::string>>;
using Months = map<int, int>;

int next(int &current){
        Months current_mon = {{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
        return current_mon[current];
}

int main(){
	std::string command, to_do;
	Notes notes;
	int Q, day, current_mon = 1;
	std::cin >> Q;
	for(size_t i = 0; i < Q; ++i){
		std::cin >> command;
		if(command == "ADD"){
			std::cin >> day >> to_do;
			if (day > 0 && day < next(current_mon)) { notes[day].insert(to_do); }
			else { std::cout << "Неверно введен день: " << day << std::endl; continue; }
		}
		if(command == "DUMP"){
			std::cin >> day;
			if (day < next(current_mon)) { for(const auto& el: notes[day]) { std::cout << el << std::endl; } }
			else { std::cout << "Неверно введен день: " << day << std::endl; continue; }
		}
		if(command == "NEXT"){
			notes.clear();
			current_mon++;
		}
	}
	return 0;
}
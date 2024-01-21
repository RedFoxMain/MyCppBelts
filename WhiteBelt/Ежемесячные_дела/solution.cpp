#include <iostream>
#include <map>
#include <set>

using Notes = std::map<int, std::set<std::string>>;
using Months = std::map<int, int>;

// взять максимальный день месяца
int next(int current){
        Months current_mon = {{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
        return current_mon[current];
}

// добавить дело в определенный день
void ADD(Notes& notes, int current_mon){
	int day;
	std::string to_do;
	std::cin >> day >> to_do;
	if (day > 0 && day < next(current_mon)) { notes[day].insert(to_do); }
	else { std::cout << "Неверно введен день: " << day << std::endl; }
}

// получить дела в определенный день
void DUMP(Notes& notes, int current_mon){
	int day;
	std::cin >> day;
	if (day < next(current_mon)) { for(const auto& el: notes[day]) { std::cout << el << std::endl; } }
	else { std::cout << "Неверно введен день: " << day << std::endl; }
}

// следущий месяц
void NEXT(Notes& notes, int& current_mon){
	notes.clear();
	current_mon++;
}

int main(){
	std::string command;
	Notes notes;
	int Q, current_mon = 1;
	std::cin >> Q;
	for(size_t i = 0; i < Q; ++i){
		std::cin >> command;
		if(command == "ADD"){ ADD(notes, current_mon); continue; }
		if(command == "DUMP"){ DUMP(notes, current_mon); continue; }
		if(command == "NEXT"){ NEXT(notes, current_mon); }
	}
	return 0;
}
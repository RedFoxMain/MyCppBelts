#include <iostream>
#include <map>

// Класс для системы
class HSystem{
public:
	// Создать клиента
	void Book(std::string &hotel_name, int time, int client_id, int room_count){
		hotels_[hotel_name][time] = client_id;
		room_count_[hotel_name][time] = room_count;
	}
	// вывести колличество зарегкстрированных персон за день
	void Clients(std::string &hotel_name){
		int count = 0;
		for(const auto &it : hotels_[hotel_name]){
			if(it.first < 86400){
				count++;
			}
		}
		std::cout << count << std::endl;
	}
	
	// вывыести количество занятых комнат
	void Rooms(std::string &hotel_name){
		int sum = 0;
		for(const auto &it : room_count_[hotel_name]){
			if(it.first < 86400 && it.second > 0){
				sum += it.second;
			}
		}
		std::cout << sum << std::endl;
	}
	
private:
	std::map<std::string, std::map<int, int>> hotels_;
	std::map<std::string, std::map<int, int>> room_count_;
};

int main(){
	HSystem system;
	int time, hotel_id, room_count, client_id, N;
	std::string hotel_name, comand;
	std::cin >> N; // количество операций
	for(int i = 0; i < N; ++i){
		std::cin >> comand;
		if(comand == "BOOK"){
			std::cin >> time >> hotel_name >> client_id >> room_count;
			system.Book(hotel_name, time, client_id, room_count); 
		}
		if(comand == "CLIENTS"){
			std::cin >> hotel_name;
			system.Clients(hotel_name);
		}
		if(comand == "ROOMS"){
			std::cin >> hotel_name;
			system.Rooms(hotel_name);
		}
	}
}

#include <iostream>
#include <map>

struct Card{
	std::string hotel_name;
	int time;
	int client_id;
	int room_count;
};

// Класс для системы
class HSystem{
public:
        // Создать клиента
        void Book(Card &card){
                hotels_[card.hotel_name][card.time] = card.client_id;
                room_count_[card.hotel_name][card.time] = card.room_count;
        }
        // вывести колличество зарегкстрированных персон за день
        void Clients(const std::string &hotel_name){
                int count = 0;
                
	            for(const auto &it : hotels_[hotel_name]){
	           	 if(it.first < 86400){
	                	count++;
	                }
	            }
                
                std::cout << count << std::endl;
        }

        // вывыести количество занятых комнат
        void Rooms(const std::string &hotel_name){
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
                        Card card;
                        std::cin >> time >> hotel_name >> client_id >> room_count;
                        card.time = time;
                        card.hotel_name = hotel_name;
                        card.client_id = client_id;
                        card.room_count = room_count;
                        system.Book(card); 
                }
                if(comand == "CLIENTS"){
                        std::cin >> hotel_name;
                        system.Clients(hotel_name);
                }
                if(comand == "ROOMS"){
                        std::cin >> hotel_name;
                        system.Rooms(hotel_name);
                }else{
                	std::cout << "Нет такой команды!" << std::endl;
                }
        }
}
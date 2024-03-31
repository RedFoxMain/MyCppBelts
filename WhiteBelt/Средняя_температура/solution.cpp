#include <iostream>
#include <map>

void midTemp(std::map<int, int> temperature, int days){
	int sum = 0;
	for (const auto [day, temp] : temperature){
		sum += temp;
	}
	int midValue = sum / days;
	std::cout << "Среднее: " << midValue << std::endl;
	std::cout << "Наибольшие: ";
	for (const auto [day, temp] : temperature){
		if (temp > midValue){
			std::cout << temp << " ";
		}
	}
}

int main(){
	std::map<int, int> temperature;
	int days;
	int temper;
	std::cin >> days;
	for (int i = 0; i < days; i++){
		std::cin >> temper;
		temperature[i] = temper;
	}
	midTemp(temperature, days);
}
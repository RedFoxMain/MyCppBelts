#include <iostream>
#include <map>

using namespace std;

void midTemp(map<int, int> temperature, int days){
	int sum = 0;
	for(const auto [day, temp]: temperature){
		sum += temp;
	}
	int midValue = sum/days;
	cout << "Среднее: " << midValue << endl;
	cout << "Наибольшие: ";
	for(const auto [day, temp]: temperature){
		if(temp > midValue){
			cout << temp << " ";
		}
	}
}

int main(int argc, char *argv[])
{
	map<int, int> temperature;
	int days;
	int temper;
	cin >> days;
	for(int i = 0; i<days; i++){
		cin >> temper;
		temperature[i] = temper;
	}
	midTemp(temperature, days);
}

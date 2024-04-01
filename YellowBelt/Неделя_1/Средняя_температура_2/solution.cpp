#include <iostream>
#include <vector>

int main(){
	std::vector<int> days;
	int k, num, sum = 0, mid;
	std::cin >> k;
	for (size_t i = 0; i < k; ++i){
		std::cin >> num;
		sum += num;
		days.push_back(num);
	}
	mid = sum / k;
	std::cout << mid << std::endl;
	for (size_t j = 0; j < days.size(); ++j){
		if (mid < days[j]){
			std::cout << j << " ";
		}
	}
}
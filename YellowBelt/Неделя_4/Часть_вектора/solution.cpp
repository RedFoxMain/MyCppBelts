#include <iostream>
#include <vector>

void PrintVectorPart(const std::vector<int> &numbers){
	auto negative_num = std::find_if(std::begin(numbers), std::end(numbers), [](int x) {
		return x < 0;
	});
	if (negative_num - numbers.begin() != numbers.size()){
		for (int i = 0; i < numbers.size() && numbers[i] >= 0; i++){
			std::cout << numbers[i] << " ";
		}
	}
	else{
		for (auto it=numbers.begin(); it != numbers.end(); ++it){
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
}

int main(){
	PrintVectorPart({6, 1, 8, -5, 4});
	PrintVectorPart({-6, 1, 8, -5, 4});
	PrintVectorPart({6, 1, 8, 5, 4});
}
#include <iostream>
#include <vector>


int main(){
	int N;
	std::vector<int> nums;
	std::cin >> N;
	// наполняем вектор числами от N до 1
	for (int i = N; i >= 1; i--){
		nums.push_back(i);
	}

	do{
		// выводим числа. Чисел в ряду N
		for (int i = 0; i < N; i++){
			std::cout << nums[i] << " ";
		}
		std::cout << std::endl;
	} while (std::prev_permutation(nums.begin(), nums.end()));
}
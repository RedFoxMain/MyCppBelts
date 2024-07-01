#include <iostream>
#include <vector>

std::vector<int> Reversed(const std::vector<int> &vec){
	return {vec.rbegin(), vec.rend()};
}

int main(){
	std::vector<int> vec = {1, 2, 3, 4};
	for (int element : Reversed(vec)){
		std::cout << element << " ";
	}
}
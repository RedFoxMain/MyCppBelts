#include <iostream>
#include <vector>
#include <map>

template<typename T>
T Sqr(T a){
	return a*a;
}

template<typename First, typename Second>
std::pair<First, Second> Sqr(std::pair<First, Second> pair){
	First first = pair.first*pair.first;
	Second second = pair.second*pair.second;
	return {first, second};
}

template<typename T>
std::vector<T> Sqr(const std::vector<T> &vec){
	std::vector<T> result; 
	for(const auto &el: vec){
		result.push_back(Sqr(el));
	}
	return result;
}

template<typename T, typename First, typename Second>
std::map<T, std::pair<First, Second>> Sqr(std::map<T, std::pair<First, Second>> map){
	std::map<T, std::pair<int, int>> result;
	for(const auto [key, val]: map){
		result[key] = Sqr(val);
	}
	return result;
}

int main(){
	// Пример вызова функции
	std::vector<int> v = {1, 2, 3};
	std::cout << "vector:";
	for (int x : Sqr(v)) {
		std::cout << ' ' << x;
	}
	std::cout << std::endl;
	
	std::map<int, std::pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	std::cout << "map of pairs:" << std::endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
	}
}
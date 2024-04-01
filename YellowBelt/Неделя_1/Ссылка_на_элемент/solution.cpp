#include <iostream>
#include <map>

template<typename T, typename Y>
Y& GetRefStrict(std::map<T, Y> &map, T key){
	if(map.count(key) == 0){ throw std::runtime_error("Нет ключа!"); }
	return map.at(key);
}

int main(){
	std::map<int, std::string> m = {{0, "value"}};
	std::string& item = GetRefStrict(m, 0);
	item = "newvalue";
	std::cout << m[0] << std::endl;
}
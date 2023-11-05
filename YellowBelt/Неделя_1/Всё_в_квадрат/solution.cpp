#include <iostream>
#include <vector>
#include <map>
using namespace std;

// перегрузка *
template<typename First, typename Second> 
pair<First,Second> operator *(pair<First, Second> &p1, pair<First, Second> &p2){
	First a = p1.first*p2.first;
	Second b = p2.second*p2.second;
	return {a,b};
}
// Sqr для pair
template<typename T> T Sqr(T x){
	return x*x;
}

// Sqr для vector
template<typename T> vector<T> Sqr(vector<T> vec){
	vector<T> result;
	for(auto el: vec){
		result.push_back(el*el);
	}
	return result;
}

// Sqr для map
template<typename T, typename First, typename Second> 
map<int, pair<int,int>> Sqr(map<T, pair<First, Second>> data){
	map<T, pair<First, Second>> result;
	for(auto [key, pair]: data){
		result[key] = Sqr(pair);
	}
	return result;
}

int main(int argc, char *argv[])
{
	vector<int> v = {1,2,3};
	cout << "Vector: ";
	for(auto el: Sqr(v)){
		cout << el << " ";
	}
	
	cout << endl;
	
	cout << "Map: " <<endl;
	map<int, pair<int, int>> m = {
		{4,{2,2}},
		{7,{4,3}}
	};
	for(auto [key, pair]: Sqr(m)){
		cout << key << " " << pair.first << " " << pair.second << endl;
	}
	
}

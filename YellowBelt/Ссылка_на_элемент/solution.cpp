#include <iostream>
#include <map>
using namespace std;

template<typename N, typename Value>
Value& GetRefStrict(map<N, Value> &dict, N key){
	if(dict.count(key)==0){
		throw runtime_error("No value in the dictionary!");
	}
	Value &v = dict[key];
	return v;
}
int main(int argc, char *argv[])
{
	map<int, string> m = {{0, "value"}};
	string &item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl;
}

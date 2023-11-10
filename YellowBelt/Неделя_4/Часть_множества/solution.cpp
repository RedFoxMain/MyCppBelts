#include <iostream>
#include <set>
#include <vector>
using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
	vector<T> result;
	for(auto el: elements){
		if(el > border){
			result.push_back(el);
		}
	}
	return result;
}

int main(int argc, char *argv[])
{
	for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
      cout << x << " ";
    }
    cout << endl;
  
    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}

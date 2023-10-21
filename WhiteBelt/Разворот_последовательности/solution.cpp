#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v){
	
	vector<int> result;
	for(int i = v.size()-1; i>=0;i--){
		result.push_back(v[i]);
	}
	return result;
}

int main(int argc, char *argv[])
{
	vector<int> vec = {1,2,3,4};
	for(int element: Reversed(vec)){
		cout << element << endl;
	}
}

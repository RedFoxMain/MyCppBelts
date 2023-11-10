#include <iostream>
#include <vector>
using namespace std;

void PrintVectorPart(const vector<int>& numbers){
	auto negative_num = find_if(begin(numbers), end(numbers), [](int x){
		return x < 0;
	}); 
	if(negative_num-numbers.begin() != numbers.size()){
		for(int i = 0; i < numbers.size() && numbers[i]>=0; i++){
			cout << numbers[i] << " ";
		}
	}else{
		for(int i = numbers.size()-1; i >= 0; i--){
			cout << numbers[i] << " ";
		}
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	PrintVectorPart({6, 1, 8, -5, 4});
	PrintVectorPart({-6, 1, 8, -5, 4});
    PrintVectorPart({6, 1, 8, 5, 4});
}

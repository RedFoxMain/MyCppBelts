#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	int N;
	vector<int> nums;
	cin >> N;
	// наполняем вектор числами от N до 1
	for(int i = N; i >=1 ; i--){
		nums.push_back(i);
	}
	
	do{
		// выводим числа. Чисел в ряду N
		for(int i = 0; i < N; i++){
			cout << nums[i] << " ";
		}
		cout << endl;
	}while(prev_permutation(nums.begin(), nums.end()));
	
}

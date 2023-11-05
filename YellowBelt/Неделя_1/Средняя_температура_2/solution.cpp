#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	vector<int> days;
	int k, num, sum=0, mid;
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> num;
		sum += num;
		days.push_back(num);
	}
	mid = sum/k;
	cout << mid << endl;
	for(int j = 0; j < days.size(); j++){
		if(mid < days[j]){
			cout << j << " ";
		}
	}
}

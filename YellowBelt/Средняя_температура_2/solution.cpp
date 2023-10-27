#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	vector<int> days;
	int k, num, sum=0;
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> num;
		sum += num;
		days.push_back(num);
	}
	for(int j = 0; j < days.size(); j++){
		if((sum/k) < days[j]){
			cout << "День "<<  j << endl;
		}
	}
}

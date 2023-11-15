#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
        int Q,k;
        vector<int> nums;

        cin >> Q;
        for(int i = 0; i < Q; i++){
                cin >> k;
                nums.push_back(k);
        }

        sort(nums.begin(), nums.end(), [](int &a, int &b){
        	return abs(a) < abs(b);
        });

        for(int el: nums){
                cout << el << " ";
        }
}
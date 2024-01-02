#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& vec){
        vector<int> reversed;
        for(int i = vec.size()-1; i>=0; --i){
                reversed.push_back(vec[i]);
        }
        return reversed;
}

int main(int argc, char *argv[])
{
        vector<int> vec = {1,2,3,4};
        for(int element: Reversed(vec)){
                cout << element << " ";
        }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	int size_of_vector = range_end-range_begin;
	if(size_of_vector < 2){
		return;
	}else{
		vector<typename RandomIt::value_type> vec(range_begin, range_end);
		
		RandomIt mid1 = begin(vec) + size_of_vector/3;
		RandomIt mid2 = mid1 + size_of_vector/3;
		vector<typename RandomIt::value_type> temp;
			
		MergeSort(begin(vec), mid1);
		MergeSort(mid1, mid2);
		MergeSort(mid2, end(vec));
		
		merge(begin(vec), mid1, mid1, mid2, back_inserter(temp));
		merge(begin(temp), end(temp), mid2, end(vec), range_begin);
		
	}
}

int main(int argc, char *argv[]){
	vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
      cout << x << " ";
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
        int size_of_vector = range_end-range_begin;
        if(size_of_vector < 2){
                return;
        }else{
                std::vector<typename RandomIt::value_type> vec(range_begin, range_end);

                RandomIt mid = std::begin(vec) + size_of_vector/2;
                MergeSort(std::begin(vec), mid);
                MergeSort(mid, std::end(vec));

                merge(std::begin(vec), mid, mid, std::end(vec), range_begin);
        }
}

int main(){
    std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(std::begin(v), std::end(v));
    for (int x : v) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
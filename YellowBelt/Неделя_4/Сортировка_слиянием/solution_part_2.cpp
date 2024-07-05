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

                RandomIt mid1 = std::begin(vec) + size_of_vector/3;
                RandomIt mid2 = mid1 + size_of_vector/3;
                std::vector<typename RandomIt::value_type> temp;

                MergeSort(std::begin(vec), mid1);
                MergeSort(mid1, mid2);
                MergeSort(mid2, std::end(vec));

                merge(std::begin(vec), mid1, mid1, mid2, std::back_inserter(temp));
                merge(begin(temp), std::end(temp), mid2, std::end(vec), range_begin);

        }
}

int main(){
    std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(std::begin(v), std::end(v));
    for (int x : v) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
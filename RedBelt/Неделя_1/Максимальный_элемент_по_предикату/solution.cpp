#include <cctype>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred){
    ForwardIterator r = std::max_element(first, last, pred);
    return r;
}

int main(){
        std::vector<int> array = {4,3,8,12,14};
        auto a = max_element_if(std::begin(array), std::end(array), [](int a, int b){ return a < b && b%2==0; });
        std::cout << a-std::begin(array) << std::endl;

        std::vector<std::string> text = {"One", "two", "Three", "One", "Two", "Three", "one", "Two", "three"};
        auto b = max_element_if(std::begin(text), std::end(text), [](std::string a, std::string b){ return a.length() < b.length() && isupper(b.front());});
        std::cout << b-std::begin(text) << std::endl;
 }
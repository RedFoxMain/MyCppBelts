#include <cctype>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
  
template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator l    ast, UnaryPredicate pred){
    ForwardIterator r = max_element(first, last, pred);
    return r;
}

int main(){
        vector<int> array = {4,3,8,12,14};
        auto a = max_element_if(begin(array), end(array), [](int a, int b){ 16         return a < b && b%2==0;
        });
        cout << a-begin(array) << endl;
   
        vector<string> text = {"One", "two", "Three", "One", "Two", "Three"    , "one", "Two", "three"};                                               21
        auto b = max_element_if(begin(text), end(text), [](string a, string     b){                                                                    23         return a.length() < b.length() && isupper(b.front());
        });
        cout << b-begin(text) << endl;
 }

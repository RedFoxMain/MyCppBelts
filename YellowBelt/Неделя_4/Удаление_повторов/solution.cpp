
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements){
	sort(elements.begin(), elements.end());
	elements.erase(unique(elements.begin(), elements.end()), elements.end());
}

int main(int argc, char *argv[])
{
	 vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
    RemoveDuplicates(v1);
    for (int x : v1) {
      cout << x << " ";
    }
    cout << endl;
    
    vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
    RemoveDuplicates(v2);
    for (const string& s : v2) {
      cout << s << " ";
    }
    cout << endl;
}
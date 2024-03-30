#include <iostream>
#include <vector>

void MoveStrings(std::vector<std::string> &destinations, std::vector<std::string> &source){
        destinations.insert(destinations.end(), source.begin(), source.end());
        source.clear();
}

int main(){
        std::vector<std::string> source = {"banana","apple"};
        std::vector<std::string> destinations = {"carrot"};

        MoveStrings(destinations, source);

        std::cout << destinations.size() << std::endl; // 3
        std::cout << source.size() << std::endl; // 0
}
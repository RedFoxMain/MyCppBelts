#include <iostream>
#include <algorithm>

void binary(int bin_num){
        std::string str;
        while (bin_num > 0){
                int remainder = bin_num % 2;
                str += std::to_string(remainder);
                bin_num = bin_num / 2;
        }
        std::reverse(str.begin(), str.end());
        std::cout << str << std::endl;
}

int main(){
        binary(182);
}
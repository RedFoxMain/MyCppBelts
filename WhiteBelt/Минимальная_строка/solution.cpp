#include <iostream>

int main(int argc, char *argv[])
{
        std::string word1, word2, word3;
        std::cin >> word1 >> word2 >> word3;
        
        std::string min = word1;
        int minLen = word1.length();
        
        if(word2.length() < minLen){
        	min = word2;
        	minLen = word2.length();
        }
        if(word3.length() < minLen){
        	min = word3;
        	minLen = word3.length();
        }
        std::cout << min << std::endl;
}
#include <iostream>
#include <algorithm>

// второе вхождение f
int find_symbol(const std::string& text, const char& symb){
	int in_text = std::count(begin(text), end(text), symb);
	int position_of_first_symbol = text.find(symb);
	if(in_text == 1) { return -1;}
	if(in_text == 0) { return -2;}
	return text.find(symb, position_of_first_symbol + 1);
}

int main(){
        std::string letter = "informative film";
        std::string letter2 = "film";
        std::string letter3 = "test";
        std::cout << find_symbol(letter, 'f') << std::endl;
        std::cout << find_symbol(letter2, 'f') << std::endl;
        std::cout << find_symbol(letter3, 'f') << std::endl;
}
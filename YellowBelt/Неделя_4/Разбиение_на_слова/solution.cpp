#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> SplitIntoWords(const std::string &s){
	std::vector<std::string> words;
	std::string word;
	std::stringstream sstream(s);
	while (!sstream.eof()){
		std::getline(sstream, word, ' ');
		words.push_back(word);
	}
	return words;
}

int main(){
	std::string s = "C Cpp Java Python";

	std::vector<std::string> words = SplitIntoWords(s);
	std::cout << words.size() << " " << std::endl;
	for (auto it = begin(words); it != end(words); ++it){
		if (it != begin(words)){
			std::cout << "/";
		}
		std::cout << *it;
	}
	std::cout << std::endl;
}
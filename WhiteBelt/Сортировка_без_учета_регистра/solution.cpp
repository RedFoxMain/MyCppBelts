#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

std::string setLowerCase(std::string word){
	for (int i = 0; i < word.length(); i++){
		word[i] = std::tolower(word[i]);
	}
	return word;
}

int main(){
	std::vector<std::string> words;

	int Q;
	std::string word;

	std::cin >> Q;
	for (int i = 0; i < Q; i++){
		std::cin >> word;
		words.push_back(word);
	}
	std::sort(words.begin(), words.end(), [](std::string word1, std::string word2) {
		return setLowerCase(word1) < setLowerCase(word2);
	});
	for (const auto el : words){
		std::cout << el << std::endl;
	}
}
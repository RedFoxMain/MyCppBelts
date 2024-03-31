#include <iostream>
#include <map>
#include <set>

using Map = std::map<std::string, std::set<std::string>>;
Map synonimous;

void Add(const std::string &word1, const std::string &word2){
	synonimous[word1].insert(word2);
	synonimous[word2].insert(word1);
}

void Count(const std::string &word){
	std::cout << synonimous[word].size() << std::endl;
}

void Check(const std::string &word1, const std::string &word2){
	std::cout << synonimous[word1].count(word2) << std::endl;
}

int main(){
	int Q;
	std::string command;
	std::cin >> Q;
	
	for (int i = 0; i < Q; i++){
		std::cin >> command;
		if(command == "ADD"){
			std::string word1, word2;
			std::cin >> word1 >> word2;
			Add(word1, word2);
		}
		if(command == "COUNT"){
			std::string word;
			std::cin >> word;
			Count(word);
		}
		if(command == "CHECK"){
			std::string word1, word2;
			std::cin >> word1 >> word2;
			Check(word1, word2);
		}
	}
}
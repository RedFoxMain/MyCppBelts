#include <iostream>
#include <vector>
#include <set>

// функция возвращает вектор палиндромов, с заданной длиной
std::vector<std::string> PalindromFilter(const std::vector<std::string> &words, int maxLen){
        std::vector<std::string> result;
        for(const auto el: words){
        	if(el.size() == maxLen){
            	result.push_back(el);
            }
        }
        return result;
}
// проверить палиндром ли это
bool isPalindrom(std::string palindrom){
	std::string pal = palindrom;
    std::reverse(palindrom.begin(), palindrom.end());
    if(pal==palindrom){
    	return true;
    }
    return false;
}

int main(){
        std::set<std::string> unique;

        int Q, len;
        std::string palindrom;
        std::cout << "Кол-во слов: ";
        std::cin >> Q;
        if (Q < 101){
        	for (int i = 0; i < Q; i++){
            	std::cin >> palindrom;
                if (isPalindrom(palindrom)){
                	unique.insert(palindrom);
                }
            }
        }
        else{
            std::cout << "Кол-во слов не должно быть болше 100";
        }
        std::cout << "Желаемая длина: ";
        std::cin >> len;
        std::vector<std::string> words(unique.begin(), unique.end());
        for(const auto el: PalindromFilter(words, len)){
                std::cout << el << std::endl;
        }
}
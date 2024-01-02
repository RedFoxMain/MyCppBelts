#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string setLowerCase(string word){
        for (int i = 0; i < word.length(); ++i){
                word[i] = tolower(word[i]);
        }
        return word;
}

int main(){
        vector<string> words;

        int Q;
        string word;

        cin >> Q;
        for (int i = 0; i < Q; ++i){
                cin >> word;
                words.push_back(word);
        }
        sort(words.begin(), words.end(), [](string word1, string word2){
                return setLowerCase(word1) < setLowerCase(word2);
        });
        for (const auto el : words){
	        cout << el << endl;
        }
}
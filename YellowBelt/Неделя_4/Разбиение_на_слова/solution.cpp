#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> SplitIntoWords(const string& s){
	vector<string> words;
	string word;
	stringstream sstream(s);
	while(!sstream.eof()){
		getline(sstream, word, ' ');
		words.push_back(word);
	}
	return words;
}

int main(int argc, char *argv[])
{
	string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " " << endl;
    for (auto it = begin(words); it != end(words); ++it) {
      if (it != begin(words)) {
        cout << "/";
      }
      cout << *it;
    }
    cout << endl;
}

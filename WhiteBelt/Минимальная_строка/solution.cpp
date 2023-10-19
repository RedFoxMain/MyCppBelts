#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>
using namespace std;


int main(int argc, char *argv[])
{
	string text = "film apple banana";
	vector<string> words;
	boost::split(words, text, boost::is_any_of(" "));
	cout << *max_element(words.begin(), words.end());
}

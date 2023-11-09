#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix)
{
	auto start_position = lower_bound(range_begin, range_end, prefix, [](const string& value, char pref){
		return value[0] < pref;
	});

	auto end_position = upper_bound(start_position, range_end, prefix, [](char pref, const string& value){
		return value[0] > pref;
	});

	return make_pair(start_position, end_position);
}


int main(int argc, char *argv[])
{
	const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

	const auto m_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
	for (auto it = m_result.first; it != m_result.second; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	const auto p_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
	cout << (p_result.first - begin(sorted_strings)) << " " << (p_result.second - begin(sorted_strings)) << endl;
    
    const auto z_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
	cout << (z_result.first - begin(sorted_strings)) << " " << (z_result.second - begin(sorted_strings)) << endl;
    
}

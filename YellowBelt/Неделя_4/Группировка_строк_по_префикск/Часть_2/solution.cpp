#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string &prefix)
{
	
	auto start_position = lower_bound(range_begin, range_end, prefix);
	
	char second_char = prefix[1];
    string new_prefix = string(1, prefix[0]) + string(1,  ++second_char);
    
	auto end_position = upper_bound(start_position, range_end, new_prefix);

	return make_pair(start_position, end_position);
}
int main(int argc, char *argv[])
{
	const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
	const auto mo_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
	for (auto it = mo_result.first; it != mo_result.second; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	const auto mt_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " << (mt_result.second - begin(sorted_strings)) << endl;
  
  const auto na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;
  

}

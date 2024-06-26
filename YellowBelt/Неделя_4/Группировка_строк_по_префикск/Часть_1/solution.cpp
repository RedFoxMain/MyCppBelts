#include <iostream>
#include <algorithm>
#include <vector>

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix){
	auto start_position = std::lower_bound(range_begin, range_end, prefix, [](const std::string &value, char pref) {
		return value[0] < pref;
	});

	auto end_position = std::upper_bound(start_position, range_end, prefix, [](char pref, const std::string &value) {
		return value[0] > pref;
	});

	return make_pair(start_position, end_position);
}

int main(){
	const std::vector<std::string> sorted_strings = {"moscow", "murmansk", "vologda"};

	const auto m_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
	for (auto it = m_result.first; it != m_result.second; ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	const auto p_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
	std::cout << (p_result.first - begin(sorted_strings)) << " " << (p_result.second - begin(sorted_strings)) << std::endl;

	const auto z_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
	std::cout << (z_result.first - begin(sorted_strings)) << " " << (z_result.second - begin(sorted_strings)) << std::endl;
}
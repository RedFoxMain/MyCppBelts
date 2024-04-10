#include <iostream>
#include <vector>

enum class Gender{
	FEMALE,
	MALE
};

struct Person{
	int age;
	Gender gender;
	bool is_employed;
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end){
	if (range_begin == range_end){
		return 0;
	}
	std::vector<typename InputIt::value_type> range_copy(range_begin, range_end);
	auto middle = begin(range_copy) + range_copy.size() / 2;
	std::nth_element(
		begin(range_copy), middle, end(range_copy),
		[](const Person &lhs, const Person &rhs) {
			return lhs.age < rhs.age;
		});
	return middle->age;
}

void PrintStats(std::vector<Person> persons){
	auto female_age = std::partition(begin(persons), end(persons), [](const Person &p) {
		return p.gender == Gender::FEMALE;
	});

	auto female_employed = std::partition(begin(persons), female_age, [](const Person &p) {
		return p.is_employed;
	});

	auto male_employed = std::partition(female_age, end(persons), [](const Person &p) {
		return p.is_employed;
	});

	std::cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << std::endl;
	std::cout << "Median age for females = " << ComputeMedianAge(persons.begin(), female_age) << std::endl;
	std::cout << "Median age for males = " << ComputeMedianAge(female_age, persons.end()) << std::endl;
	std::cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), female_employed) << std::endl;
	std::cout << "Median age for unemployed females = " << ComputeMedianAge(female_employed, female_age) << std::endl;
	std::cout << "Median age for employed males = " << ComputeMedianAge(female_age, male_employed) << std::endl;
	std::cout << "Median age for unemployed males = " << ComputeMedianAge(male_employed, persons.end()) << std::endl;
}

int main(){
	std::vector<Person> persons = {
		{31, Gender::MALE, false},
		{40, Gender::FEMALE, true},
		{24, Gender::MALE, true},
		{20, Gender::FEMALE, true},
		{80, Gender::FEMALE, false},
		{78, Gender::MALE, false},
		{10, Gender::FEMALE, false},
		{55, Gender::MALE, true},
	};
	PrintStats(persons);
	return 0;
}
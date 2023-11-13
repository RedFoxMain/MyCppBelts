#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string getDataByYear(int year, map<int, string> history){
	auto r = history.upper_bound(year);
	string name;
	if(r != history.begin()){
		--r;
		name = r->second;
	}
	return name;
}

class Person{
  public:
	void ChangeFirstName(int year, const string &first_name){
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string &last_name){
		last_names[year] = last_name;
	}
	string GetFullName(int year){
		auto first_name = getDataByYear(year, first_names);
		auto last_name = getDataByYear(year, last_names);
		if(first_name.empty() && last_name.empty()){
			return "Incognito!";
		}
		if(last_name.empty()){
			return first_name + " unknown last name";
		}
		if(first_name.empty()){
			return last_name + " unknown first name";
		}else{
			return first_name + " " + last_name;
		}
	}

  private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main(int argc, char *argv[]){
	  Person person;
  
	  person.ChangeFirstName(1965, "Polina");
	  person.ChangeLastName(1967, "Sergeeva");
	  for (int year : {1900, 1965, 1990}) {
	    cout << person.GetFullName(year) << endl;
	  }
	  
	  person.ChangeFirstName(1970, "Appolinaria");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullName(year) << endl;
	  }
	  
	  person.ChangeLastName(1968, "Volkova");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullName(year) << endl;
	  }
}

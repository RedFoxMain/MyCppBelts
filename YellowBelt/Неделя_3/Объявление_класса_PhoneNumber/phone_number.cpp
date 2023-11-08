#include <iostream>
#include <sstream>
#include "phone_number.h"

using namespace std;

// конструктор класса
PhoneNumber::PhoneNumber(const string &international_number)
{
	stringstream stream(international_number);
	if(stream.peek() != '+'){
		throw invalid_argument("Invalid number");
	}
	getline(stream, country_code_, '-');
	getline(stream, city_code_, '-');
	getline(stream, local_number_);

	
}
// функция получения кода страны
string PhoneNumber::GetCountryCode() const
{
	if(!country_code_.empty()){ return country_code_; }
	else{ throw invalid_argument("Invalid country code"); }
}
// функция получения кода города
string PhoneNumber::GetCityCode() const
{
	if(!city_code_.empty()){ return city_code_; }
	else{ throw invalid_argument("Invalid city code"); }
}
// функция получения локального номера
string PhoneNumber::GetLocalNumber() const
{
	if(!local_number_.empty()){ return local_number_; }
	else{ throw invalid_argument("Invalid local number"); }
}
// функция получения международного номера
string PhoneNumber::GetInternationalNumber() const
{
	return country_code_+"-"+city_code_+"-"+local_number_;
}

int main(){
	PhoneNumber phone("+7-45-124-90");
	cout << phone.GetCountryCode() << endl;
	cout << phone.GetCityCode() << endl;
	cout << phone.GetLocalNumber() << endl;
	cout << phone.GetInternationalNumber() << endl;
	return 0;
}

#include <iostream>
#include <sstream>
#include "phone_number.h"

// конструктор класса
PhoneNumber::PhoneNumber(const std::string &international_number){
        stringstream stream(international_number);
        if(stream.peek() != '+'){
                throw invalid_argument("Invalid number");
        }
        getline(stream, country_code_, '-');
        getline(stream, city_code_, '-');
        getline(stream, local_number_);


}
// функция получения кода страны
std::string PhoneNumber::GetCountryCode() const{
        if(!country_code_.empty()){ return country_code_; }
        else{ throw invalid_argument("Invalid country code"); }
}
// функция получения кода города
std::string PhoneNumber::GetCityCode() const{
        if(!city_code_.empty()){ return city_code_; }
        else{ throw invalid_argument("Invalid city code"); }
}
// функция получения локального номера
std::string PhoneNumber::GetLocalNumber() const{
        if(!local_number_.empty()){ return local_number_; }
        else{ throw invalid_argument("Invalid local number"); }
}
// функция получения международного номера
std::string PhoneNumber::GetInternationalNumber() const{
        return country_code_+"-"+city_code_+"-"+local_number_;
}

int main(){
        PhoneNumber phone("+7-45-124-90");
        std::cout << phone.GetCountryCode() << std::endl;
        std::cout << phone.GetCityCode() << std::endl;
        std::cout << phone.GetLocalNumber() << std::endl;
        std::cout << phone.GetInternationalNumber() << std::endl;
        return 0;
}
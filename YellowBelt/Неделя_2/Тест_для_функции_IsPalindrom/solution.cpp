#include <iostream>
#include <sstream>

class TestRunner{
  public:
	template <typename A, typename B>
	void AssertionEqual(A a, B b){
		std::ostringstream os;
		if (a != b){
			os << a << " != " << b << " Тест: " << test;
			throw std::runtime_error(os.str());
		}
		test++;
	}

  private:
	int test = 1;
};

// функция для проверки на палиндром
bool IsPalindrom(const std::string &str){
	bool answer = true;

	if (str.size() != 0){
		for (int i = 0; i < (str.size() / 2); i++){
			int j = str.size() - (i + 1);
			if (str[i] != str[j]){
				answer = false;
				break;
			}
		}
	}

	return answer;
}
// тест для функции IsPslindrom
void TestIsPalindrom(TestRunner &tr, std::string text, bool result){
	tr.AssertionEqual(IsPalindrom(text), result);
}

int main(){
	TestRunner tr;

	TestIsPalindrom(tr, "Nikita", false);
	TestIsPalindrom(tr, "a b a", true);
	TestIsPalindrom(tr, "c vc", false);
	TestIsPalindrom(tr, "le v el", true);
	TestIsPalindrom(tr, "", true);
	std::cout << "Ok" << std::endl;
}
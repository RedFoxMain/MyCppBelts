#include <iostream>

struct Specialization{
public:
	std::string specialization_;
	explicit Specialization(std::string specialization): specialization_(specialization) {}
};

struct Course{
public:
	std::string course_;
	explicit Course(std::string course): course_(course) {}
};

struct Week{
public:
	std::string week_;
	explicit Week(std::string week): week_(week) {}
};

struct LectureTitle {
public:
	Specialization spec_;
	Course course_;
	Week week_;
	LectureTitle(Specialization spec, Course course, Week week):
		spec_(spec), course_(course), week_(week) {}
};

int main(){
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
}
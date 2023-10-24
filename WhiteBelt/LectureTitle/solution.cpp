#include <iostream>

using namespace std;

struct Specialization
{
	string specialization;
	Specialization(string specialization){
		specialization = "";
	}
};

struct Course
{
	string course;
	Course(string course){
		course = "";
	}
};

struct Week
{
	string week;
	Week(string week){
		week = "";
	}
};

struct LectureTitle
{
	string specialization, course, week;
	
	LectureTitle(Specialization spec, Course course, Week week){
		this->specialization = spec.specialization;
		this->course = course.course;
		this->week = week.week;
	}
};

int main(int argc, char *argv[])
{
	LectureTitle lec(
	Specialization("c++"),
	Course("white belt"),
	Week("4th"));
}

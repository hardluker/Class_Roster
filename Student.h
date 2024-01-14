#pragma once
#include <string>
#include "Degree.h"
using namespace std;
class Student
{
public:

	//Accessors (Getters) for the Student attributes
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getDaysToCompleteEachCourse() const;
	DegreeProgram* getDegreeProgram() const;

	//Mutators (Setters) for the Student attributes
	void setStudentID(const string& studentID);
	void setFirstName(const string& firstName);
	void setLastName(const string& firstName);
	void setEmailAddress(const string& emailAddress);
	void setAge(int age);
	void setDaysToCompleteEachCourse(int* daysToCompleteEachCourse);




private:
	//Private attributes per the encapsulation paradigm
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCompleteEachCourse[3];
	DegreeProgram degreeProgram;

};


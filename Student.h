#pragma once
#include <string>
#include <array>
#include <iostream>
#include "Degree.h"

using namespace std;

class Student
{
public:
	//Constant variable for array size to be accessed throughout the program
	static const int SIZE = 3;
	


	//Constructor
	Student(const string& studentID,
			const string& firstName,
			const string& lastName,
			const string& emailAddress,
			int age,
			const int* daysToCompleteEachCourse,
			DegreeProgram degreeProgram);

	//Accessors (Getters) for the Student attributes
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	const int* getDaysToCompleteEachCourse() const;
	DegreeProgram getDegreeProgram() const;

	//Mutators (Setters) for the Student attributes
	void setStudentID(const string& studentID);
	void setFirstName(const string& firstName);
	void setLastName(const string& lastName);
	void setEmailAddress(const string& emailAddress);
	void setAge(int age);
	void setDaysToCompleteEachCourse(int* daysToCompleteEachCourse);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Print Function
	void print();
	

private:

	//Private attributes per the encapsulation paradigm
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCompleteEachCourse[SIZE];
	DegreeProgram degreeProgram;

};


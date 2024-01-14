#pragma once
#include "Student.h"
#include <string>
using namespace std;

//Constant variable for consolidation of array size
static const int numberOfStudents = 5;

//String array containing all the student data
const string studentData[numberOfStudents] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Donald,Azevedo,dba9514@gmail.com,28,10,20,30,SOFTWARE"
};

class Roster
{
public:

	//Methods for adding and removing data from the roster
	void parse();
	void add(const string& studentID, const string& firstName, const string& lastName,
		     const string& emailAddress, int age, int daysInCourse1,
		     int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(const string& studentID);

	//Printing methods
	void printAll();
	void printAverageDaysInCourse(const string& studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	//Accessor Method
	Student** getClassRosterArray();

	//Destructor
	~Roster();
private:
	
	Student* classRosterArray[numberOfStudents] = { nullptr };

	//Additional utility methods
	DegreeProgram strToDegreeProgram(const string& degreeProgramStr);
	string strToUpper(string string);
};


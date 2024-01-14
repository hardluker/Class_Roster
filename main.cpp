#include <iostream>
#include "Roster.h"
#include "Student.h"
using namespace std;

int main() {
	cout << "Course Title: Scripting and Programming Applications - C867" << endl
		 << "Programming Language Used: C++" << endl
		 << "Name: Donald Azevedo" << endl
		 << "WGU Student ID: 011371173" << endl;

	Roster classRoster;
	classRoster.parse(); //Data to be parsed is in the Roster.h file
	classRoster.printAll();
	classRoster.printInvalidEmails();

	//Looping through the students and printing the average days
	int numberOfStudents = 5;
	Student** classRosterArray = classRoster.getClassRosterArray();
	for (int i = 0; i < numberOfStudents; i++)
		classRoster.printAverageDaysInCourse(classRosterArray[i]->getStudentID());

	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

	return 0;
}
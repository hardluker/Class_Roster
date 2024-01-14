#include "Roster.h"
#include <iostream>
#include <sstream>

//Method to parse the data in the string array
void Roster::parse()
{
	
	for (int i = 0; i < numberOfStudents; i++) 
	{
		//Setting up string stream and creating the token
		istringstream stringStream(studentData[i]);
		string token;

		//Declaring student variables and attributesQty
		const int ATTRIBUTES_QTY = 9;
		string studentID, firstName, lastName, emailAddress;
		int age, daysInCourse1, daysInCourse2, daysInCourse3;
		DegreeProgram degreeProgram;

		//Assigning all the attributes
		for (int j = 1; j <= ATTRIBUTES_QTY; j++) 
		{
			getline(stringStream, token, ',');

			switch (j)
			{

			case 1:
				studentID = token;
				break;
			case 2:
				firstName = token;
				break;
			case 3:
				lastName = token;
				break;
			case 4:
				emailAddress = token;
				break;
			case 5:
				age = stoi(token);
				break;
			case 6:
				daysInCourse1 = stoi(token);
				break;
			case 7:
				daysInCourse2 = stoi(token);
				break;
			case 8:
				daysInCourse3 = stoi(token);
				break;
			case 9:
				degreeProgram = strToDegreeProgram(token);
				break;
			}


		}
		//Adding the parsed data to the roster
		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

	}
}

//Method to add students to the roster
void Roster::add(const string& studentID, const string& firstName, const string& lastName,
	             const string& emailAddress, int age, int daysInCourse1, 
	             int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	//Creating the student object pointer.
	int daysToCompleteEachCourse[Student::SIZE] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* student = new Student{ studentID, firstName, lastName, 
		                            emailAddress, age, 
		                            daysToCompleteEachCourse, degreeProgram };
	//Adding the student to the next available slot in the array.
	for (int i = 0; i < numberOfStudents; i++)
		if (classRosterArray[i] == nullptr) 
		{
			classRosterArray[i] = student;
			break; //Breaking out to only add once.
		}

}

//Method to remove students from the roster
void Roster::remove(const string& studentID)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			return; // Exit the function early if a student was found
		}
	}
	cout << "Student was not found with the ID: " << studentID;
}

//Method to print all students
void Roster::printAll()
{
	cout << "Printing all current students in the roster" << endl;
	for (int i = 0; i < numberOfStudents; i++)
		if (classRosterArray[i] != nullptr)
			classRosterArray[i]->print();
}

//Method to print the average days a student spent in a course
void Roster::printAverageDaysInCourse(const string& studentID)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		int sum = 0;
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			const int* daysArray = classRosterArray[i]->getDaysToCompleteEachCourse();
			for (int j = 0; j < Student::SIZE; j++) {
				sum += daysArray[j];
			}
			double average = static_cast<double>(sum) / Student::SIZE;
			cout << "Student ID: " << classRosterArray[i]->getStudentID() << " The average days in a course is: " << average << endl;
			return;
		}
	}
	cout << "Student was not found with the ID: " << studentID;
}

//Method for printing invalid emails
void Roster::printInvalidEmails()
{
	for (int i = 0; i < numberOfStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			bool atChar = false;
			bool dotChar = false;
			bool spaceChar = false;
			string email = classRosterArray[i]->getEmailAddress();
			for (char& c : email) {
				if (c == '@')
					atChar = true;
				if (c == '.')
					dotChar = true;
				if (c == ' ')
					spaceChar = true;
			}
			if (atChar == false || dotChar == false || spaceChar == true)
				cout << "Student ID: " << classRosterArray[i]->getStudentID() << " Invalid Email: " << email << endl;
		}
		
	}
}

//Method for printing the student by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "Printing by Degree Program" << endl;
	for (int i = 0; i < numberOfStudents; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}

	}
}

//Accessor method for the classRosterArray
Student** Roster::getClassRosterArray()
{
	return this->classRosterArray;
}


//Utility method for converting strings to DegreeProgram Enums
DegreeProgram Roster::strToDegreeProgram(const string& degreeProgramStr)
{

	if (strToUpper(degreeProgramStr) == "SECURITY")
		return DegreeProgram::SECURITY;
	else if (strToUpper(degreeProgramStr) == "NETWORK")
		return DegreeProgram::NETWORK;
	else if (strToUpper(degreeProgramStr) == "SOFTWARE")
		return DegreeProgram::SOFTWARE;
	else
		return DegreeProgram::UNDECIDED; //Handling undefinded case

}

//Utility method for converting strings to Uppercase
string Roster::strToUpper(string string)
{
	for (char& c : string)
		c = toupper(c);
	return string;
}

//Deleting allocated memory
Roster::~Roster()
{
	for (int i = 0; i < numberOfStudents; i++)
		delete this->classRosterArray[i];
	delete this;
}
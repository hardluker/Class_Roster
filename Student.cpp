#include "Student.h"


// Accessor (Getter) implementations
string Student::getStudentID() const
{
    return this->studentID;
}

string Student::getFirstName() const
{
    return this->firstName;
}

string Student::getLastName() const
{
    return this->lastName;
}

string Student::getEmailAddress() const
{
    return this->emailAddress;
}

int Student::getAge() const
{
    return this->age;
}

const int* Student::getDaysToCompleteEachCourse() const
{
    return this->daysToCompleteEachCourse;
}

DegreeProgram Student::getDegreeProgram() const
{
    return this->degreeProgram;
}

// Mutator (Setter) Implementations
void Student::setStudentID(const string& studentID)
{
    this->studentID = studentID;
}

void Student::setFirstName(const string& firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(const string& firstName)
{
    this->lastName = lastName;
}

void Student::setEmailAddress(const string& emailAddress)
{
    this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDaysToCompleteEachCourse(int* daysToCompleteEachCourse)
{
    //Utilizing the static SIZE variable for iteration through the loop
    for (int i = 0; i < Student::SIZE; i++) {
        this->daysToCompleteEachCourse[i] = daysToCompleteEachCourse[i];
    }
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    this->degreeProgram = degreeProgram;
}



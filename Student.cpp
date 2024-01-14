#include "Student.h"

//Constructor implementation
Student::Student

    //Constructor Parameters
    (const string& studentID, 
     const string& firstName, 
     const string& lastName, 
     const string& emailAddress, 
     int age, 
     const int* daysToCompleteEachCourse, 
     DegreeProgram degreeProgram) :

    //Member initializer list
    studentID(studentID),
    firstName(firstName),
    lastName(lastName),
    emailAddress(emailAddress),
    age(age),
    degreeProgram(degreeProgram)

{
    // Setting the values for the daysToCompleteEachCourse array
    for (int i = 0; i < Student::SIZE; i++) {
        this->daysToCompleteEachCourse[i] = daysToCompleteEachCourse[i];
    }
}



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

void Student::setLastName(const string& lastName)
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

void Student::print()
{
    cout << getStudentID() << "\t"
         << "First Name: " << getFirstName() << "\t"
         << "Last Name: " << getLastName() << "\t"
         << "Email Address: " << getEmailAddress() << "\t"
         << "Age: " << getAge() << "\t";
    cout << "Days in Course: {";

    for (int i = 0; i < SIZE; i++) {
        cout << daysToCompleteEachCourse[i];
        if (i != SIZE - 1)
            cout << ", ";
        else
            cout << "}\t";
    }

    cout << "Degree Program: ";
    if (degreeProgram == SECURITY)
        cout << "SECURITY" << endl;
    else if (degreeProgram == NETWORK)
        cout << "NETWORK" << endl;
    else if (degreeProgram == SOFTWARE)
        cout << "SOFTWARE" << endl;
    else if (degreeProgram == UNDECIDED)
        cout << "UNDECIDED";
}



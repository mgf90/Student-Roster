#include <iostream>
#include "Student.h"
using std::string;
using std::cout;
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 20;
    for (int i = 0; i < daysToCompleteSize; i++) this->days[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}


Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysToCompleteSize; i++) this->days[i] = days[i];
    this->degreeProgram = degreeProgram;
}


Student::~Student() {}

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[]) { for (int i = 0; i < daysToCompleteSize; i++) this->days[i] = days[i]; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader()
{
    cout << "Format: Student ID | First Name | Last Name | Email | Age | Days to Complete Program | Degree Program\n";
}

void Student::print()
{
    cout << this->getStudentID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}
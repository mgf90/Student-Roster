#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
    const static int daysToCompleteSize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int days[daysToCompleteSize];
    DegreeProgram degreeProgram;
public:
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);
    ~Student();

    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();

    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    static void printHeader();

    void print();
};

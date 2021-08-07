#pragma once
#include "student.h"

class Roster
{
private:
    int lastArrayIndex = -1;
    const static int numStudents = 5;
    // Student* classRosterArray[numStudents];

public:
    Student* classRosterArray[numStudents];
    void parse(string row);
    void add(string studentID, string firstName, string lastName, string email, int age,
        int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();

};

#include "roster.h"

void Roster::parse(string studentData)
{
    int rs = studentData.find(",");
    string studentID = studentData.substr(0, rs);

    int ls = rs + 1;
    rs = studentData.find(",", ls);
    string firstName = studentData.substr(ls, rs - ls);

    ls = rs + 1;
    rs = studentData.find(",", ls);
    string lastName = studentData.substr(ls, rs - ls);

    ls = rs + 1;
    rs = studentData.find(",", ls);
    string email = studentData.substr(ls, rs - ls);

    ls = rs + 1;
    rs = studentData.find(",", ls);
    int age = stoi(studentData.substr(ls, rs - ls));

    ls = rs + 1;
    rs = studentData.find(",", ls);
    int day1 = stoi(studentData.substr(ls, rs - ls));

    ls = rs + 1;
    rs = studentData.find(",", ls);
    int day2 = stoi(studentData.substr(ls, rs - ls));

    ls = rs + 1;
    rs = studentData.find(",", ls);
    int day3 = stoi(studentData.substr(ls, rs - ls));

    DegreeProgram degreeProgram;
    if (studentData.back() == 'K') degreeProgram = NETWORK;
    if (studentData.back() == 'E') degreeProgram = SOFTWARE;
    if (studentData.back() == 'Y') degreeProgram = SECURITY;
    add(studentID, firstName, lastName, email, age, day1, day2, day3, degreeProgram);
}


void Roster::add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degreeProgram)
{
    int dayarray[3] = { days1, days2, days3 };
    classRosterArray[++lastArrayIndex] = new Student(studentID, firstName, lastName, email, age, dayarray, degreeProgram);
}

void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastArrayIndex; i++)
    {

        classRosterArray[i]->print();

    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastArrayIndex; i++)
    {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
            classRosterArray[i]->print();

        cout << "\n";
    }
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastArrayIndex; i++)
    {
        string sEmail = (classRosterArray[i]->getEmail());
        if (sEmail.find('@') == string::npos || sEmail.find('.') == string::npos || sEmail.find(' ') != string::npos)
        {
            any = true;
            cout << sEmail << ": " << classRosterArray[i]->getLastName() << "\n";
        }
    }
    if (!any) cout << "NONE\n";
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastArrayIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            cout << classRosterArray[i]->getStudentID() << ": ";
            cout << (classRosterArray[i]->getDays()[0]
                + classRosterArray[i]->getDays()[1]
                + classRosterArray[i]->getDays()[2])
                / 3.0 << "\n";
        }
        /*cout << classRosterArray[i]->getStudentID() << ": ";
        cout << (classRosterArray[i]->getDays()[0]
            + classRosterArray[i]->getDays()[1]
            + classRosterArray[i]->getDays()[2])
            / 3.0 << "\n";*/

    }
    cout << "\n";
}

void Roster::remove(string StudentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastArrayIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == StudentID)
        {
            success = true;
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[1];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastArrayIndex--;
        }
    }
    if (success)
    {
        cout << StudentID << " was removed from class roster.\n";
        this->printAll();
    }
    else cout << "Error: " << StudentID << " was not found.\n";

}

Roster::~Roster()
{
    cout << "Time to destruct, ha ha ha!\n";
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << "\n";
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
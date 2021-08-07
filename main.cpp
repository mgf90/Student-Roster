#include <iostream>
#include "roster.h"
/* #include "student.h"
#include "degree.h"
#include "roster.cpp"
#include "student.cpp" */
using std::string;
using std::cout;


int main()
{
    cout << "Scripting and Programming Applications\n" << "C++\n";
    cout << "001539795\n" << "Moses Farmer\n";

    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Moses,Farmer,mfarm51@wgu.edu,30,4,7,9,SOFTWARE"
    };

    const int numStudents = 5;
    Roster classRoster;

    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    cout << "Here are all of the students: \n";
    classRoster.printAll();
    cout << "\n";

    cout << "Students with invalid emails: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    cout << "Average days to complete courses: " << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());

    }
    for (int i = 0; i < 3; i++)
    {
        cout << "Ordered by degree program: " << degreeProgramStrings << "\n";
        classRoster.printByDegreeProgram((DegreeProgram)i);
    }

    cout << "Removing student A3:\n";
    classRoster.remove("A3");
    cout << "\n";

    cout << "Removing student A3:\n";
    classRoster.remove("A3");
    cout << "\n";

    system("pause");
    return 0;
}
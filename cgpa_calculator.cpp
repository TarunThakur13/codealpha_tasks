#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Course {
public:
    string courseName;
    int creditHours;
    double gpa;

    Course(string name, int credits, string grade) {
        courseName = name;
        creditHours = credits;
        gpa = mapGradeToPoint(grade);
    }

private:
    double mapGradeToPoint(const string& grade) {
        if (grade == "A+") return 10.0;
        if (grade == "A")  return 9.0;
        if (grade == "B+") return 8.0;
        if (grade == "B")  return 7.0;
        if (grade == "C")  return 6.0;
        if (grade == "D")  return 5.0;
        return 0.0; // F or invalid grades
    }
};

int main() {
    int totalCourses;
    cout << "Enter total number of courses: ";
    cin >> totalCourses;

    vector<Course> courseList;
    for (int i = 0; i < totalCourses; ++i) {
        string name, grade;
        int credits;

        cout << "\nCourse " << (i + 1) << " name: ";
        cin >> name;
        cout << "Credit hours: ";
        cin >> credits;
        cout << "Grade (A+, A, B+, B, C, D, F): ";
        cin >> grade;

        courseList.emplace_back(name, credits, grade);
    }

    double totalGradePoints = 0.0;
    int totalCreditHours = 0;

    for (const auto& course : courseList) {
        totalGradePoints += course.gpa * course.creditHours;
        totalCreditHours += course.creditHours;
    }

    double cgpa = (totalCreditHours > 0) ? (totalGradePoints / totalCreditHours) : 0.0;

    cout << fixed << setprecision(2);
    cout << endl << "Your CGPA is: " << cgpa << endl;

    return 0;
}

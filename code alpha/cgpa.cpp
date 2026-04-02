#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
float gradeToPoint(char grade) {
    switch(grade) {
        case 'A': return 10;
        case 'B': return 8;
        case 'C': return 6;
        case 'D': return 4;
        case 'F': return 0;
        default: return 0;
    }
}
int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;
    vector<char> grades(n);
    vector<int> credits(n);
    float totalCredits = 0, totalPoints = 0;
    for(int i = 0; i < n; i++) {
        cout << "\nCourse " << i+1 << endl;
        cout << "Enter grade (A/B/C/D/F): ";
        cin >> grades[i];
        cout << "Enter credit hours: ";
        cin >> credits[i];
        float gradePoint = gradeToPoint(grades[i]);
        totalCredits += credits[i];
        totalPoints += gradePoint * credits[i];
    }
    float cgpa = totalPoints / totalCredits;
    cout << "\n RESULT \n";
    for(int i = 0; i < n; i++) {
        cout << "Course " << i+1 
             << " | Grade: " << grades[i] 
             << " | Credits: " << credits[i] << endl;
    }
    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nCGPA: " << cgpa << endl;
    return 0;
}
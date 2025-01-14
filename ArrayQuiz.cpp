#include <iostream>
#include <string>
#include <limits>

using namespace std;


const int MAXSTUDENTS = 50;

void addStudent(string names[], double grades[], int& count);
void displayStudents(const string names[], const double grades[], int count);
double calculateAverage(const double grades[], int count);
void findHighestLowest(const string names[], const double grades[], int count);

int main() {
    string names[MAXSTUDENTS];
    double grades[MAXSTUDENTS];
    int count = 0;
    int choice;

    do {

        cout << "\nMenu:\n";
        cout << "1. Add a student and their grade\n";
        cout << "2. Display all students and their grades\n";
        cout << "3. Calculate and display the average grade\n";
        cout << "4. Find and display the highest and lowest grades\n";
        cout << "Please Enter a choice by selecting a number from 1-4: ";
        cin >> choice;


        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error, please enter a number between 1 and 4.\n";
            continue;
        }


        switch (choice) {
            case 1:
                addStudent(names, grades, count);
                break;
            case 2:
                displayStudents(names, grades, count);
                break;
            case 3:
                cout << "Average grade: " << calculateAverage(grades, count) << endl;
                break;
            case 4:
                findHighestLowest(names, grades, count);
                break;
            default:
                cout << "Error, please choose a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}

void addStudent(string names[], double grades[], int& count) {
    if (count >= MAXSTUDENTS) {
        cout << "Maximum number of students reached.\n";
        return;
    }

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, names[count]);
    cout << "Enter grade: ";
    cin >> grades[count];

    if (cin.fail() || grades[count] < 0 || grades[count] > 100) {
        cout << "Error, please enter a number between 0 and 100.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    count++;
    cout << "Student added successfully.\n";
}


void displayStudents(const string names[], const double grades[], int count) {
    if (count == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\nList of students and their grades:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << names[i] << " - " << grades[i] << "\n";
    }
}

double calculateAverage(const double grades[], int count) {
    if (count == 0) {
        cout << "No grades to calculate average.\n";
        return 0.0;
    }

    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return sum / count;
}


void findHighestLowest(const string names[], const double grades[], int count) {
    if (count == 0) {
        cout << "No students to find highest and lowest grades.\n";
        return;
    }

    int highestIndex = 0;
    int lowestIndex = 0;

    for (int i = 1; i < count; i++) {
        if (grades[i] > grades[highestIndex]) {
            highestIndex = i;
        }
        if (grades[i] < grades[lowestIndex]) {
            lowestIndex = i;
        }
    }

    cout << "Highest grade: " << grades[highestIndex] << " - " << names[highestIndex] << "\n";
    cout << "Lowest grade: " << grades[lowestIndex] << " - " << names[lowestIndex] << "\n";
}

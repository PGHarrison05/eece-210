#include <iostream>
#include <string>

using namespace std;

const int Maxstudents = 50;

void addStudent(string names[], double grades[], int& count) {
    if (count < Maxstudents) {
        cout << "Enter student name: ";
        cin.ignore();  // Ignore any leftover newline character
        getline(cin, names[count]);

        cout << "Enter student grade: ";
        cin >> grades[count];

        count++;
        cout << "Student added successfully!\n";
    } else {
        cout << "Maximum number of students reached.\n";
    }
}

void displayStudents(const string names[], const double grades[], int count) {
    cout << "Student Name\tGrade\n";
    for (int i = 0; i < count; i++) {
        cout << names[i] << "\t\t" << grades[i] << endl;
    }
}

double calculateAverage(const double grades[], int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return count > 0 ? sum / count : 0;  // Avoid division by zero
}

void findHighestLowest(const string names[], const double grades[], int count) {
    if (count == 0) {
        cout << "No students to evaluate.\n";
        return;
    }

    int highestIndex = 0, lowestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (grades[i] > grades[highestIndex]) {
            highestIndex = i;
        }
        if (grades[i] < grades[lowestIndex]) {
            lowestIndex = i;
        }
    }

    cout << "Highest Grade: " << names[highestIndex] << " (" << grades[highestIndex] << ")" << endl;
    cout << "Lowest Grade: " << names[lowestIndex] << " (" << grades[lowestIndex] << ")" << endl;
}

int main() {
    string names[Maxstudents];
    double grades[Maxstudents];
    int count = 0;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add a student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average grade\n";
        cout << "4. Find highest and lowest grades\n";
        cout << "5. Exit\n";
        cout << "Enter your choice from 1-5: ";
        cin >> choice;
        cin.ignore();  // Ignore newline character left in buffer

        switch (choice) {
            case 1:
                addStudent(names, grades, count);
                break;
            case 2:
                displayStudents(names, grades, count);
                break;
            case 3:
                cout << "The Average grade: " << calculateAverage(grades, count) << endl;
                break;
            case 4:
                findHighestLowest(names, grades, count);
                break;
            case 5:
                cout << "Thank You for using this program!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib> // for exit()

using namespace std;

class Student {
private:
    int rollno, age;
    string name;

public:
    Student(int stdId, string stdName, int stdAge) {
        rollno = stdId;
        name = stdName;
        age = stdAge;
    }

    void setRollno(int stdId) {
        rollno = stdId;
    }

    int getRollno() {
        return rollno;
    }

    void setName(string stdName) {
        name = stdName;
    }

    string getName() {
        return name;
    }

    void setAge(int stdAge) {
        age = stdAge;
    }

    int getAge() {
        return age;
    }

    void displayStudent() {
        cout << "Roll No: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Create function to update Student record
void updateStudent(vector<Student> &students) {
    string sname;
    bool found = false;
    int choice;

    cout << "\t\tEnter Name to Update Record: ";
    cin.ignore();
    getline(cin, sname);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == sname) {
            found = true;
            cout << "\t\t---Student Found -----" << endl;
            cout << "\t\t 1. Update Rollno " << endl;
            cout << "\t\t 2. Update Name " << endl;
            cout << "\t\t 3. Update Age " << endl;
            cout << "\t\tEnter Your Choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                int rno;
                cout << "\t\tEnter New Rollno: ";
                cin >> rno;
                students[i].setRollno(rno);
                break;
            }
            case 2: {
                string name;
                cout << "\t\tEnter New Name: ";
                cin.ignore();
                getline(cin, name);
                students[i].setName(name);
                break;
            }
            case 3: {
                int age;
                cout << "\t\tEnter New Age: ";
                cin >> age;
                students[i].setAge(age);
                break;
            }
            default:
                cout << "\t\tInvalid Choice" << endl;
            }
            return; // Exit the function once the student is found and updated
        }
    }
    if (!found) {
        cout << "\t\tRecord Not Found" << endl;
    }
}

// Create function to search Student in list
void SearchStudent(vector<Student> &students) {
    int rollno;
    cout << "\t\tEnter Rollno: ";
    cin >> rollno;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getRollno() == rollno) {
            cout << "\t\t--------Student Found ------------" << endl;
            students[i].displayStudent();
            return;
        }
    }
    cout << "\t\tStudent Not Found" << endl;
}

// Create function to show all list of students
void DisplayAllStudent(vector<Student> &students) {
    if (students.empty()) {
        cout << "\t\tNo Student Found" << endl;
        return;
    }
    for (int i = 0; i < students.size(); i++) {
        students[i].displayStudent();
        cout << endl;
    }
}

// Create function to add new student
void addNewStudent(vector<Student> &students) {
    int rollno, age;
    string name;
    cout << "Enter Rollno: ";
    cin >> rollno;

    // Check if student already exists
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getRollno() == rollno) {
            cout << "\t\tStudent Already Exists" << endl;
            return;
        }
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;

    Student newStudent(rollno, name, age);
    students.push_back(newStudent);
}

// Create function to delete student in list
void deleteStudent(vector<Student> &students) {
    string name;
    cout << "Enter Name to Delete: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == name) {
            students.erase(students.begin() + i);
            cout << "\t\tStudent Removed Successfully" << endl;
            return;
        }
    }
    cout << "\t\tStudent Not Found" << endl;
}

int main() {
    vector<Student> students;
    students.push_back(Student(1, "ali", 35));
    char choice;

    do {
        int op;
        cout << "\n\t\t--------------------------------";
        cout << "\n\t\t*** Student Management System ***";
        cout << "\n\t\t--------------------------------";
        cout << "\n\t\t 1. Add New Student" << endl;
        cout << "\t\t 2. Display All Students" << endl;
        cout << "\t\t 3. Search Student" << endl;
        cout << "\t\t 4. Update Student" << endl;
        cout << "\t\t 5. Delete Student" << endl;
        cout << "\t\t 6. Exit" << endl;
        cout << "\t\t Enter Your Choice: ";
        cin >> op;

        switch (op) {
        case 1:
            addNewStudent(students);
            break;
        case 2:
            DisplayAllStudent(students);
            break;
        case 3:
            SearchStudent(students);
            break;
        case 4:
            updateStudent(students);
            break;
        case 5:
            deleteStudent(students);
            break;
        case 6:
            exit(0);
        default:
            cout << "\t\tInvalid Choice" << endl;
        }

        cout << "\t\tDo You Want to Continue [Yes/No]? : ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer to avoid issues with the next input

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

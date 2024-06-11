Description :
The Student Management System is a console-based application designed to manage student records efficiently. 
This system allows for adding, updating, searching, displaying, and deleting student information. It is implemented in C++ using Object-Oriented Programming principles and provides an intuitive menu-driven interface for users.

Features :
Add New Student: Input and store a new student's roll number, name, and age. The system checks for duplicate roll numbers to prevent redundancy.
Display All Students: Retrieve and display the details of all students currently stored in the system.
Search Student: Find and display a student's details using their roll number.
Update Student: Update the roll number, name, or age of an existing student by searching with their name.
Delete Student: Remove a student's record from the system by searching with their name.

Functionality:
Student Class: Encapsulates student details such as roll number, name, and age. Provides methods to set and get these attributes, as well as a method to display the student's information.
Menu-Driven Interface: A simple text-based interface that prompts users to choose actions like adding, updating, searching, displaying, and deleting student records.
Input Validation: Ensures that duplicate roll numbers are not added and handles cases where a student is not found for updating or deleting.
Data Storage: Uses a vector to dynamically store student objects, providing efficient management and manipulation of student records.

Tech Stack
C++: The programming language used to develop the application.
Standard Template Library (STL): Utilized for the vector container to manage dynamic lists of students.
Object-Oriented Programming (OOP): Design principle used to structure the code and manage student data efficiently.

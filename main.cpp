#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "date.h"
#include "address.h"
#include "student.h"

void testAddress();
void testDate();
void testStudent(std::vector<Student>& students);
void printAllStudentNames(const std::vector<Student>& students);
void printAllStudentData(const std::vector<Student>& students);
void findStudent(const std::vector<Student>& students);
void loadStudentsFromCSV(const std::string& filename, std::vector<Student>& students);

int main() {
    std::vector<Student> students;  // Store the student objects in a vector
    
    // Load students from CSV file
    loadStudentsFromCSV("students.csv", students);
    
    int option;
    do {
        // Show menu
        std::cout << "0) quit" << std::endl;
        std::cout << "1) print all student names" << std::endl;
        std::cout << "2) print all student data" << std::endl;
        std::cout << "3) find a student" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> option;
        
        // Handle user input
        switch(option) {
            case 0:
                std::cout << "Goodbye!" << std::endl;
                break;
            case 1:
                printAllStudentNames(students);
                break;
            case 2:
                printAllStudentData(students);
                break;
            case 3:
                findStudent(students);
                break;
            default:
                std::cout << "Invalid option, try again!" << std::endl;
                break;
        }
    } while (option != 0);
    
    return 0;
} // end main

void testAddress() {
    Address a;
    a.init("123 W Main St", "Muncie", "IN", "47303");
    a.printAddress();
} 

void testDate() {
    Date d;
    d.init("01/27/1997");
    d.printDate();
} 

void printAllStudentNames(const std::vector<Student>& students) {
    std::cout << "All student names:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.getLastFirst() << std::endl;
    }
}

void printAllStudentData(const std::vector<Student>& students) {
    std::cout << "All student data:" << std::endl;
    for (const auto& student : students) {
        student.printStudent();
        std::cout << std::endl;
    }
}

void findStudent(const std::vector<Student>& students) {
    std::string searchName;
    std::cout << "Enter the student's name (Last, First): ";
    std::cin.ignore(); 
    std::getline(std::cin, searchName);
    
    bool found = false;
    for (const auto& student : students) {
        if (student.getLastFirst() == searchName) {
            student.printStudent();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Student not found." << std::endl;
    }
}


void loadStudentsFromCSV(const std::string& filename, std::vector<Student>& students) {
    std::ifstream file(filename);
    std::string line;
    
    
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string firstName, lastName, street, city, state, zip, birthDateStr, gradDateStr, scoreStr;
        
      
        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, street, ',');
        std::getline(ss, city, ',');
        std::getline(ss, state, ',');
        std::getline(ss, zip, ',');
        std::getline(ss, birthDateStr, ',');
        std::getline(ss, gradDateStr, ',');
        std::getline(ss, scoreStr, ',');
        
        
        std::string studentData = firstName + "," + lastName + "," + street + "," + city + "," + state + "," + zip + "," + birthDateStr + "," + gradDateStr + "," + scoreStr;
        
        Student student;
        student.init(studentData);
        
        students.push_back(student);
    }
    std::cout << "Loaded " << students.size() << " students from " << filename << std::endl;
}


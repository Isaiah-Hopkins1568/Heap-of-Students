#include "student.h"
#include <sstream> // For stringstream to parse the studentString
#include <iomanip> // For formatting dates (optional)

Student::Student() : firstName(""), lastName(""), score(0) {}

Student::~Student() {}

void Student::init(const std::string& studentString) {
    std::stringstream ss(studentString);
    std::string temp;

    // Parse first and last name (assumed comma-separated)
    std::getline(ss, lastName, ',');
    std::getline(ss, firstName, ',');

    // Parse address (assumed address format in studentString)
    std::string street, city, state, zip;
    std::getline(ss, street, ',');
    std::getline(ss, city, ',');
    std::getline(ss, state, ',');
    std::getline(ss, zip, ',');
    address.init(street, city, state, zip);

    // Parse birthdate (MM/DD/YYYY)
    std::getline(ss, temp, ',');
    birthDate.init(temp);

    // Parse graduation date (MM/DD/YYYY)
    std::getline(ss, temp, ',');
    graduationDate.init(temp);

    // Parse score (assuming it's an integer)
    std::getline(ss, temp, ',');
    score = std::stoi(temp);
}

void Student::printStudent() const {
    std::cout << "" << firstName << " " << lastName << std::endl;
    std::cout << "";
    address.printAddress();
    std::cout << "";
    birthDate.printDate();
    std::cout << "";
    graduationDate.printDate();
    std::cout << "" << score << std::endl;
}

std::string Student::getLastFirst() const {
    return lastName + ", " + firstName;
}


#include "student.h"
#include <sstream> 
#include <iomanip>

Student::Student() : firstName(""), lastName(""), score(0) {}

Student::~Student() {}

void Student::init(const std::string& studentString) {
    std::stringstream ss(studentString);
    std::string temp;

    
    std::getline(ss, lastName, ',');
    std::getline(ss, firstName, ',');

    
    std::string street, city, state, zip;
    std::getline(ss, street, ',');
    std::getline(ss, city, ',');
    std::getline(ss, state, ',');
    std::getline(ss, zip, ',');
    address.init(street, city, state, zip);


    std::getline(ss, temp, ',');
    birthDate.init(temp);


    std::getline(ss, temp, ',');
    graduationDate.init(temp);

    
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


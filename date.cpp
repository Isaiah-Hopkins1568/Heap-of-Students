#include "date.h"
#include <iostream>
#include <sstream> 


Date::Date() : day(0), month(0), year(0) {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::~Date() {}


void Date::init(const std::string& dateString) {
    month = std::stoi(dateString.substr(0, 2)); 
    day = std::stoi(dateString.substr(3, 2));    
    year = std::stoi(dateString.substr(6, 4));   
}


void Date::printDate() const {
    std::cout << (month < 10 ? "0" : "") << month << "/"   
              << (day < 10 ? "0" : "") << day << "/"      
              << year << std::endl;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

std::string Date::toString() const {
    std::ostringstream ss;
    ss << (month < 10 ? "0" : "") << month << "/"  
       << (day < 10 ? "0" : "") << day << "/"       
       << year;
    return ss.str();
}


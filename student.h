#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "address.h"
#include "date.h"
#include <iostream>

class Student {
    private:
        std::string firstName;
        std::string lastName;
        Address address;
        Date birthDate;
        Date graduationDate;
        int score;

    public:
        Student();
        ~Student();

        void init(const std::string& studentString);
        void printStudent() const;
        std::string getLastFirst() const;
};

#endif


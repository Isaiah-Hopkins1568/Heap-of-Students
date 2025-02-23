#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date {
    private:
        int day;
        int month;
        int year;

    public:
        Date(); 
        Date(int day, int month, int year);
        ~Date(); // Destructor
        void init(const std::string& dateString);
        void printDate() const;
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        std::string toString() const;
};

#endif

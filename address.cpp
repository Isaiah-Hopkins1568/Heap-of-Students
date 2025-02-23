#include "address.h"
#include <iostream>


Address::Address() : street(""), city(""), state(""), zip("") {}

void Address::init(const std::string& street, const std::string& city, const std::string& state, const std::string& zip) {
    this->street = street;
    this->city = city;
    this->state = state;
    this->zip = zip;
}

void Address::printAddress() const {
    std::cout << street << ", " << city << ", " << state << " " << zip << std::endl;
}


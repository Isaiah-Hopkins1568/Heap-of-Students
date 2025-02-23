#ifndef ADDRESS_A_EXISTS
#define ADDRESS_A_EXISTS

#include <string>

class Address {
    private:
        std::string street;
        std::string city;
        std::string state;
        std::string zip;

    public:
        Address(); 
        void init(const std::string& street, const std::string& city, const std::string& state, const std::string& zip); // Renamed to init
        void printAddress() const;
};

#endif



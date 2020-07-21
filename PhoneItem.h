#include <string>; 

class PhoneItem{
    public:
    std::string phoneName;
    long phoneNumber;

    PhoneItem* left;
    PhoneItem* right;

    bool operator<(PhoneItem compare);
    bool operator>(PhoneItem compare);
    bool operator=(PhoneItem compare);
    bool operator<=(PhoneItem compare);
    bool operator>=(PhoneItem compare);

    PhoneItem();
};

PhoneItem* leaf(std::string name, long number);
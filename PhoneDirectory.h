#include "PhoneItem.h";
#include <string>;

class PhoneDirectory{
    public:
        PhoneItem* root;

        PhoneDirectory();

        void print();
        void printHelper(PhoneItem* currentPhone);

        void insert(std::string name, long number);
        void insertHelper(std::string name, long number, PhoneItem* currentPhone);

        void del(std::string name);
        void delHelper(std::string name, PhoneItem* node);

        long search(std::string name);
        long searchHelper(std::string name, PhoneItem* currentPhone);

        PhoneItem* twoChild(int lr, std::string name, PhoneItem* root);


};
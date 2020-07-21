#include "PhoneItem.h"

//PhoneItem constructor
PhoneItem::PhoneItem(){
    phoneName = "Operator";
    phoneNumber = 0;

    left = NULL;
    right = NULL;
}

//creates a new pointer to a leaf PhoneItem with NULL subtrees
PhoneItem* leaf(std::string name, long number){
    PhoneItem* n = new PhoneItem;
    n -> phoneName = name;
    n -> phoneNumber = number;

    n -> left = NULL;
    n -> right = NULL;

    return n;
}


//overloading comparison operators for functionality with PhoneItem objects
bool PhoneItem::operator<(PhoneItem compare){
  return(this-> phoneName < compare.phoneName);
}

bool PhoneItem::operator>(PhoneItem compare){
  return(this->phoneName > compare.phoneName);
}

bool PhoneItem::operator=(PhoneItem compare){
  return(this->phoneName == compare.phoneName);
}
bool PhoneItem::operator<=(PhoneItem compare){
  return(this->phoneName <= compare.phoneName);
}
bool PhoneItem::operator>=(PhoneItem compare){
  return(this->phoneName >= compare.phoneName);
}
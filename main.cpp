/*
  Wulfgang Rankenburg
  9/24/2019, 12:10P.M.
  Last Edited: 9/25/19, 10:11 p.m.
  CS355
  Creates a PhoneDirectory of PhoneItem objects, which store the name of the owner of the PhoneItem as well as the number of the PhoneItem. The structure of the PhoneDirectory is based off of a Binary Search Tree, meaning that each PhoneItem has no children, 1 child, or 2 children that branch off from it as the root node. BST should be balanced from left side over, and PhoneItems with no children are considered leaves, and the pointers to its children should be NULL
*/

#include <iostream>
#include "Directory.h"
using namespace std;

int main() {
  std::cout << "Hello World!\n";

  PhoneItem* p1 = leaf("Operator", 5768);
  cout << "PhoneItem created\n";
  PhoneItem* p2 = leaf("Tanner", 8472927810);
  cout << "Leaf created\n";
  PhoneItem* p3 = leaf("Swift", 7730960550);
  PhoneItem* p4 = leaf("Rylee", 2179947832);
  PhoneItem* p5 = leaf("Haley", 2173349217);
  PhoneItem* p6 = leaf("Axel", 4328997389);



  PhoneDirectory YP = PhoneDirectory();
  cout << "Directory created\n";
  YP.insert(p1->phoneName, p1->phoneNumber);
  YP.insert(p5->phoneName, p5->phoneNumber);
  YP.insert(p3->phoneName, p3->phoneNumber);
  YP.insert(p2->phoneName, p2->phoneNumber);
  YP.insert(p4->phoneName, p4->phoneNumber);
  YP.insert(p6->phoneName, p6->phoneNumber);
  YP.print();
  cout << "Starting directory search\n";
  cout << YP.search("Haley"); 
  cout << YP.search("Swift");
  YP.del("Rylee");
  YP.print(); //something happens with delete that messes up structure, but delete does work
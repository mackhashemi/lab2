#include <iostream>

#define _DEBUG  // to enable debug code in class
#include "LinkedList.h"

using namespace std;

int main(void)
{

  LinkedList<int>* list = new LinkedList<int>();

  cout << "At the beginning length should be 0.  Actual value: " << list->getLength() << endl;

  cout << "Inserting a few nodes at different locations" << endl;

  // insert nodes at beginning, middle and end.  print list at each step to validate
  list->insert(1, 4);
  list->print();

  list->insert(1, 5);
  list->print();

  list->insert(2, 6);
  list->print();

  list->insert(3, 7);
  list->print();

  list->insert(5, 8);
  list->print();

  cout << "Now length should be 5.  Actual value: " << list->getLength() << endl << endl;

  list->setEntry(3, 9);
  list->print();

  cout << "Entry at position 3 should be 9 - actual value is " << list->getEntry(3) << endl << endl;

  // remove nodes at beginning, middle and end.  print list at each step to validate
  list->remove(3);
  list->print();

  list->remove(4);
  list->print();

  list->remove(1);
  list->print();

  cout << "Now length should be 2.  Actual value: " << list->getLength() << endl << endl;

  list->clear();
  list->print();

  cout << "Now length should be 0.  Actual value: " << list->getLength() << endl << endl;

  return 0;
}

/** @file LinkedList.h */
#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"

template <class ItemType>

class LinkedList : public ListInterface <ItemType>
{
private:
    Node<ItemType>* headPtr;
    int count;

    Node<ItemType>* getNodeAt(int position) const;

public:

    LinkedList(); // Default constructor
    LinkedList(const LinkedList<ItemType>& list);
    virtual ~LinkedList(); // Destructor

    // Linked List Operations
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const;
    void setEntry(int position, const ItemType& newEntry);

}; // end LinkedList

#include "LinkedList.cpp"
#endif // _LINKED_LIST

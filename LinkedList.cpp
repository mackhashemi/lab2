/** @file LinkedList.cpp */

#include "LinkedList.h"


template<class ItemType> Node<ItemType>*
LinkedList<ItemType>::getNodeAt(int position) const
{
  // TODO: handle cases where position is out of range

  Node<ItemType>* curr = head;
  for (int skip = 1; skip < position; skip++)
    {
      curr = curr->getNext();
    }

  return curr;
}

template <class ItemType> LinkedList <ItemType>::LinkedList() :
  head(nullptr), count(0)
{
}


template <class ItemType> LinkedList <ItemType>::LinkedList(const LinkedList<ItemType>& list)
{
}


template <class ItemType> LinkedList <ItemType>::~LinkedList()
{
}


template <class ItemType> bool LinkedList <ItemType>::isEmpty() const
{
  return (count == 0);
}


template <class ItemType> int LinkedList <ItemType>::getLength() const
{
  return count;
}


template <class ItemType> bool LinkedList <ItemType>::insert(int newPosition, const ItemType& newEntry)
{

  return false;
}


template <class ItemType> bool LinkedList <ItemType>::remove(int position)
{
  return false;
}

template <class ItemType> void LinkedList <ItemType>::clear()
{
  return;
}


template <class ItemType> ItemType LinkedList <ItemType>::getEntry(int position)  const
{
  // TODO: handle cases where position is out of bounds
  Node<ItemType>* nodePtr = getNodeAt(position);
  return nodePtr->getItem();
}


template <class ItemType> void LinkedList <ItemType>::setEntry(int position, const ItemType & newEntry) {

  return;
}

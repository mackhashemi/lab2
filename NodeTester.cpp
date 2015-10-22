#include <iostream>

#include "Node.h"

using namespace std;

int main(void)
{
  // create 3 nodes
  Node<int>* nodePtr1 = new Node<int>();
  Node<int>* nodePtr2 = new Node<int>();
  Node<int>* nodePtr3 = new Node<int>();

  // set three nodes to 1, 2, 3
  nodePtr1->setItem(1);
  nodePtr2->setItem(2);
  nodePtr3->setItem(3);

  // linked them as node1 <--> node2 <--> node3
  nodePtr1->setNext(nodePtr2);
  nodePtr2->setPrev(nodePtr1);

  nodePtr2->setNext(nodePtr3);
  nodePtr3->setPrev(nodePtr2);

  // handle edges
  nodePtr1->setPrev(nullptr);
  nodePtr3->setNext(nullptr);

  // see if the chain is what we expect going forward
  cout << "Forward: Node1 value is: " << nodePtr1->getItem() << endl;
  cout << "Next node value is: " << (nodePtr1->getNext())->getItem() << endl;;
  cout << "Next node value is: " << ((nodePtr1->getNext())->getNext())->getItem() << endl;;

  // see if the chain is what we expect going backwards
  cout << "Forward: Node3 value is: " << nodePtr3->getItem() << endl;
  cout << "Prev node value is: " << (nodePtr3->getPrev())->getItem() << endl;;
  cout << "Prev node value is: " << ((nodePtr3->getPrev())->getPrev())->getItem() << endl;;

  // confirm edge pointers are null
  cout << "Node1 prev ptr is: " << nodePtr1->getPrev() << endl;
  cout << "Node3 next ptr is: " << nodePtr3->getNext() << endl;

  // test constructor
  Node<int>* nodePtr4 = new Node<int>(4);
  cout << "Node 4 value is: " << nodePtr4->getItem() << endl;

  return 0;
}

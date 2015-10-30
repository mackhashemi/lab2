#include <iostream>

#include "Stack.h"

using namespace std;

int main(void)
{

  int i;

  Stack<int> stack;

  cout << "Stack empty? : " << stack.isEmpty() << endl;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  i = stack.peek();
  cout << "peek 1 is " << i << endl;
  stack.pop();

  i = stack.peek();
  cout << "peek 2 is " << i << endl;
  stack.pop();

  i = stack.peek();
  cout << "peek 3 is " << i << endl;
  stack.pop();

  return 0;
}

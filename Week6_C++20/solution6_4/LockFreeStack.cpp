#include "LockFreeStack.h"
#include <iostream>

using namespace std;
using namespace mpcs51044;

int main()
{
  Stack* ls = new Stack();
  ls->push(3);
  ls->push(5);
  ls->push(6);
  //ls.push(3);
  cout<<ls->pop()<<endl;
  cout<<ls->pop()<<endl;
  cout<<ls->pop()<<endl;
  return 0;
}
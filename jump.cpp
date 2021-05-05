#include "jump.h"
  void Jump::run(){
    glTranslatef(0,value,0);
  }
  Jump::Jump(){
  
  }
std::istream& operator>>(std::istream& in, Jump& jmp)
{
  in >> jmp.value;
  return in;
}
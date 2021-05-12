#include "jump.h"
  void Jump::run(){
    glTranslatef(Command::value,0,0);
  }
  Jump::Jump(){
  
  }
std::istream& operator>>(std::istream& in, Jump& jmp)
{
  in >> jmp.value;
  return in;
}
#include "left.h"
  void Left::run(){
	  glRotatef(value, 0,0,1);
  }
  Left::Left(){
  
  }
std::istream& operator>>(std::istream& in, Left& lft)
{
  in >> lft.value;
  return in;
}


#include "right.h"
void Right::run(){
	glRotatef(0-(value), 0,0,1);
}
Right::Right(){
  
}
std::istream& operator>>(std::istream& in, Right& rit)
{
  in >> rit.value;
  return in;
}

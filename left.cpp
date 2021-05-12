#include "left.h"
  void Left::run(){
	  glRotatef(value, 0,0,1);
  }
  Left::Left(){
  
  }
std::istream& operator>>(std::istream& in, Left& lft)
{
    std::string input;
    in >> input;
    
    if(std::isdigit(input[0]))
    {
        lft.value = std::stof(input);
    }
    else
    {
        std::cerr << "Invalid Value for Left" << std::endl;
        exit(0);
    }

    return in;
}


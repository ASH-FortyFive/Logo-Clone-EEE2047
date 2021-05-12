#include "jump.h"
  void Jump::run(){
    glTranslatef(Command::value,0,0);
  }
  Jump::Jump(){
  
  }
std::istream& operator>>(std::istream& in, Jump& jmp)
{
    std::string input;
    in >> input;
    
    if(std::isdigit(input[0]))
    {
        jmp.value = std::stof(input);
    }
    else
    {
        std::cerr << "Invalid Value for Jump" << std::endl;
        exit(0);
    }

    return in;
}
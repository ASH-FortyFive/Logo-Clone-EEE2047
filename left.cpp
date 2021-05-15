#include "left.h"
  void Left::run(){
	  glRotatef(value, 0,0,1);
  }
  Left::Left(){
  
  }
std::istream& operator>>(std::istream& in, Left& lft)
{
    std::string input;
    in >> input >> std::ws;

    try
    {
        lft.value = std::stof(input);
    }
    catch(std::invalid_argument)
    {
        std::cerr << "Invalid Value for Left (Invalid Arg): " << input << std::endl;
        exit(0);
    }
    catch(std::out_of_range)
    {
        std::cerr << "Invalid Value for Left (Out of Range): " << input << std::endl;
        exit(0);
    }

    //! Slighly strange method of ensuring our Error Checking code doesn't destroy the ] sign
    if(input[input.length() - 1] == ']')
    {   
        in.putback(']');
    }
    
    return in;
}


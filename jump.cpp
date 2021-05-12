#include "jump.h"
  void Jump::run(){
    glTranslatef(Command::value,0,0);
  }
  Jump::Jump(){
  
  }
std::istream& operator>>(std::istream& in, Jump& jmp)
{
    std::string input;
    in >> input >> std::ws;

    try
    {
        jmp.value = std::stof(input);
    }
    catch(std::invalid_argument)
    {
        std::cerr << "Invalid Value for Jump (Invalid Arg): " << input << std::endl;
        exit(0);
    }
    catch(std::out_of_range)
    {
        std::cerr << "Invalid Value for Jump (Out of Range): " << input << std::endl;
        exit(0);
    }

    //! Slighly strange method of ensuring our Error Checking code doesn't destroy the ] sign
    if(input[input.length() - 1] == ']')
    {   
        in.putback(' ');
        in.putback(']');
    }

    return in;
}
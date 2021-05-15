#include "right.h"
void Right::run(){
	glRotatef(0-(value), 0,0,1);
}
Right::Right(){
  
}
std::istream& operator>>(std::istream& in, Right& rit)
{
    std::string input;
    in >> input >> std::ws;

    try
    {
        rit.value = std::stof(input);
    }
    catch(std::invalid_argument)
    {
        std::cerr << "Invalid Value for Right (Invalid Arg): " << input << std::endl;
        exit(0);
    }
    catch(std::out_of_range)
    {
        std::cerr << "Invalid Value for Right (Out of Range): " << input << std::endl;
        exit(0);
    }

    //! Slighly strange method of ensuring our Error Checking code doesn't destroy the ] sign
    if(input[input.length() - 1] == ']')
    {   
        in.putback(']');
    }
    
    return in;
}

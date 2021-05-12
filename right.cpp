#include "right.h"
void Right::run(){
	glRotatef(0-(value), 0,0,1);
}
Right::Right(){
  
}
std::istream& operator>>(std::istream& in, Right& rit)
{
    std::string input;
    in >> input;
    
    if(std::isdigit(input[0]))
    {
        rit.value = std::stof(input);
    }
    else
    {
        std::cerr << "Invalid Value for Right" << std::endl;
        exit(0);
    }

    return in;
}

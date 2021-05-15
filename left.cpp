#include "left.h"

void Left::run()
{
    glRotatef(value, 0,0,1);
}
  
Left::Left(){}

std::istream& operator>>(std::istream& in, Left& lft)
{
    int peek = in.peek();
    if((peek >= 48 && peek <= 57) || //Ensure next value is a number
        char(peek) == '-'         || //or a negative symbol
        char(peek) == '.')           //or a decimal
    {
        in >> lft.value >> std::ws;
        return in;
    }
    else
    {
        std::string error;
        in >> error;
        std::cerr << "Invalid Input for Left: " << error << std::endl;
        exit(0);
    }
}


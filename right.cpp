#include "right.h"

void Right::run()
{
	glRotatef(0-(value), 0,0,1);
}

Right::Right(){}

std::istream& operator>>(std::istream& in, Right& rit)
{
    int peek = in.peek();
    if((peek >= 48 && peek <= 57) || //Ensure next value is a number
        char(peek) == '-'         || //or a negative symbol
        char(peek) == '.')           //or a decimal
    {
        in >> rit.value >> std::ws;
        return in;
    }
    else
    {
        std::string error;
        in >> error;
        std::cerr << "Invalid Input for Right: " << error << std::endl;
        exit(0);
    }
}

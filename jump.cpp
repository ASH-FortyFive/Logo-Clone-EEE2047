#include "jump.h"

void Jump::run()
{
    glTranslatef(Command::value,0,0);
}

Jump::Jump(){}

std::istream& operator>>(std::istream& in, Jump& jmp)
{
    int peek = in.peek();
    if((peek >= 48 && peek <= 57) || //Ensure next value is a number
        char(peek) == '-'         || //or a negative symbol
        char(peek) == '.')           //or a decimal
    {
        in >> jmp.value >> std::ws;
        return in;
    }
    else
    {
        std::string error;
        in >> error;
        std::cerr << "Invalid Input for Jump: " << error << std::endl;
        exit(0);
    }
}
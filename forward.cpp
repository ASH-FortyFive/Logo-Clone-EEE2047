#include "forward.h"

void Forward::run() 
{
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(Command::value, 0.0f, 0.0f);
    glEnd();
    glTranslatef(Command::value, 0, 0);
}

Forward::Forward() {}

std::istream& operator>>(std::istream& in, Forward& fwd)
{
    int peek = in.peek();
    if((peek >= 48 && peek <= 57) || //Ensure next value is a number
        char(peek) == '-'         || //or a negative symbol
        char(peek) == '.')           //or a decimal
    {
        in >> fwd.value >> std::ws;
        return in;
    }
    else
    {
        std::string error;
        in >> error;
        std::cerr << "Invalid Input for Forward: " << error << std::endl;
        exit(0);
    }
}

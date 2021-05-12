#include "forward.h"

void Forward::run() {
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(Command::value, 0.0f, 0.0f);
    glEnd();
    glTranslatef(Command::value, 0, 0);
}
Forward::Forward() {

}
std::istream& operator>>(std::istream& in, Forward& fwd)
{
    std::string input;
    in >> input;
    
    if(std::isdigit(input[0]))
    {
        fwd.value = std::stof(input);
    }
    else
    {
        std::cerr << "Invalid Value for Forward" << std::endl;
        exit(0);
    }

    return in;
}

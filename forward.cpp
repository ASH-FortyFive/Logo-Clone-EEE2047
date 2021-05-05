#include "forward.h"

void Forward::run() {

    std::cout << "Foward " << Command::value << std::endl; 

    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, Command::value, 0.0f);
    glEnd();
    glTranslatef(0,Command::value,0);
}
Forward::Forward() {

}
std::istream& operator>>(std::istream& in, Forward& fwd)
{
    in >> fwd.value;
    return in;
}

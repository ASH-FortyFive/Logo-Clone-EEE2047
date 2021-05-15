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
    in >> input >> std::ws;

    //std::cout << "In: "<< input << std::endl; 

    try
    {
        fwd.value = std::stof(input);
    }
    catch(std::invalid_argument)
    {
        std::cerr << "Invalid Value for Forward (Invalid Arg): " << input << std::endl;
        exit(0);
    }
    catch(std::out_of_range)
    {
        std::cerr << "Invalid Value for Forward (Out of Range): " << input << std::endl;
        exit(0);
    }

    //! Slighly strange method of ensuring our Error Checking code doesn't destroy the ] sign
    if(input[input.length() - 1] == ']')
    {   
        //in.putback(' ');
        in.putback(']');
    }

    return in;
}

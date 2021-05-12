#include "repeat.h"

//--------Teammember 2 to complete this section (class definition) ----------
void Repeat::run()
{
    for(int i(0); i < Command::value; i++)
    {
        prog.run();
    }
}

Repeat::Repeat() {}
        
std::istream& operator>>(std::istream& in, Repeat& rpt)
{
    std::string input;
    in >> input;
    
    if(std::isdigit(input[0]))
    {
        rpt.value = std::stof(input);
    }
    else
    {
        std::cerr << "Invalid Value for Repeat" << std::endl;
        exit(0);
    }

    in >> input;
    if(input == "[")
    {
        in >> rpt.prog;
    }
    else
    {
        std::cerr << "Invalid Repeat Format" << std::endl;
        exit(0);
    }

    return in;
}
//----------------------------------------------------------------------------

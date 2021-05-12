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
    in >> rpt.value;

    std::string check;
    in >> check;
    
    if(check == "[")
    {
        in >> rpt.prog;
    }
    else
    {
        std::cerr << "Invalid Repeat Format" << std::endl;
    }

    return in;
}
//----------------------------------------------------------------------------

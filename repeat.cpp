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
    int peek = in.peek();
    if(peek >= 48 && peek <= 57)  //Ensure next value is a number
    {
        in >> rpt.value >> std::ws;
    }
    else
    {
        std::string error;
        in >> error;
        std::cerr << "Invalid Input for Repeat: " << error << std::endl;
        exit(0);
    }

    //! Checking that we correctly open brackets next
    if(char(in.peek()) != '[')
    {
       
       std::cerr << "Invalid Repeat Format" << std::endl;
        exit(0);
    }

    in.get(); //! Removes the previously peaked '['

    in >> rpt.prog;

   // std::cerr << "Peek: " << char(in.peek())  << std::endl;
    
    return in;
}
//----------------------------------------------------------------------------

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
    
    in >> input >> std::ws;

    try
    {
        rpt.value = std::stof(input);
    }
    catch(std::invalid_argument)
    {
        std::cerr << "Invalid Value for Repeat (Invalid Arg): " << input << std::endl;
        exit(0);
    }
    catch(std::out_of_range)
    {
        std::cerr << "Invalid Value for Repeat (Out of Range): " << input << std::endl;
        exit(0);
    }

    //! Slighly strange method of ensuring our Error Checking doesn't ignore the '['
    if(input[input.length() - 1] == '[')
    {   
        // Default case
    }
    else if(char(in.peek()) == '[')
    {
       in.get(); //! Removes the previously peaked '['
       if(char(in.peek()) == ' ') //! Removes any white spaces after opening bracket
       {
            in.get();
       }
    }
    else
    {
        std::cerr << "Invalid Repeat Format" << std::endl;
        exit(0);
    }

    in >> rpt.prog;

   // std::cerr << "Peek: " << char(in.peek())  << std::endl;
    
    return in;
}
//----------------------------------------------------------------------------

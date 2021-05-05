#include "repeat.h"
#include "program.h"


void Program::run() {
	//--------Teammember 1 to replace this section----------
	for (Command * cmd: cmds)
	{
		cmd->run();
	}
	//-------------------------------------------------------
}


std::istream& operator>>(std::istream& in, Program& prog)
{	
	//--------Teammember 1 to complete this section----------
	std::string commandString;


	float temp;

	while(!in.eof())// || in.peek()  == ']')
	{
		in >> commandString;
		if(commandString == "FORWARD")
		{
			prog.cmds.push_back(new Forward);
		}
		else if(commandString == "JUMP")
		{
			prog.cmds.push_back(new Jump);
		}
		else if(commandString == "LEFT")
		{
			prog.cmds.push_back(new Left);
		}
		else if(commandString == "RIGHT")
		{
			prog.cmds.push_back(new Right);
		}
		else if(commandString == "REPEAT")
		{
			prog.cmds.push_back(new Forward);
		}
		else
		{
			std::cerr << "Oppsie whoppsie" << std::endl;
		}

		in >> temp;
		//std::cerr << *prog.cmds.front() << std::endl;
	}
	return in;
}

Program::~Program()
{
	
}


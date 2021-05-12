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

	

	while(!in.eof())// || in.peek()  == ']')
	{
		in >> commandString;
		if(commandString == "FORWARD")
		{
			Forward *fwd  = new Forward;
			in >> *fwd;
			prog.cmds.push_back(fwd);
		}
		else if(commandString == "JUMP")
		{
			Jump *jmp  = new Jump;
			in >> *jmp;
			prog.cmds.push_back(jmp);
		}
		else if(commandString == "LEFT")
		{
			Left *lft  = new Left;
			in >> *lft;
			prog.cmds.push_back(lft);
		}
		else if(commandString == "RIGHT")
		{
			Right *rit  = new Right;
			in >> *rit;
			prog.cmds.push_back(rit);
		}
		else if(commandString == "REPEAT")
		{
			float temp;
			in >> temp;
			//prog.cmds.push_back(new Forward);
		}
		else
		{
			std::cerr << "Oppsie whoppsie" << std::endl;
		}
	}
	return in;
}

Program::~Program()
{
	
}


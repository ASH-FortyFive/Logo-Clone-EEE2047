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

	while(!in.eof())
	{
		in >> commandString >> std::ws;
		//std::cerr << commandString << std::endl;
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
			Repeat *rpt  = new Repeat;
			std::cerr << "Reading Repeat Input" << std::endl;
			in >> *rpt;
			prog.cmds.push_back(rpt);
		}
		else if(commandString == "]")
		{
			return in;
		}
		else // For Debug only
		{
			std::cerr << "Invalid Input: " << commandString << std::endl;
			exit(0);
		}
	}
	return in;
}

Program::~Program()
{
	cmds.clear();
}


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

		if(char(in.peek()) == ']')
		{
			in.get(); //Removes the peek ']'
			in >> std::ws; //Removes empty space
			return in; 
		}

		in >> commandString >> std::ws;
		
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
			in >> *rpt;
			prog.cmds.push_back(rpt);
		}
		else
		{
			std::cerr << "Invalid Input: " << commandString << std::endl;
			exit(0);
		}
	}

	in >> std::ws;

	return in;
}

Program::~Program()
{
	cmds.clear();
}


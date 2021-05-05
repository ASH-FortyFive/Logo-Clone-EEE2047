#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

#include "left.h"
#include "right.h"
#include "forward.h"
#include "jump.h"

class Program {
	//--------Teammember 1 to complete this section (class declaration) ----------
private:
	std::vector<Command*> cmds;
public:
	void run();
	~Program();

	friend std::istream& operator>>(std::istream& in, Program& prog);
	//----------------------------------------------------------------------------

};





#endif /* PROGRAM_H_ */

#ifndef LEFT_H_
#define LEFT_H_
#include "command.h"
class Left:public Command{
	public:
		Left();
	  void run();
		friend std::istream& operator>>(std::istream& in, Left& lft);
};
#endif /* LEFT_H_ */
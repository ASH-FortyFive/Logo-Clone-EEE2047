#ifndef RIGHT_H_
#define RIGHT_H_
#include "command.h"
class Right:public Command{
	public:
		Right();
	  void run();
		friend std::istream& operator>>(std::istream& in, Right& rit); 
};
#endif /* RIGHT_H_ */
#ifndef ROBOT_CLASS_H_INCLUDED
#define ROBOT_CLASS_H_INCLUDED
#include <iostream>
#include <ostream>
#include "Grid_Format.h"
using namespace std;


class Robot
{
private:
	int xLocation;
	int yLocation;
	bool cargoBed;
	char load;

public:
	Robot(Grid_Format&, int lx, int ly, bool b, char l);
    Robot( int lx, int ly, bool b, char l);
    //void Show_Robot(Grid_Format&, int lxx, int lyy);

	void setX(int lx);
	void setY(int ly);
	int getX();
	int getY();

	void setCargo(bool b);
	bool getCargo();

	void setLoad(char l);
	char getLoad();

	bool moveTo(Grid_Format&, int lx, int ly);
	bool pickup(Grid_Format&, int lx, int ly);
	bool dropOff(Grid_Format&, int lx, int ly);



	friend ostream& operator<<(ostream& out, const Robot& r);

};



#endif // ROBOT_CLASS_H_INCLUDED

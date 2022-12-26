#include "Robot_Class.h"
#include "Grid_Format.h"


Robot::Robot(int lx, int ly, bool b, char l)
{
	xLocation = lx;
	yLocation = ly;
	cargoBed = b;
	load = l;

}


/*void Robot::Show_Robot(Grid_Format& Some_Grid, int lxx, int lyy)
{

    lxx = getX();
    lyy = getY();
    if(cargoBed == false)
    {
        char temp = 'R';
        Some_Grid.setGrid_Format(lxx, lyy, temp);
        load = temp;
    }


}*/



Robot::Robot(Grid_Format&, int lx, int ly, bool b, char l)
{
    xLocation = lx;
    yLocation = ly;
    cargoBed = b;
	load = l;
	Grid_Format Some_Grid;
    Some_Grid.setGrid_Format_Nochar(lx, ly);



}



void Robot::setX(int lx)
{
	xLocation = lx;
}

int Robot::getX()
{
	return xLocation;
}

void Robot::setY(int ly)
{
	yLocation = ly;
}

int Robot::getY()
{
	return yLocation;
}

void Robot::setCargo(bool b)
{
	cargoBed = b;

}
bool Robot::getCargo()
{
	return cargoBed;
}

void Robot::setLoad(char l)
{
	load = l;
}
char Robot::getLoad()
{
	return load;
}

// Move robot and checks if payload is in grid
bool Robot::moveTo(Grid_Format& Some_Grid, int lx, int ly)
{

	int locX = getX();
	int locY = getY();

	if (lx < 0 || lx > 10 || ly < 0 || ly > 10)
	{
		return false;
	}
	else {
		if (locX < lx)
		{
			for (int i = locX; i <= lx; i++) {
				setX(i);
			}
		}
		else if (locX > lx)
		{
			for (int i = locX; i >= lx; i--) {
				setX(i);
			}
		}
		if (locY < ly)
		{
			for (int i = locY; i <= ly; i++) {
				setY(i);
			}
		}
		if (locY > ly)
		{
			for (int i = locY; i >= ly; i--) {
				setY(i);
			}
		}
		Some_Grid.setGrid_Format_Nochar(lx, ly);

		return true;
	}
}


// Pickup payload
bool Robot::pickup(Grid_Format& Some_Grid, int lx, int ly)
{
	if (Some_Grid.getGrid_Format(lx, ly) == '.' || cargoBed == true)
	{
		return false;
	}
	else
	{
	    char temp;

		moveTo(Some_Grid,lx, ly);
        //Some_Grid.setGrid_Format_Nochar (lx, ly);
        temp = Some_Grid.getGrid_Format(lx, ly);
        load = temp;
		cargoBed = true;
		Some_Grid.setGrid_Format(lx, ly, '.');
		cout << "Payload is in cargo bed." << endl;
		return true;
	}



}

// Drop off payload
bool Robot::dropOff(Grid_Format& Some_Grid, int lx, int ly)
{
	if (Some_Grid.getGrid_Format(lx, ly) != '.' || cargoBed == false)
	{
		return false;
	}
	else
	{

		moveTo(Some_Grid, lx, ly);
		Some_Grid.setGrid_Format(lx, ly, this->load);
		cargoBed = false;
		cout << "Payload has been dropped off." << endl;
		return true;
	}

}

//Overloading << to print robot location and payload
ostream& operator<<(ostream& out, const Robot& r)
{
	out << "Robot is at location (" << r.xLocation << "," << r.yLocation << ")" << endl;

	if (r.cargoBed == true)
	{
		out << "The robot has the load " << r.load << endl;
	}
	else if (r.cargoBed == false)
	{
		out << "The robot does not have a load\n" << endl;
	}
	return out;
}

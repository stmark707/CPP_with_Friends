#include <iostream>
#include "Grid_Format.h"
#include "Robot_Class.h"

using namespace std;

void print2D(Grid_Format& Another_Grid)
{
    for (int row = 0; row < 10; row++)
    {
    for (int column = 0; column < 10; column++)
    {
        cout << Another_Grid.getGrid_Format(row, column) << " ";

    }
        cout << endl;
    }
    cout << endl << endl;
}

void clear(Grid_Format& Another_Grid)
{
    for (int row = 0; row < 10; row++)
    {
    for (int column = 0; column < 10; column++)
    {
    if (Another_Grid.getGrid_Format(row, column) != '.')
    {
        Robot* r = new Robot(Another_Grid, row, column, false, '.');
        r->pickup(Another_Grid, row, column);

        cout << "***Payload removed***" << endl;

        delete r;
    }

}

    }
    cout << "///Clearing grid///" << endl;
}

int main()
{

    Grid_Format Grid;
    Grid_Format();
    Grid.setGrid_Format(3, 8, 'B');
    Grid.setGrid_Format(2, 6, 'C');

    print2D(Grid);

    Robot R2D2(Grid, 1, 1, false, '*');
    Robot Walle(Grid, 0, 0, false, '*');
    cout << R2D2;
    cout << Walle;
    R2D2.moveTo(Grid, 9, 2);
    Walle.moveTo(Grid, 3, 4);

    print2D(Grid);
    cout << R2D2;
    cout << Walle;

    R2D2.pickup(Grid, 3, 8);
    cout << R2D2;
    R2D2.dropOff(Grid, 9, 9);
    print2D(Grid);
    cout << R2D2;

    Walle.pickup(Grid, 2, 6);
    cout << Walle;
    Walle.dropOff(Grid, 0, 0);
    print2D(Grid);
    cout << Walle;

    clear(Grid);
    print2D(Grid);






 return 0;
}


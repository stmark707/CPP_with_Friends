#include "Grid_Format.h"
#include <iostream> //implementation of the square array class functions

using namespace std;


Grid_Format::Grid_Format() //constructor no argument

{
    for (int row_count = 0; row_count < Allotted_Rows; row_count++)
    {
        for (int column_count= 0; column_count < Allotted_Columns; column_count++)
        {

        Square_Array[row_count][column_count] = '.';
        }
    }

//Square_Array[Allotted_Rows][Allotted_Columns] = {0};
}

Grid_Format::Grid_Format(int Row_Element, int Column_Element)

{
    Square_Array[Row_Element][Column_Element];
}

void Grid_Format::setGrid_Format(int row_element, int column_element, char User_Inputed_Value) //allow user to set the value

{

 if (row_element <= Allotted_Rows && column_element <= Allotted_Columns)
    {
        Square_Array[row_element][column_element] = User_Inputed_Value;
    }

}

void Grid_Format::setGrid_Format_Nochar(int row_element, int column_element)
{
    if (row_element <= Allotted_Rows && column_element <= Allotted_Columns)
    {
        Square_Array[row_element][column_element];
    }
}



char Grid_Format::getGrid_Format(int row_element, int column_element) //allow user to see a value

{
    return Square_Array[row_element][column_element];
}

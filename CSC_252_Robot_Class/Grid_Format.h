#ifndef GRID_FORMAT_H_INCLUDED
#define GRID_FORMAT_H_INCLUDED


class Grid_Format
{
public:

    Grid_Format(); //constructor no argument

    Grid_Format(int Row_Element, int Column_Element);

    void setGrid_Format(int row_element, int column_element, char User_Inputed_Value);
    void setGrid_Format_Nochar (int row_element, int column_element); //allow user to set the value

    char getGrid_Format(int row_element, int column_element); //allow user to see a value


private:

    static const int Allotted_Rows = 10;
    static const int Allotted_Columns = 10;

    char Square_Array[Allotted_Rows][Allotted_Columns]; //create our matrix/2 dimensional array



};






#endif // GRID_FORMAT_H_INCLUDED

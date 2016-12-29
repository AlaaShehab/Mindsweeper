
#ifndef VALID_OPERATION
#define VALID_OPERATION

///Put a question mark
void putQuestionMark(int row,int col,int num1, int num2, char userArray[row][col]);
///put a flag
void putFlag(int row,int col,int num1, int num2, char userArray[row][col]);
/// open a cell
void openCell(int row, int col,int num1, int num2, char userArray[row][col], char editorArray[row][col]);
///open an empty cell
void openEemptyCell(int row, int col,int num1,int num2,char editorArray[row][col], char userArray[row][col]);
///when the user opens a cell that contains a mine '*' they lose.
///opening cells around a number on pushing a
void openingOpenCell (int row, int col, int num1, int num2, char editorArray[row][col], char userArray[row][col]);


#endif

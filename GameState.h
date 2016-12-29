

#ifndef GAME_STATE
#define GAME_STATE

///when the user opens a cell that contains a mine '*' they lose.
void loseGame(int row, int col, int num1, int num2, char userArray[row][col], char editorArray[row][col]);
///Win a game
void winGame(int row, int col,char editorArray[row][col], char userArray[row][col]);


#endif



#ifndef ENTER_GAME
#define ENTER_GAME


void startGame();

void enterGame(int row,int col,char editorArray[row][col],char userArray[row][col],int load);

void loadGame(int load);

void saveGame(int row, int col, char editorArray[row][col],char userArray[row][col]);


#endif


#include"GameState.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"Global_Variables.h"

///when the user opens a cell that contains a mine '*' they lose.
void loseGame(int row, int col, int num1, int num2, char userArray[row][col], char editorArray[row][col]){
    int i,j;
    printf("            SORRY YOU LOSE :( \n\n");
    for (i=0;i<row;i++){ ///loop on all cells in the editor array.
        for (j=0;j<col;j++){

            if (i== num1 && j == num2){ ///the cell that made the user lose'mine cell' is changed to '!'
                userArray[num1][num2]= '!';
            }


            else if ((editorArray[i][j]>= '1' && editorArray[i][j]<= '8')|| (editorArray[i][j]== ' ')){
                if (userArray[i][j] == 'F'){ ///any number or empty cell that have a flag is considered a missed flag'_'
                    userArray[i][j]= '_';
                }
                else {
                    userArray[i][j] = editorArray[i][j]; ///If there's no flag on these cells then replace then directly(open cell)
                }
            }


            else if (editorArray[i][j]== '*'){ ///If there's a mine in the cell and it's placed a flag then replace it with '*'
                if (userArray[i][j] == 'F'){
                    userArray[i][j] = editorArray[i][j];
                }
                else {
                    userArray[i][j] = 'M'; ///If the mine is left with no flag 'missed mine' then replace cell with 'M'
                }
            }


        }
    }
    return;
}


///Win a game
void winGame(int row, int col,char editorArray[row][col], char userArray[row][col]){
    int i,j;
    printf("        CONGRATULATIONS YOU WON THE GAME");
///on winning open open all cells and replace those with mine with a Flag 'F
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            if (editorArray[i][j]=='*'){
                userArray[i][j]='F';
            }
        }
    }
    return;

}

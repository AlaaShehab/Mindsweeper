#include"ValidOperations.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"Global_Variables.h"

/// put a question mark
void putQuestionMark(int row,int col,int num1, int num2, char userArray[row][col]){

    if (userArray[num1][num2] == '?'){  ///If there's already a question mark then change it to X (closed cell)
        userArray[num1][num2] = 'X';
        user.questionMarkNumber--;

    }
    else {
        userArray[num1][num2] = '?';
        user.questionMarkNumber++;
    }
    return;
}
/// put a flag
void putFlag(int row,int col,int num1, int num2, char userArray[row][col]){

    if (userArray[num1][num2] == 'F'){ ///If there's already a cell marked with a flag then change it to X (closed cell)
        userArray[num1][num2] = 'X';
        user.FlagsNumber--;
    }
    else {
        userArray[num1][num2] = 'F';
        user.FlagsNumber++;
    }
}
/// open a cell
void openCell(int row, int col,int num1, int num2, char userArray[row][col], char editorArray[row][col]){

        if ((editorArray[num1][num2]>='1') && (editorArray[num1][num2]<='8')){ ///check if the cell is a number
            userArray[num1][num2] = editorArray[num1][num2];                   ///then replace it (i.e.open the cell)
        }
        else if (editorArray[num1][num2]=='*'){
            lose = 1;   ///if the cell chosen is a mine'*' then change lose value to 1 (i.e.User loses and a flag is used)
            return;
        }
        else if (editorArray[num1][num2]==' '){
        ///If it's an empty cell(i.e.have no number with in it then it will open all empty cells beside it till reaching a number it stops
            openEemptyCell(row,col,num1,num2,editorArray,userArray);
        }
    return;
}
///when the user opens a cell that contains a mine '*' they lose.
///opening cells around a number on pushing a
void openingOpenCell (int row, int col, int num1, int num2, char editorArray[row][col], char userArray[row][col]){

    int a, b, counter=0;
    ///count number of flags around the cell as a '3X3 grid'
    if (userArray[num1][num2] >='1' && userArray[num1][num2] <='8'){
        for (a=num1-1;a<num1+2;a++){
            for(b=num2-1;b<num2+2;b++){
                if (a>=0 && a<row && b>=0 && b<col){
                    if (userArray[a][b] == 'F'){
                        counter ++;
                    }
                }
            }
        }

        if (counter == userArray[num1][num2]-'0'){ ///check whether number of cell equals number of flags around it
///Open cells around it by looping around the number
            for (a=num1-1;a<num1+2;a++){
                for(b=num2-1;b<num2+2;b++){
                    if (a>=0 && a<row && b>=0 && b<col){
                        if (userArray[a][b] != 'F' && editorArray[a][b] != '*'){
                            userArray[a][b] = editorArray[a][b];
                        }
                        else if (editorArray[a][b]=='*' && userArray[a][b] != 'F'){
                            lose =1; ///if a flag is wrong then the user loses
                        return;
                        }
                    }
                }
            }
        }
    }
    return;
}
/// opening an empty cell.
void openEemptyCell(int row, int col,int num1,int num2,char editorArray[row][col], char userArray[row][col]){
    int a, b;
///when reaching an empty cell loop starting from 3X3 smaller grid with the cell chosen with in the middle
    if ( userArray[num1][num2] == 'X' && editorArray[num1][num2]==' '){
        userArray[num1][num2] = ' ';
        for (a=num1-1;a<num1+2;a++){
            for(b=num2-1;b<num2+2;b++){
                if (a<row && b<col && a>=0 && b>=0){
///As long as the cell is within range continue
                    openEemptyCell(row,col,a,b,editorArray,userArray);
                }
            }
        }
    }
    else {
            userArray[num1][num2]=editorArray[num1][num2];
    }
    return;
}

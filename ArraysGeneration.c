
#include"ArraysGeneration.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"Global_Variables.h"

///generating mines in editor's array
void mineGeneration(int rowNum, int colNum, char editorArray[rowNum][colNum],int rowNumberofMine[91],int colNumberOfMine[91],int num1,int num2){

    int i,j;
    int counter = 0;
    ///
    time_t t;
    srand((unsigned) time(&t));
    ///Add a number of mines according to an equation
    while(counter<minesNumber){

        i = rand() % rowNum;
        j = rand() % colNum;
///choose a random number between 0 and the number of rows of the gird
///check whether a mine has already been generated in this cell before or not
        if (editorArray[i][j]!= '*' && i != num1 && j!= num2){
            editorArray[i][j]= '*';
        rowNumberofMine[counter]=i;  ///arrays that keep both the vertical and horizontal representation of any mine in the grid
        colNumberOfMine[counter]=j;
        counter++;
        }

    }

   return;
}
///generating number in editor's array
void numberGeneration(int row, int col, int minesNumber,char editorArray[row][col],int rowNumberofMine[91],int colNumberOfMine[91]){

    int i, rowNum, colNum;
///looping a number of times equals to the number of mines in the grid
    for (i=0;i<minesNumber;i++){
///start with first mine (knowing the number of row and column of its cell) start looping within 3X3 grid around it
        for (rowNum=rowNumberofMine[i]-1;rowNum<rowNumberofMine[i]+2;rowNum++){
            for(colNum=colNumberOfMine[i]-1;colNum<colNumberOfMine[i]+2;colNum++){
///Make sure the number of cell is within the range of the grid
                if (((rowNum>=0 && rowNum<row) && (colNum>=0 && colNum<col)) && editorArray[rowNum][colNum]!='*'){
///filling the cells with numbers.
                        if (editorArray[rowNum][colNum]>= '1'){
                            editorArray[rowNum][colNum] += 1;
                        }
                        else {
                            editorArray[rowNum][colNum] = '1';
                        }
                }
            }
        }
    }
    return;
}
///generating user's array with 'X' as closed cells.
void generateUserArray(int row, int col, char userArray[row][col]){
    int i,j;
    for(i=0;i<row;i++){
        for (j=0;j<col;j++){
            userArray[i][j]='X';
        }
    }
    return;
}
///generating spaces in the array
void initialArrayGeneration(int row, int col, char editorArray[row][col]){
///initializing Editor array with free spaces 'i.e.empty cells'
    int i,j;
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            editorArray[i][j]=' ';
        }
    }
    return;
}

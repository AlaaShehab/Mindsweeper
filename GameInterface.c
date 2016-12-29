
#include"GameInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"Global_Variables.h"
///print user interface (number of moves,flags,'?',and time
void printInterface(int load){

    printf("Your Total moves is %d \n", user.movesNumber);
    printf("Number of Flags used %d \n", user.FlagsNumber);
    printf("Number of Question Marks used %d \n", user.questionMarkNumber);
    user.timePassed = (currentTime-startTime) + user.loadTime;
    printf("Time passed %d seconds \n",user.timePassed);
    printf("\n");

}
///printing user's array -edited-
void printUserArray(int row, int col, char userArray[row][col]){
    int i,j;
    int counter=0;
    system("cls");
    printf("    Mine Sweeper ^_^\n\n");

    for (i=-1;i<col;i++){    ///printing numbers of columns of the user array

        if (i==-1){
                printf("     "); /// print a space at the beginning of the row (numbers of rows space)
            }
            else{
                printf("%d  ",i);
            }
    }
    printf("\n\n\n");

    for (i=0;i<row;i++){
        printf("%d",counter);///print the row number at the beginning of the row.
        if (counter<10){
            printf("    ");
        }
        else {
            printf("   "); /// add spaces according to the row number to manage grid display
        }
        counter++;
        for (j=0;j<col;j++){
            if (j<9){
                printf("%c  ",userArray[i][j]); /// print user array
            }
            else {
                printf("%c   ",userArray[i][j]); /// add spaces after each cell according to the column number to manage grid display
            }

        }
        printf("\n");
        printf("\n");
    }
    printf("\n");
    return;
}

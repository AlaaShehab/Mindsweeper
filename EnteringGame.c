#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"EnteringGame.h"
#include"Global_Variables.h"

//int initialize = 1;
void startGame(){
    char entergame;
    int load = 0;
///check whether the user is loading or starting a new game
    printf("Press N to start a new game or L to load game : \n");
    scanEnterGame(&entergame);
    printf("\n");

///change input to lowercase
    changeToLowercase(&entergame);
///start time of the game
    time(&startTime);



    if (entergame == 'l'){
///change some flags for entering and loading game
        load = 1;
        initialize = 1;
        loadGame(load);
        return;
    }
    else if (entergame !='n'){
        printf("Invalid Input, A new game will start\n\n");
    }

///enter grid size
    int row,col;
    scanGridSize(&row,&col);

    char userArray[row][col];
    char editorArray[row][col];
///generate user array with X (Closed cells)
    generateUserArray(row,col,userArray);
///generate number of mines and enter game.
    minesNumber = 1+(row*col)/10;
    enterGame(row,col,editorArray,userArray,load);


}
///enter game and play
void enterGame(int row,int col,char editorArray[row][col],char userArray[row][col],int load){

    int i,j,closedCellNumber=0;
    int num1, num2;
    char operation;
    int rowNumberofMine[91];
    int colNumberOfMine[91];

    printUserArray(row,col,userArray);

    printf("NOTE : the cell number must consist of 2 numbers (Number of row and column) separated by space\nThen enter the operation required\n");
    printf("To open a cell enter 'O'\nTo put or remove a FLAG enter 'F'\nTo put or remove a question mark enter'?'\nTo open all cells around a specific cell enter 'A'\n\n");

    printf("If you want to save game press 0 0 s \n");


///continue game as long as number of flags,question marks and closed cells are less than number of mines
    while ((user.FlagsNumber+user.questionMarkNumber+closedCellNumber) != minesNumber){

        closedCellNumber=0;

        scanInput(&num1, &num2, &operation, row,col);

        time(&currentTime);
///check if the user wants to save the game
        if (operation=='s'&& num1==0 && num2==0){
            saveGame(row,col,editorArray,userArray);
            return;
        }
///generate the editor array and save it
        if ((initialize==0 )|| (load == 1 && user.movesNumber == 0)){
            initialArrayGeneration(row,col,editorArray);
            mineGeneration(row,col,editorArray,rowNumberofMine,colNumberOfMine,num1,num2);
            numberGeneration(row,col,minesNumber,editorArray,rowNumberofMine,colNumberOfMine);
            saveGame(row,col,editorArray,userArray);

        }
///input operation 'O' to open a cell, 'F' to put or remove a flag, '?' to add or remove a question mark
///'a' to open all cells around a specific one

        switch(operation){

        case 'o': openCell(row,col,num1,num2,userArray,editorArray); user.movesNumber++; break;

        case 'f': putFlag(row,col,num1,num2,userArray); user.movesNumber++; break;

        case '?': putQuestionMark(row,col,num1,num2,userArray); user.movesNumber++; break;

        case 'a': openingOpenCell (row,col,num1,num2,editorArray,userArray); user.movesNumber++; break;

        }

        printUserArray(row,col,userArray);
        printInterface(load);

        initialize=1;
///if the flag changes'lose' then the user loses
        if (lose == 1){
            loseGame(row,col,num1,num2,userArray,editorArray);
            printUserArray(row,col,userArray);
            printInterface(load);
            return;
        }
///check number of cells that are still closed
        for (i=0;i<col;i++){
            for(j=0;j<col;j++){
                if (userArray[i][j]== 'X'){
                    closedCellNumber++;
                }
            }
        }
///check if the user wins.
        if ((user.FlagsNumber+user.questionMarkNumber+closedCellNumber) == minesNumber){
            winGame(row,col,editorArray,userArray);
            printUserArray(row,col,userArray);
            printInterface(load);
    }
    }

    return;
}

void saveGame(int row, int col, char editorArray[row][col],char userArray[row][col]){
    int i,j;
///save editor array to a file cell by cell
    FILE *fsave;
    fsave= fopen("Saving Editor Array.txt","w+");
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            fprintf(fsave,"%c ",editorArray[i][j]);
        }
        fprintf(fsave,"\n");
    }
    fclose(fsave);

    fsave= fopen("Saving User Array.txt","w+");
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            fprintf(fsave,"%c ",userArray[i][j]);
        }
        fprintf(fsave,"\n");
    }
        fclose(fsave);
///Save user interface
    fsave= fopen("Saving User Interface.txt","w+");

    fprintf(fsave,"%d %d %d %d ",user.movesNumber,user.FlagsNumber,user.questionMarkNumber,user.timePassed);
    fprintf(fsave,"%d %d ",row,col);

        fclose(fsave);

}
///load a game
void loadGame(int load){

    int row,col,i=0,j=0;

    FILE *fload;
    fload = fopen("Saving User Interface.txt","r+");

    char tempStr[256];
///put whatever in the file in a temporary array of strings
    while( !feof(fload)){
        (fgets(tempStr,256,fload));
    }
    char *ptempStr;
///cut array of strings into small strings separated by spaces
    for (ptempStr = strtok(tempStr," "); ptempStr; ptempStr = strtok(NULL, " "))
    {
        if (i==0){
        user.movesNumber = atoi(ptempStr); /// first string represents user moves and transfer string to an integer and so on
        }
        else if (i==1){
        user.FlagsNumber = atoi(ptempStr);
        }
        else if (i==2){
        user.questionMarkNumber = atoi(ptempStr);
        }
        else if (i==3){
        user.loadTime = atoi(ptempStr);
        }
        else if (i==4){
        row = atoi(ptempStr);
        }
        else if (i==5){
        col = atoi(ptempStr);
        }
        i++;

    }

    fclose(fload);

    char editorArray[row][col];

    fload = fopen("Saving Editor Array.txt","r+");
///get editor array from file
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            char s[]="0";
            fscanf(fload, "%c", &s[0]);
///scan first element in the array and save it to editor array
            editorArray[i][j] = s[0];
            fscanf(fload, "%c", &s[0]);
///second element is space so scan it and don't save it
        }
        char s[]="0";
///after finishing the row an element must be ignored which is a '\n' new line
        fscanf(fload, "%c", &s[0]);
    }


    char userArray[row][col];

    fclose(fload);
    fload = fopen("Saving User Array.txt","r+");

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            char s[]="0";
            fscanf(fload, "%c", &s[0]);
            userArray[i][j] = s[0];
            fscanf(fload, "%c", &s[0]);
        }
        char s[]="0";
        fscanf(fload, "%c", &s[0]);
    }

    minesNumber = 1+(row*col)/10;

    enterGame(row,col,editorArray,userArray,load);
}


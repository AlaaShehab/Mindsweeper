
#include"InputPreparation.h"
#include <stdio.h>
#include <stdlib.h>
#include"Global_Variables.h"
///change operation input to lowercase in order to match switch condition.
void changeToLowercase(char *operation){
    if (*operation>='A' && *operation<='Z'){
        *operation = *operation-'A'+'a';
    }
    return;
}

///change name input to lowercase in order to compare during ranking.
void changeToLower(char strName[],int length){
    int i=0;
    for (i=0;i<length;i++){
        if(strName[i]>='A' && strName[i]<='Z'){
           strName[i] = strName[i]-'A'+'a';
        }
    }
    return;
}
///Scan input (load game/new game)
void scanEnterGame(char *entergame){

    char letter;
    int i=0;
///get input from user in a string as long as they enter to avoid crash or saving in places not allocated for it
    while ((letter=getchar()) != '\n'){
        if (i<1){
            *entergame= letter;
        }
        i++;
    }


}

void scanGridSize(int *row, int *col){

    char input;
    char tempStr[20];
    char *pTempStr;
    int i=0;

    printf("Enter size of Grid : \n");
    printf("NOTE : Make sure the size of the grid is minimum 2 and maximum 30\nEnter a space after each number and when you finish press ENTER\n\n");
///enter grid size and save it in a temporary array
    while ((input=getchar()) != '\n'){
        if (i<20){
            tempStr[i++]= input;
        }
    }
    i =0;
///cut array till spaces and save first as number of rows, second as number of columns
    for (pTempStr = strtok(tempStr," "); pTempStr; pTempStr = strtok(NULL, " ")){
        if (i==0){
            *row = atoi(pTempStr);
        }
        else if (i==1){
            *col = atoi(pTempStr);
        }
        i++;
    }
///check the grid boundaries
    if(*row<2 || *row>30 || *col<2 || *col>30){
       scanGridSize(&*row, &*col);
    }
    else {
        return;
    }

    }

void scanInput(int *num1, int *num2, char *operation,int row,int col){

    char tempStr[100];
    char str[20];
    char *pTempStr;
    int i=0;
    char input;
    printf("\n\n");
    printf("Enter Cell and operation: \n\n");

///input cell number and operation in an array with spaces separation
    while((input=getchar())!= '\n'){
        if (i<100)
        tempStr[i++]=input;
    }
    i=0;
///divide string into a smaller ones, each separated by spaces
    for (pTempStr = strtok(tempStr," ");pTempStr; pTempStr = strtok(NULL, " ")){
        if(i==0){
            *num1 = atoi(pTempStr);
        }
        if (i==1){
            *num2 = atoi(pTempStr);
        }
        if (i==2){
            *operation = pTempStr[0];
        }
        i++;
    }
///change input operator to lowercase
    changeToLowercase(&*operation);
///check validity of input
    if ((*operation != 'o' && *operation != 'f'&& *operation != 'a' && *operation != 'u' && *operation != '?' && *operation != 's')||(*num1 <0 || *num1>row)||(*num2<0 || *num2>col)){
        scanInput(&*num1, &*num2, &*operation, row, col);
    }
    else{
        return;
    }


}


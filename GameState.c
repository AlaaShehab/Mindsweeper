
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

        char action;
    scanNewAction(&action);

    if (action == '0'){
        return;
    }
    else{
        startGame();
    }

    return;
}

///Win a game
void winGame(int row, int col,char editorArray[row][col], char userArray[row][col]){
    int i,j;
///on winning open open all cells and replace those with mine with a Flag 'F
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            if (editorArray[i][j]=='*'){
                userArray[i][j]='F';
            }
        }
    }
    printUserArray(row,col,userArray);
    printf("        CONGRATULATIONS YOU WON THE GAME\n\n");
    Ranking(row, col);

    char action;
    scanNewAction(&action);

    if (action == '0'){
        return;
    }
    else{
        startGame();
    }

    return;

}

void Ranking (int row, int col){
 char data[900], userName[900];
    char scoreChar[900];
    int counter=0, flag = 0;
    FILE *frank;
    int i=0,j=0,m=0;
    frank = fopen("user Name.txt","r");
    // here we count number of lines in the file to make an array with the same size
    while (fgets(data,900,frank)){
        counter++;
    }
    fclose(frank);
    struct userData userDataArray[counter+1];

    frank = fopen("user Name.txt","r");
    // reading the name and score ,separate them and putting them in the array of structures
    while (fgets(data,900,frank)){
        i=0;
        j=0;
        while (data[i] != ','){
            userDataArray[m].name[i]=data[i];
            i++;
        }
        userDataArray[m].name[i]='\0';
        i++;
        while (data[i] != '\n'){
            scoreChar[j]=data[i];
            j++;
            i++;
        }
        scoreChar[j]='\0';
        userDataArray[m].score = atoi(scoreChar);
        m++;
    }
    fclose(frank);

    int userScore = (pow(row,4)*pow(col,4))/((currentTime-startTime)*user.movesNumber);
    printf("Your score is %d\n",userScore);
    scanUserName(userName,900);
    printf("%s",userName);
   // scanf("%s",userName);
    //comparing the user name with the saved names and see if it is the first time for him to play or not
    for(i=0;i<counter;i++){
       if(strcmp(userName,userDataArray[i].name) == 0) {
            flag = 1;
            userDataArray[i].score += userScore;

       }
    }
    if (flag == 0){
        strcpy(userDataArray[counter].name ,userName);
        userDataArray[counter].score = userScore;
        counter= counter+1;
    }
    frank = fopen ("user Name.txt","w");

    int minIndex;
    struct userData  temp;
    //sorting the users by their scores
    printf("\n\n");
    printf("     Leader Board\n\n");
    printf("   Name       Score\n");
    for (i=0;i<counter;i++){
        minIndex = i;
        for  (j=i+1;j<counter;j++){
            if (userDataArray[j].score > userDataArray[minIndex].score){
                minIndex = j;
            }

       }
       temp = userDataArray[i];
       userDataArray[i] = userDataArray[minIndex];
       userDataArray[minIndex] = temp;
    }
    //printing the leader board
    for (i=0;i<counter;i++){
        printf("%d  %s         ",i+1,userDataArray[i].name);
        printf("%d\n",userDataArray[i].score);
        fprintf(frank,"%s,",userDataArray[i].name);
        fprintf(frank,"%d\n",userDataArray[i].score);
    }

    fclose(frank);
}

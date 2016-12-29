#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include"ValidOperations.h"
#include"InputPreparation.h"
#include"GameInterface.h"
#include"ArraysGeneration.h"
#include"GameState.h"
#include"EnteringGame.h"
#include"Global_Variables.h"
#include"Global_Variables.h"

 struct countingMoves user;

 time_t currentTime=0, startTime=0;;

 int lose =0;
 int minesNumber = 0;
 int initialize =0;


int main()
{
    startGame();

    return 0;

}

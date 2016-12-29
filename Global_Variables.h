
#ifndef GLOBAL_VARS
#define GLOBAL_VARS

extern struct countingMoves{

    int movesNumber;
    int FlagsNumber;
    int questionMarkNumber;
    time_t timePassed;
    time_t loadTime;
    long long userRank;
};

extern struct countingMoves user;
extern int minesNumber;

extern time_t currentTime, startTime;
extern int lose;
extern int initialize;

#endif


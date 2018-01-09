#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functionTimer.h"
#define ORIGINAL_FUNC_TIME 0.007187
#define ORIGINAL_EXEC_TIME 0.000231 

double total = 0;
clock_t timer;
int counter = 0;

void  setTotalTime(double tt){
		total += tt;
		counter ++;
}

void getFunctionTimerStats(){

double funcIncrease = total/CLOCKS_PER_SEC - ORIGINAL_FUNC_TIME/100;
	
printf("\n----------------RESULTS-----------------\n");
printf("Original Average Execution Time:  0.000231 sec.\n");
printf("Hacked Average Execution Time:    %f sec.\n", (total/counter)/CLOCKS_PER_SEC);
printf("----------------------------------------\n");
printf("Original Total Time:              0.007187 sec.\n");
printf("Hacked Total Time:                %f sec.\n", total/CLOCKS_PER_SEC);
printf("----------------------------------------\n");
printf("Difference of :                   %f sec.\n", ORIGINAL_FUNC_TIME - total/CLOCKS_PER_SEC );
printf("Optimized by:                     %.2f%%\n", funcIncrease/ORIGINAL_FUNC_TIME * 100);
printf("----------------------------------------\n");
}

void startTimer() {
	  timer=clock();
}

void stopTimer(){
	    timer = clock() - timer;
		setTotalTime(timer);
printf( "[TESTING FUNCTION]-(ZopfliResetHash){HACKED}-[EXEC#]: %d -[EXEC TIME#]: %f sec. \n", counter,((double)timer)/CLOCKS_PER_SEC);
}


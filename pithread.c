#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "pithread.h"

float randNumGen(){

   int random_value = rand(); //Generate a random number
   float unit_random = random_value / (float) RAND_MAX; //make it between 0 and 1
   return unit_random;
}

void *docalc (void *param) {

	int thrnum = *((int *)param); // The thread number ()
	num_ptos[thrnum] = 0;
	num_ptos_cir[thrnum] = 0;

	for (int i = 0; i<(inter/10); i++){

		double x = randNumGen(); // draws a number from 0 to 1
		double y = randNumGen(); // draws a number from 0 to 1

		double result = ((x*x) + (y*y));
        // If the sum of squares is less than R = 1
        // then fell into the circle
		if (result <= 1){
			num_ptos_cir[thrnum] ++; // count points in circle
		}

		num_ptos[thrnum] ++; // increments the total points of thread N (0 to 9)

	}

    // Prints on the screen the number of points in the circle
    // and in the total of each thread
	printf ("Circ t%i:%d \n",thrnum,num_ptos_cir[thrnum]);
	printf ("Total t%i:%d \n",thrnum,num_ptos[thrnum]);
	pthread_exit(0);
}

double pi() {

    int TOT_COUNT = 0; // total de pontos
    int tot_in = 0; // pontos no circulo

    for (int i = 0; i< NUMTHR ; i++){
        TOT_COUNT += num_ptos[i];  // TOT_COUNT = TOT_COUNT + num_ptos[i]
        tot_in += num_ptos_cir[i]; // tot_in = TOT_COUNT + num_ptos[i]
       }
    return 4.0*(((double)tot_in)/((double)TOT_COUNT));
}

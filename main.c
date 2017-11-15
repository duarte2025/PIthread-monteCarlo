#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "pithread.h"

int main () {

	pthread_t tid[10];  // ID thread
    scanf("%d", &inter);

    // For all threads
	for (int i = 0; i< NUMTHR ; i++){
	    // create thread
	    pthread_create (&tid[i], NULL, docalc, &i);
       }

    // For each thread
	for (int i = 0; i< NUMTHR ; i++){
        // wait for threads to finish
    	pthread_join (tid[i], NULL);
       }

	printf("Valor de pi:%lf\n",pi());

  return 0;
}

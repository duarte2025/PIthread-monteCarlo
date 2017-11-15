#define NUMTHR 10  // Total number of threads

int num_ptos [10]; // Total thread points
int num_ptos_cir[10]; // Points in the circle
int inter; // number of interactions

void *docalc (void *param);
float randNumGen();
double pi();

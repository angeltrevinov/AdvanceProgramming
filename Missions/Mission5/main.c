/*
 *Angel Odiel Treviño Villanueva
 *Matricula: A01336559
 * Fecha: 27/10/19
 *
 * Mission 5 calculate pi with multi or single thread
 * */
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define THREADS 1 //set the number of threads here
#define GOTAS 1000000000

long circulo = 0;
long gotas;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//----------------------------------------------------------
void *calculatePI(){
    double dX;
    double dY;
    int vRan = rand();
    long vLocal = 0;
    for (long i = 0; i < gotas; i++){
        dX = rand_r(&vRan) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        dY = rand_r(&vRan) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        if ((dX*dX) + (dY*dY) < 1){
            vLocal++;
        }
    }
    pthread_mutex_lock(&mutex);
    circulo += vLocal;
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

//----------------------------------------------------------
int main(){
    gotas = GOTAS / THREADS;
    time_t icontT = time(NULL);
    srand((unsigned)time(NULL));
    pthread_t *threads = malloc(THREADS * sizeof(pthread_t));
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    for (int i = 0; i < THREADS; i++){
        pthread_create(&threads[i], &attr, calculatePI, (void *) NULL);
    }
    for (int i = 0; i < THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    free(threads);
    printf("Valor de PI: %.20f\n", (4. * (double)circulo) / ((double)gotas * THREADS));
    printf("CPU time: %d sec\n", (unsigned int)(time(NULL) - icontT));
    return 0;
}
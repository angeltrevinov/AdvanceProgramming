#include <stdio.h>
#include <time.h>

int randomNumberGenerator(
        //method that generates a random number from the time
        ) {
    struct timespec p[1]; //we create a buffer
    clock_gettime(
            //clock_gettime gets the real time and allocates
            //  it in a buffer that we called p
            CLOCK_REALTIME,
            p
            );

    //the buffer includes tv._nsec and tv.sec and we divide
    //      by ten 1000 to get rid of extra 0s
    return p->tv_nsec / 1000;
}

int main() {
    int intNumRan;
    intNumRan = randomNumberGenerator();
    printf("Your random number: %d \n",  intNumRan);

    return 0;
}
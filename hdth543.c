/*######################################
# University of Information Technology #
# IT007 Operating System #
# Tran Hoang Bao Ly, 21521109 #
# File: hdth543.c #
######################################*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#define NUM_THREADS 2
int x = 0;
void *ProcessA()
{
    while (1)
    {
        x = x + 1;
        if (x == 20)
            x = 0;
        printf("x in A is %d \n", x);
    }
}
void *ProcessB()
{
    while (1)
    {
        x = x + 1;
        if (x == 20)
            x = 0;
        printf("x in B is %d \n", x);
    }
}
int main()
{
    pthread_t threads[NUM_THREADS];
    pthread_create(
        &threads[0],
        NULL,
        &ProcessB,
        NULL
    );
    pthread_create(
        &threads[1],
        NULL,
        &ProcessA,
        NULL
    );
    pthread_exit(NULL);
}
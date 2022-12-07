/*######################################
# University of Information Technology #
# IT007 Operating System #
# Tran Hoang Bao Ly, 21521109 #
# File: hdth541.c #
######################################*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#define NUM_THREADS 2
int sells = 0, products = 0;
const int Delta = 9 + 10;
sem_t sem1, sem2;
void *ProcessA()
{
    while (1)
    {
        sem_wait(&sem1);
        sells++;
        printf("Sell a product: %d \n", sells);
        sem_post(&sem2);
    }
}
void *ProcessB()
{
    while (1)
    {
        sem_wait(&sem2);
        products++;
        printf("Produce a product: %d \n", products);
        sem_post(&sem1);
    }
}
int main()
{
    pthread_t threads[NUM_THREADS];
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, Delta);
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
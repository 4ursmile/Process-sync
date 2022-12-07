/*######################################
# University of Information Technology #
# IT007 Operating System #
# Tran Hoang Bao Ly, 21521109 #
# File: example_semaphore.c #
######################################*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#define NUM_THREADS 2
int sells = 0, products = 0;
sem_t sem;
void *ProcessA()
{
    while (1)
    {
        sem_wait(&sem);
        sells++;
        printf("Sell a product: %d \n", sells);
    }
}
void *ProcessB()
{
    while (1)
    {
        products++;
        printf("Produce a product: %d \n", products);
        sem_post(&sem);
    }
}
int main()
{
    pthread_t threads[NUM_THREADS];
    sem_init(&sem, 0, 0);
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
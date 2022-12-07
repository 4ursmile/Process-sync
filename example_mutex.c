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
int products = 0;
pthread_mutex_t mutex;
void *ProcessA()
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (products > 0){
            products--;
            printf("Sell a product: %d \n", products);
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *ProcessB()
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        products++;
        printf("Produce a product: %d \n", products);
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
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
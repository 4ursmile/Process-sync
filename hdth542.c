/*######################################
# University of Information Technology #
# IT007 Operating System #
# Tran Hoang Bao Ly, 21521109 #
# File: hdth542.c #
######################################*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#define NUM_THREADS 2
#define N 1000
int a[N];
int pointer = -1;
sem_t sem;
void *ProcessA()
{
    while (1)
    {
        
        if (pointer > -1)
        {
            sem_wait(&sem);
            pointer--;
            a[pointer] = rand();
            printf("Remove 1 element in tail, total elements in array is %d \n", pointer+1);
             sem_post(&sem);
        } 
       
    }
}
void *ProcessB()
{
    while (1)
    {
        if (pointer < N-1)
        {
            sem_wait(&sem);
            pointer++;
            a[pointer] = rand();
            printf("Add 1 element, total elements in array is %d \n", pointer + 1);
            sem_post(&sem);
        } 
    }
}
int main()
{
    pthread_t threads[NUM_THREADS];
    sem_init(&sem, 0, 1);
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
/*######################################
# University of Information Technology #
# IT007 Operating System #
# Tran Hoang Bao Ly, 21521109 #
# File: btot551.c #
######################################*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#define NUM_THREADS 7
#define NUM_SEMAPHORE 6
int w = 0,v = 0,y = 0,z = 0,ans = 0,x1 = 0,x2 = 0,x3 = 0,x4 = 0,x5 = 0,x6 = 0;
sem_t sems[NUM_SEMAPHORE];
void *ProcessA(){
    w = x1*x2;
    sem_post(&sems[1]);
}
void *ProcessB(){
    v = x3*x4;
    sem_post(&sems[0]);
    sem_post(&sems[0]);
}
void *ProcessC(){
    sem_wait(&sems[0]);
    y = v*x5;
    sem_post(&sems[2]);
}
void *ProcessD(){
    sem_wait(&sems[0]);
    z = v*x6;
    sem_post(&sems[5]);
}
void *ProcessE(){
    sem_wait(&sems[1]);
    sem_wait(&sems[2]);
    y = w*y;
    sem_post(&sems[3]);
}
void *ProcessF(){
    sem_wait(&sems[5]);
    z = w*z;
    sem_post(&sems[4]);
}
void *ProcessG(){
    sem_wait(&sems[3]);
    sem_wait(&sems[4]);
    ans = y + z;
    printf("Ans of parallel system is: %d \n", ans);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    void *ArrThread[NUM_THREADS] = 
        {ProcessA, ProcessB, ProcessC, ProcessD, ProcessE, ProcessF, ProcessG};
    printf("Nhap lan luot x1,x2,x3,x4,x5,x6: ");
    scanf("%d%d%d%d%d%d", &x1,&x2,&x3,&x4,&x5,&x6);
    for (int i = 0; i < NUM_SEMAPHORE; i++)
    {
        sem_init(&sems[i],0,0);
    }
    
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, ArrThread[i], NULL);
    }

    int w = 0,v = 0,y = 0,z = 0,ans = 0;
    w = x1*x2;
    v = x3*x4;
    y = v*x5;
    z = v*x6;
    y = w*y;
    z = w*z;
    ans = y + z;
    printf("Ans single core system is: %d \n", ans);
    pthread_exit(NULL);
}
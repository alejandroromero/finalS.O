
# include <stdio.h> 
# include <pthread.h>
#include <malloc.h>
# define BufferSize 20

void *Producer(); 
void *Consumer();

int buferi=0; 
char *bufer;

pthread_cond_t Buffer_Not_Full=PTHREAD_COND_INITIALIZER; 
pthread_cond_t Buffer_Not_Empty=PTHREAD_COND_INITIALIZER; 
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main() 
{
pthread_t ptid,ctid; 
bufer=(char *) malloc(sizeof(char) * BufferSize); 
pthread_create(&ptid,NULL,Producer,NULL); 
pthread_create(&ctid,NULL,Consumer,NULL); 
pthread_join(ptid,NULL); pthread_join(ctid,NULL); 
return 0; }

void *Producer()
{
for(;;) 
{
pthread_mutex_lock(&mVar); 
if(buferi==BufferSize) 
{
pthread_cond_wait(&Buffer_Not_Full,&mVar); 
} 
bufer[buferi++]='@'; 
printf("Produce : %d \n",buferi); 
pthread_mutex_unlock(&mVar); 
pthread_cond_signal(&Buffer_Not_Empty); 
} 
}

void *Consumer() 
{ 
for(;;) 
{ 
pthread_mutex_lock(&mVar); 
if(buferi==-1) 
{ 
pthread_cond_wait(&Buffer_Not_Empty,&mVar); 
} 
printf("Consume : %d \n",buferi--); 
pthread_mutex_unlock(&mVar); 
pthread_cond_signal(&Buffer_Not_Full); 
} 
}


// egegve // 



#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <errno.h> 
#include <sys/ipc.h> 
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h> 
#define N 5
 
time_t etime;
sem_t mutex,customers,barbers; //declaracion de semaphores//
int count=0; 
void barber(void *arg); 
void customer(void *arg); 
int main(int argc,char *argv[]) { 
pthread_t p1,p2; //procesos//
int status=0; 
etime=time(NULL)+10; //tiempo//
 
sem_init(&mutex,0,1); 
sem_init(&customers,0,0); //inicializo semaphore//
sem_init(&barbers,0,1); 
 
status=pthread_create(&p1,NULL,(void *)barber,NULL); 
if(status!=0) 
perror("create barbers is failure!\n"); 
 
status=pthread_create(&p2,NULL,(void *)customer,NULL); 
if(status!=0) 
perror("create customers is failure!\n");  
pthread_join(p2,NULL); 
pthread_join(p1,NULL); 
exit(0); 
} 
void barber(void *arg) { 
while(time(NULL)<etime || count>0) { 
sem_wait(&customers); 
sem_wait(&mutex); 
count--; 
printf("Barber:cut hair,count is:%d.\n",count); 
sem_post(&mutex); 
sem_post(&barbers); 
sleep(3); 
} 
} 
void customer(void *arg) { 
while(time(NULL)<etime) { 
sem_wait(&mutex); 
if(count<N) { 
count++; 
printf("Customer:add count,count is:%d\n",count); 
sem_post(&mutex); 
sem_post(&customers); 
sem_wait(&barbers); 
} 
else 
 
 
sem_post(&mutex); 
sleep(1); 
} 
}
//La logica principal me guie del pseudocodigo que mando:  http://en.wikipedia.org/wiki/Sleeping_barber_problem y algunos accesorios extras meguie de :http://www.codeproject.com/Questions/49028/Sleeping-barber-problem//

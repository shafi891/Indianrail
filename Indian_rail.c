#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<semaphore.h>
 int trainarrived= 0, allPassengerseated= 0; leftover= 0; seatingcounter= 0;

struct Station
 {
 int NoOfseatsleft; waitingPassenger; SeatedPassenger;
      sem_t lock;
 }S;
 
     void station_init()
  {
      seatingcounter= 0;
         leftover= 0;
      printf("\n ENTER THE TRAIN'S CAPACITY : ");
          scanf("%d", &s.NoOfseatsleft);
        if(S.NoOfseatsleft == 0)
     {
        printf(" TRAIN IS ALREADY FULL>>> \n );
        exit(0);
      }
 if(S.NoOfseatsleft < 0)
      {
               printf(" SEATS CAN'T BE NEGATIVE \N");
               exit(0);
               
       }
   
               
      
 

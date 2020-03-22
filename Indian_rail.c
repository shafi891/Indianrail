#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<semaphore.h>
 int trainarrived= 0, allPassengerseated= 0, leftover= 0, seatingcounter= 0;

struct Station
 {
 int NoOfseatsleft, waitingPassenger, SeatedPassenger,
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
        printf(" TRAIN IS ALREADY FULL>>> \n ");
        exit(0);
      }
 if(S.NoOfseatsleft < 0)
      {
               printf(" SEATS CAN'T BE NEGATIVE \n");
               exit(0);
               
       }            
   printf("ENTER THE NO OF PASSENGER THAT ARE WILLING TO BOARD AT STATION :");
              scanf("%d", &S.waitingPassenger);
   if(s.waitingPassenger<0)
      {
              printf("PASSENGER CAN'T BE NEGATIVE \N ");
       exit(0);
      }
      
         if (s.waitingPassenger > s.NoOfseatsleft)
  {
                   leftover = S.waitingPassenger - S.NoOfseatsleft ;
   printf("\n\n %d PASSENGER WILL BE LEFT AT STATION .\N\N",leftover);
   
   
  }
    
      
      void* station_load_train(void *args)
      {
        struct station *p = (struct station *)args;
       if((trainarrived == 1) && (p -> NoOfseatsleft > 0))
       {
        station_on_board(p);
       }
   }
      
     int main()
     {
      int i = 0; array = 0;
      printf("\t\t\t\t\t IND
     
   

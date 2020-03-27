#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<semaphore.h>
 int train_arrived= 0, allPassenger_seated= 0, remains= 0, seating_counter= 0;

struct Rail_station
 {
 int No_Of_seatsleft, waiting_Passenger, Seated_Passenger;
  sem_t lock;
 }S;
 
     void Rail_station_init()
  {
      seating_counter= 0;
        remains= 0;
      printf("\n ENTER THE TRAIN'S SEAT CAPACITY : ");
          scanf("%d", &S.No_Of_seatsleft);
        if(S.No_Of_seatsleft==0)
     {
        printf(" TRAIN IS ALREADY FULL>>> \n ");
        exit(0);
      }
 if(S.No_Of_seatsleft<0)
      {
               printf(" SEATS CAN'T BE NEGATIVE \n");
               exit(0);
               
       }            
   printf("ENTER THE NO. OF PASSENGER THAT ARE WILLING TO BOARD AT STATION :");
              scanf("%d", &S.waiting_Passenger);
   if(S.waiting_Passenger<0)
      {
              printf("PASSENGER CAN'T BE NEGATIVE \n ");
       exit(0);
      }
      
         if (S.waiting_Passenger>S.No_Of_seatsleft)
  {
                   remains = S.waiting_Passenger - S.No_Of_seatsleft ;
   printf("\n\n %d PASSENGER LEFT AT STATION .\n\n",remains);
          S.waiting_Passenger = S.No_Of_seatsleft ;
   
   
    }
    
 }
      
      void* Rail_station_load_train(void *args)
      {
       
         printf("NOW TRAIN IS IN STATION AND IT'S OPEN THE DOORS PLEASE WAIT....");
       
               struct Rail_station *plt = (struct Rail_station *)args;
                train_arrived = 1;
                sleep(3);
                
                  if(plt-> No_Of_seatsleft<0){
                            printf("\n SEATS LEFT: 0 \n");}
                if(allPassenger_seated == 1 || plt-> No_Of_seatsleft== 0)
                {
               printf("\n SEATS LEFT: %d \n", plt-> No_Of_seatsleft);
                printf("\n TRAIN DEPARTED...\n");
                }
                if(remains > 0)
                {
                    printf("\n REMAINS PASSENGERS =%d \n", remains);
                            }
                     } 
       void Rail_station_on_board(struct Rail_station *st)
            { seating_counter ++;
                  sem_wait(&S.lock);
                allPassenger_seated= 0;
                   st-> No_Of_seatsleft--;
                printf("%d SUCCESSFULLY PASSENGERS ARE  SEATED \n",seating_counter);
                     allPassenger_seated= 1;
             sem_post(&S.lock);
             }
                         
       void* Rail_station_wait_for_train(void *args)
                            {
                 struct Rail_station *plt = (struct Rail_station *)args;
                  if((train_arrived ==1) &&(plt-> No_Of_seatsleft>0))
                  {
                   Rail_station_on_board(plt);
                  }
          }
                
                
                             
      
     int main()
     {
      int j = 0, All_waiting, array = 0;
           printf("\t\t!!!...INDIAN~TRAIN~IS~BOOTING...!!! \n");
         
                for(j=0; j<8; j++)
                { 
                     printf(".-.-.-.-.-.-.-");
                 sleep(1);
                }
      printf("\n\n\n");
           while(1)
           {
            printf("\n IF YOU WANT TO EXIT, PRESS CTRL + C\n");
              Rail_station_init();
               pthread_t train, passenger[All_waiting+1]; //create passenger and train thread
            sem_init(&S.lock,0,1);
               pthread_create(&train, NULL, Rail_station_load_train,&S);
            sleep(2);
        for(j=0;j<All_waiting;j++)
               {
           pthread_create(&passenger[j],NULL, Rail_station_wait_for_train,&S);
             printf("\n PASSANGER%d IS ARRIVED AT STATION\n",j+1);
        }
        for(j=0;j<All_waiting;j++)
        { pthread_join(passenger[j],NULL);}
            pthread_join(train,NULL);
            
           } 
      return 0;
     }
         
            
   

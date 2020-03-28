#include<pthread.h>
struct Rail_station
{
int waiting_Passenger;
int Seated_Passenger;
};

void Rail_station_init();
void* Rail_station_load_train(void *args);
void Rail_station_on_board(struct Rail_station *st);
void* Rail_station_wait_for_train(void *args);

#include <stdio.h>
#define A 7
#define C 5
#define M 11

int main(void){
 int seed=0;
 int Loops=0;
 do{
    seed=(A*seed+C)%M;
    printf("%i\n",seed);
    Loops++;
 }while(seed!=0);
 printf("%d\n",Loops);
 return 0;
}
 
 

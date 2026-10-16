#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
 double x,y,r,pi;
 int hits=0;
 printf("enter a radius:");
 scanf("%lf",&r);
 if(r<=0){
   printf("Invalid!Please enter a positive number!\n");
 }
 for (int i=1;i<10000;i++){
    x=((double)rand()/RAND_MAX)*r;
    y=((double)rand()/RAND_MAX)*r;
    if(x*x+y*y<=r*r){
      hits++;
      pi=4.0*hits/i;
      printf("\nthe approximation to π is %lf\n",pi);
    }
 }
 return 0;
}

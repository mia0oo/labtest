#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main(void){
 double pi,x;
 double sum=0.0;
 for(int i=0;;i++){
    x=pow(-1,i)/(2*i+1);
    sum=x+sum;
    pi=4.0*sum;
    if(fabs(pi-M_PI)<1e-7){
      printf("After %i iterations, it get π correctly approximated to 7 decimal places.\n",i+1);
      break;
    }
 }
 return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define D_MAX 100000

int main(void){
 double i,x;
 for(i=1.0;;i++){
     for(x=1.0;x<D_MAX;x++){
        if(fabs((2.0*x+i)/x-M_E)<=1e-15){
          printf("The pair give the best approximation to e is %i and %i\n",(int)(2*x+i),(int)x);
          break;
        }
     }
 } 
 return 0;
}
     
    
      


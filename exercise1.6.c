#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 int median=RAND_MAX/2;
 int minus_cnt=1,plus_cnt=1;
 for(int i=0;i<500;i++){
    if(rand()<median){
       minus_cnt++;
    }
 }
 int d;
 d=minus_cnt-plus_cnt;
 printf("the value of the difference of plus_cnt and minus_cnt is %i \n",d);
 return 0;
}
    


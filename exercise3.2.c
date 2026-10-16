#include <stdio.h>

int main(void){
 int buttons[3]={600,60,10};
 int presstime=0;
 int remaintime,count;
 printf("Type the time required:\n");
 scanf("%i",&remaintime);
 for(int i=0;i<3;i++){
    count=remaintime/buttons[i];
    presstime+=count;
    remaintime=remaintime%buttons[i];
 }
 if(remaintime>0){
   presstime++;
 }
 printf("Number of button presses = %i\n",presstime);
 return 0;
}
   
 
 

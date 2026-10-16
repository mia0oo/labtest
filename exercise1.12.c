#include <stdio.h>

int main(void){
 int a,b,c;
 while(1){
  printf("How much money would you like?\n");
  scanf("%i",&a);
  b=(a/20)*20;
  c=b+20;
  if(a<0){
    printf("Wrong number!Try again!\n");
  }
  if(a>=0&&a<20){
    printf("I can give you 20 and more, try again!\n");
  }
  if(a>=20){ 
    if(a%20!=0){
      printf("I can give you %i or %i,try again!\n",b,c);
    }
    else{
      printf("OK,dispensing ...\n");
      break;
    }
  }
 }
  return 0;
}

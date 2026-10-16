#include <stdio.h>
#include <stdlib.h>

int main(void){
 int a=rand()%1000+1;
 int b;
 printf("guess the number!\n");
 for(int i=1;i<=10;i++){
    scanf("%i",&b);
    if(b>a){
      printf("your guess was too high!\n");
    }
    else if(b<a){
      printf("your guess was too low!\n");
    }
    else{
      printf("Congrats!You guessed it!\n");
      return 0;
    }
 }
 printf("Sorry!You have used 10 attempts!");
 return 0;
}

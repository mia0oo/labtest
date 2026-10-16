#include <stdio.h>
#include <stdlib.h>

#define MAX_SONGS 100000

int main(void){
 int n;
 int playlist[MAX_SONGS];
 printf("How many songs required?\n");
 if(scanf("%i",&n)!=1||n<=0||n>MAX_SONGS){
   printf("invalid number!\n");
   return 1;
 }
 for(int i=0;i<n;i++){
    playlist[i]=i+1;
 }
 for(int i=n-1;i>0;i--){
    int j=rand()%(i+1);
    int temp=playlist[i];
    playlist[i]=playlist[j];
    playlist[j]=temp;
 }
 for(int i=0;i<n;i++){
    printf("%i ",playlist[i]);
 }
 printf("\n");
 return 0;
}

#include <stdio.h>

int main(void)
{
 int n,a,max;
 int f=0;
 printf("To find the largest odd integer among your inputs.\nTips:even numbers will be ignored!\n");
 printf("How many numbers do you wish to enter ? \n");
 scanf("%i",&n);
 printf("Enter %i integer numbers:",n);

 for(int i=0;i<n;i++){
    scanf("%i",&a);
    if(a%2==0){
      printf("%i is even,ignoring.\n",a);
      }
    else{
      if(f==0){
        max=a;
        f=1;
        }
      else if(a>max){
        max=a;
        }
      }
    }
 printf("The largest odd integer is %i \n",max);
 return 0;
}

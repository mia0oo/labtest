#include <stdio.h>

int main(void)
{
 int n;
 double max,a;
 printf("How many numbers do you wish to enter ? \n");
 scanf("%i",&n);
 printf("Enter %i real numbers:",n);
 scanf("%lf",&max);
 for(int i=1;i<n;i++){
    scanf("%lf",&a);
    if(a>max){
      max=a;
    }
 }
 printf("Maximum value: %.2f\n",max);
 return 0;
}

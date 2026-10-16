#include <stdio.h>

int twicesum(int j,int k,int m);

int main(void)
{
 int a, b, c, d;
 printf("Input three integers: ");
 scanf("%i%i%i",&a,&b,&c);
 d=twicesum(a,b,c)+7;
 printf("\nTwice the sum of integers plus 7 is %i !\n",d);
 return 0;
}

int twicesum(int j,int k,int m)
{
 int count;
 count=(j+k+m)*2;
 return count;
}

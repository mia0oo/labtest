#include <stdio.h>
#include <math.h>

int main(void){
 int x;
 printf("type in a number\n");
 scanf("%i",&x);
 double y=sin(x)*sin(x)+cos(x)*cos(x);
 printf("sin(%i)*sin(%i)+cos(%i)*cos(%i)=%.2lf\n",x,x,x,x,y);
 return 0;
}

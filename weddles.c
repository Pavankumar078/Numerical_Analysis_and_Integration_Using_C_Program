/*C program to implement Weddle's rule*/
#include<stdio.h>
float y(float x)
{
   return(1/(1+x*x));
}
int main()
{
  int n,i;
  float x0,xn,h,s=0;
  printf("Enter the initial and final values of interval\n");
  scanf("%f%f",&x0,&xn);
  printf("Enter the number of intervals\n");
  scanf("%d",&n);
  h=(xn-x0)/n;
  for(i=0;i<=n;i+=2)
     s+=y(x0+i*h);
  for(i=1;i<=n;i+=4)
     s=s+5*y(x0+i*h);
  for(i=3;i<=n;i+=4)
     s=s+6*y(x0+i*h);
  printf("The value of the integral is=%f",3*(h/10)*s);
}
/*Output:
Enter the initial and final values of interval
0                                                                               
1                                                                               
Enter the number of intervals                                                   
6                                                                               
The value of the integral is=0.785400*/

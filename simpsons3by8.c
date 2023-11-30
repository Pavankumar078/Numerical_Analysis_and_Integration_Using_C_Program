/*C program to implement Simpson's 3/8th rule*/
#include<stdio.h>
float f(float x)
{
   return(1/(1+x*x));
}
int main()
{
   int n,i;
   float x0,xn,h,s=0;
   printf("Enter the initial and final value of interval");
   scanf("%f%f",&x0,&xn);
   printf("\nEnter the number of interval\n");
   scanf("%d",&n);
   h=(xn-x0)/n;
   s=f(x0)+f(xn);
   for(i=1;i<n;i++)
   {
      if(i%3==0)
	s=s+2*f(x0+i*h);
      else
	s=s+3*f(x0+i*h);
   }
   printf("The value of the integral =%f",(3*h*s)/8);
}
 /*Output*/
/*Enter the initial and final value of interval  0  1
Enter the number of interval
6
The value of the integral =0.785396*/


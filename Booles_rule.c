/*C program to implement Boole's rule*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x)
{
   return(1/(1+x*x));
}
int main()
{
   float h,s;
   int n,i,a,b;
   printf("Enter the upper and lower limits of integral\n");
   scanf("%d%d",&a,&b);
   printf("Enter the number of intervals\n");
   scanf("%d",&n);
   if(n%4!=0)
   {
     printf(" n should be the multiple of 4\n");
     exit(0);
   }
   h=(float)(b-a)/n;
   s=7*f(a);
   for(i=1;i<=n;i+=4)
   {
     s+=32*f(a+i*h)+12*f(a+(i+1)*h)+32*f(a+(i+2)*h)+14*f(a+(i+3)*h);
   }
   s=(2*h*s)/45;
   printf("The value of integral is:%f",s);
   return 0;
}
/*Output*/
/*Enter the upper and lower limits of integral
0                                                                               
1                                                                               
Enter the number of intervals                                                   
8                                                                               
The value of integral is: 0.804843*/


/*C program to solve the IVP by Runge Kutta 4th order method*/
#include<stdio.h>
#include<math.h>
#define F(x,y)y-(x)
int main()
{
   float y0,x0,y1,n,h,f,f1,f2,f3,k1,k2,k3,k4;
   printf("\n Enter the value of x0:");
   scanf("%f",&x0);
   printf("\n Enter the value of y0:");
   scanf("%f",&y0);
   printf("\nEnter the value of h:");
   scanf("%f",&h);
   printf("\n Enter the value of last point:");
   scanf("%f",&n);
   for(;x0<n;x0=x0+h)
   {
     f=F(x0,y0);
     k1=h*f;
     f1=F(x0+h/2,y0+k1/2);
     k2=h*f1;
     f2=F(x0+h/2,y0+k2/2);
     k3=h*f2;
     f3=F(x0+h,y0+k3);
     k4=h*f3;
     y1=y0+(k1+2*k2+2*k3+k4)/6;
     printf("\n\n K1=%f",k1);
     printf("\n\n K2=%f",k2);
     printf("\n\n K3=%f",k3);
     printf("\n\n K4=%f",k4);
     printf("\n\n y(%f)=%f",x0+h,y1);
     y0=y1;
   }
   return 0;
}
/*Output*/
/*Enter the value of x0:0                                                        
 Enter the value of y0:2                                                        
Enter the value of h:0.1                                                 
 Enter the value of last point:0.1                                              
 K1=0.200000                                                                    
 K2=0.205000                             
 K3=0.205250                                                             
 K4=0.210525                                                            
 y(0.100000)=2.205171*/ 


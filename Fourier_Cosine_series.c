/*C program to implement Fourier Cosine series for polynomial equation having the period (0,l)*/
#include<stdio.h>
#include<math.h>
#define pi 3.142
double d_r(double d)
{
   return(d*3.142/180);
}
int fact(int n)
{
   if(n==0)
    return (1);
   else
    return(n*fact(n-1));
}
double power(double x,int n)
{
  int i;
  double s=1.0;
  if(x==0)
   return (0);
   for(i=1;i<=n;i++)
     s*=x;
   return(s);
}
float f(int x,double a[],int n)
{
   int i;
   double s=0.0;
   if(x==0)
   s=a[0];
   else
   {
	for(i=n;i>=0;i--)
	{
	    s+=(a[i]*power(x,i));
	}
   }
   return(s);
}
float df(int x,int n,int i,double a[])
{
   int dr=i,j;
   double r=0.0;
   if(x==0)
   return(a[i]*i);
   for(j=n;j>i-1;j--)
   {
      r+=(fact(j)/fact(j-dr)*a[j]*power(x,(j-dr)));
   }
   return(r);
}
double Ia0(double l,int n,double a[])
{
   int i;
   double s=0.0,x1;
   for(i=n;i>=0;i--)
   {
     x1=power(l,(i+1));
     s+=(a[i]*x1/(i+1));
   }
   return (s);
}
double Ian(int x, int n,double a[],int l)
{
  double s,x1,d;
  int dt,sg=1,i;
  float dlt=(n*3.142*x/l);
  dt=(fabs(sin(dlt)));
  s=f(x,a,n)*dt;
  s/=3.142;
  for(i=1;i<=n;i++)
  {
     if(i%2!=0)
     {
       x1=power(-1,sg);
       d=df(x,n,i,a);
       s-=((x1*cos(n*3.142*x/l)/power(n,i+1))*d);
       s/=pow(3.142,i+1);
     }
     else
     {
	x1=power(-1,sg);
	d=df(x,n,i,a);
	s-=((x1*sin(n*3.142*x/l)/power(n,i+1))+d);
	s/=pow(3.142,i+1);
	sg++;
     }
  }
  return(s);
}
int main()
{
   double a0,an,bn,x,fx,c,s;
   int n,i;
   double ce[100];
   float l;
   printf("\nEnter the degree of polynomial equation\n");
   scanf("%d",&n);
   printf("Enter the co-efficients of polynomial\n");
   for(i=0;i<=n;i++)
   {
     scanf("%lf",&ce[i]);
   }
   printf("Enter the value of l\n");
   scanf("%f",&l);
   a0=(Ia0(l,n,ce)-Ia0(0,n,ce));
   an=(Ian(l,n,ce,l)-Ian(0,n,ce,l));
   a0=(2*a0)/l;
   an=(2*an)/l;
   printf("Co-efficients are:\n");
   printf("\nA0=%lf",a0);
   printf("\nAn=%lf",an);
   printf("\n Enter the value of x\n");
   scanf("%lf",&x);
   fx=a0/2;
   for(i=1;i<=n;i++)
   {
      fx+=((an*cos(d_r(i*x))));
   }
   printf("\n F(x):%lf",fx);
   return (0);
}




/*Output*/
/*Enter the degree of polynomial equation                                         
1                                                                               
Enter the co-efficients of polynomial                                           
-1                                                                              
2                                                                               
Enter the value of l                                                            
1
Co-efficients are:                                                              
                                                                                
A0=0.000000                                                                     
An=-0.810359                                                                    
 Enter the value of x                                                           
90                                                                              
F(x):0.000165*/


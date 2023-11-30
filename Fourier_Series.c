/*C program to implement Fourier Series*/
#include<stdio.h>
#include<math.h>
#define pi 3.142
double d_r(int d)
{
   return(d*3.142/180);
}
int fact(int n)
{
   if(n==0)
    return 1;
   else
    return(n*fact(n-1));
}
double power(double x,int n)
{
  int i;
  double s=1.0;
  if(x==0)
   return 0;
   for(i=1;i<=n;i++)
     s*=x;
   return(s);
}
float f(double x,double a[],int n)
{
   int i,s=0;
   if(x==0)
     return (a[0]);
   for(i=n;i>=0;i--)
   {
     s+=(a[i]*power(x,i));
   }
   return s;
}
float df(double x,int n,int i,double a[])
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
   double s=0.0,x;
   double lr=d_r(l);
   for(i=n;i>=0;i--)
   {
     x=power(lr,(i+1));
     s+=(a[i]*x/(i+1));
   }
   return s;
}
double Ian(double l,int n,double a[])
{
  double s,x,lr,d;
  int sg=1,i;
  lr=d_r(l);
  s=f(lr,a,n)*sin(d_r(n*l))/n;
  for(i=1;i<=n;i++)
  {
    if(i%2!=0)
    {
      x=power(-1,sg);
      d=df(lr,n,i,a);
      s-=(x*cos(d_r(n*l))/power(n,(i+1))*d);
    }
    else
    {
      x=power(-1,sg);
      d=df(lr,n,i,a);
      s+=(x*sin(d_r(n*l))/power(n,i+1)*d);
      sg++;
    }
  }
  return(s);
}
double Ibn(double l,int n,double a[])
{
   double s,x,lr,d;
   int sg=1,i;
   s=-(f(lr,a,n)*cos(d_r(n*l)))/n;
   for(i=1;i<=n;i++)
   {
      if(i%2!=0)
      {
	x=power(-1,sg);
	d=df(lr,n,i,a);
	s-=((x*sin(d_r(n*l))/power(n,i+1))*d);
	sg++;
      }
      else
      {
	 x=power(-1,sg);
	 d=df(lr,n,i,a);
	 s+=((x*cos(d_r(n*l))/power(n,i+1))*d);
      }
   }
   return s;
}
int main()
{
   double a0,an,bn,x,fx;
   int n,i;
   double ce[100];
   printf("\nEnter the degree of polynomial equation\n");
   scanf("%d",&n);
   printf("Enter the co-efficients of polynomial\n");
   for(i=0;i<=n;i++)
   {
     scanf("%lf",&ce[i]);
   }
   a0=(Ia0(360,n,ce)-Ia0(0,n,ce))/pi;
   an=(Ian(360,n,ce)-Ian(0,n,ce))/pi;
   bn=(Ibn(360,n,ce)-Ibn(0,n,ce))/pi;
   printf("Co-efficients are:\n");
   printf("\nA0=%lf",a0);
   printf("\nAn=%lf",an);
   printf("\nBn=%lf",bn);
   printf("\n Enter the value of x\n");
   scanf("%lf",&x);
   fx=a0/2;
   for(i=1;i<=n;i++)
   {
      fx+=((an*cos(d_r(i*x)))+bn*sin(d_r(i*x)));
   }
   printf("\n F(x):%lf",fx);
}

/*Output*/

/*Enter the degree of polynomial equation
2
Enter the co-efficients of polynomial
2
2
1
Co-efficients are:

A0=42.893771
An=1.013611
Bn=0.000260
 Enter the value of x
90
F(x):23.474108*/


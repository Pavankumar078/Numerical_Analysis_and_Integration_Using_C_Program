/*C program to implement Fourier Sine series for polynomial equation having the period (0,l)*/
#include<stdio.h>
#include<math.h>
#define pi 3.142
double d_r(double d)
{
   return(d*pi/180);
}
int fact(int n)
{
  if(n==0)
  return(1);
  else
  return(n*fact(n-1));
}
double power(double x,int n)
{
   int i;
   double s=1.0;
   if(x==0)
     return(0);
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
float df(int x, int n, int i, double a[])
{
   int dr=i,j;
   double r=0.0;
   if(x==0)
     return(a[i]*i);
   for(j=n;j>i-1;j--)
   {
      r+=(fact(j)/fact(j-dr))*a[j]*power(x,(j-dr));
   }
   return(r);
}
double Ibn(int x,int n,double a[],int l)
{
   double s,x1,d,sn,temp;
   float dt;
   int sg=l,i;
   float dlt=(n*pi*x/l);
   dt=cos(dlt);
   s=-f(x,a,n)*dt;
   s/=(n*pi/l);
   for(i=1;i<n;i++)
   {
     if(i%2!=0)
     {
      x1=power(-1,sg);
      d=df(x,n,i,a);
      sn=sin(pi);
      temp=((x1*sn/power((n*pi/l),i+1))*d);
      s-=temp;
      sg++;
     }
     else
     {
       x1=power(-1,sg);
       d=df(x,n,i,a);
       temp=((x1*cos(n*pi*x/l)/power((pi*n/l),i+1))*d);
       s+=temp;
     }
   }
   return(s);
}
int main()
{
  double bn,x,fx,c,s;
  int n,i;
  double ce[100];
  float l;
  printf("\n Enter the degree of polynomial equation\n");
  scanf("%d",&n);
  printf("\n Enter the co-efficient of polynomial\n");
  for(i=0;i<=n;i++)
  {
    scanf("%lf",&ce[i]);
  }
  printf("\n Enter the value of l\n");
  scanf("%f",&l);
  bn=Ibn(l,n,ce,l)-Ibn(0,n,ce,l);
  bn=(2*bn)/l;
  printf("\n Co-efficients are \n");
  printf("\n Bn=%lf",bn);
  printf("\n Enter the value of x\n");
  scanf("%lf",&x);
  for(i=1;i<=n;i++)
  {
    fx+=((bn*sin(d_r(i*x))));
  }
  printf("\n F(x)=%lf",fx);
  return 0;
}
/*Output*/
/*Enter the degree of polynomial equation
1

 Enter the co-efficient of polynomial
-1
2
	
 Enter the value of l
1

 Co-efficients are

 Bn=-0.000000                                                                   
 Enter the value of x                                                           
90                                                                            
 F(x)=-0.000000*/  


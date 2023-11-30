/*C program to implement Taylor's Method for IVP*/
#include<stdio.h>
#include<math.h>
int fact(int n)
{
  if (n==0)
  return 1;
  else
    return (n*fact (n-1));
}
float f(int x,int a[],int n)
{
  int i,s=0;
  for(i=n;i>=0;i--)
  {
    s+=(a[i]*pow(x,i));
  }
  return s;
}
float df(int x,int n,int i,int a[])
{
   int dr=i,j;
   double r=0.0;
   for(j=n;j>i-1;j--)
   {
     r+=(fact(j)/fact(j-dr)*a[j]*pow((double)x,(double)(j-dr)));
   }
   return r;
}
int main()
{
   float s;
   int x,p,n,i,h,a[100];
   printf("Enter the degree of polynomial equation:\n");
   scanf("%d",&n);
   printf("\n Enter the value of x:");
   scanf("%d",&x);
   printf("\n Enter the co-efficients of polynomial:\n");
   for(i=0;i<=n;i++)
   {
     scanf("%d",&a[i]);
   }
   printf("Enter the point p:\n");
   scanf("%d",&p);
   h=x-p;
   s=f(p,a,n);
   printf("h:%d\n equation at point p:%f",h,s);

   for(i=1;i<=n;i++)
   {
      s+=((pow((double)h,(double)i)/fact(i))*df(p,n,i,a));
   }
   printf("\nResult ::%f\n",s);
   return 0;
}
/*Output*/
/*Enter the degree of polynomial equation:
3

 Enter the value of x:3

 Enter the co-efficients of polynomial:
1
2
4
3
Enter the point p:
2
h:1
 equation at point p:45.000000
Result ::124.000000*/ 


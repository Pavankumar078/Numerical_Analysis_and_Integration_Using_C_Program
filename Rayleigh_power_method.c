/*C program to implement  Rayleigh's power method*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void biggest(float x[10][10],float *,int);
void product(float a[10][10],float x[10][10],int n);
void display(float x[10][10],int n,int m);
int main()
{
   int i,j,k,itr=0;
   float a[10][10],x,lm[10][10],x1;
   int n;
   printf("Enter the order of matrix\n");
   scanf("%d",&n);
   printf("Enter the elements of matrix\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
	 scanf("%f",&a[i][j]);
      }
   }
   printf("Enter the initial eigen vector\n");
   for(j=0;j<n;j++)
     scanf("%f",&lm[j][0]);
   printf("Matrix is::\n");
   display(a,n,n);
   printf("Initial eigen value is:\n");
   display(lm,n,1);
   product(a,lm,n);
   biggest(lm,&x,n);
   while(itr<7)
   {
      product(a,lm,n);
      biggest(lm,&x1,n);
      if(fabs(x1-x)<0.001)
      {
	printf("The largest eigen value is::%0.3f",x1);
	printf("\nThe corresponding eigen vector is:\n");
	display(lm,n,1);
	exit(0);
      }
      x=x1;
   }
}


void biggest (float lm[10][10],float *big,int n)
{
   int i,j;
   *big=lm[0][0];
   for(i=1;i<n;i++)
   {
      if(lm[i][0]>*big)
      {
	 *big=lm[i][0];
      }
   }
   for(i=0;i<3;i++)
      lm[i][0]=lm[i][0]/(*big);
}
void product(float a[10][10],float lm[10][10],int n)
{
   int i,j,k;
   float sum=0,prd[10][10];
   for(i=0;i<n;i++)
   {
      for(j=0;j<1;j++)
      {
	 for(k=0;k<n;k++)
	 {
	    sum+=a[i][k]*lm[k][j];
	 }
	 prd[i][j]=sum;
	 sum=0;
      }
   }
   for(i=0;i<n;i++)
     for(j=0;j<1;j++)
       lm[i][j]=prd[i][j];
}
void display(float x[10][10],int n,int m)
{
   int i,j;
   for(i=0;i<n;i++)
   {
      for(j=0;j<m;j++)
      {
	 printf("%3.2f\t",x[i][j]);
      }
      printf("\n");
   }
}








/*Output*/
/*Enter the order of matrix
3
Enter the elements of matrix
2 0 1 0 2 0 1 0 2
Enter the initial eigen vector
1 0 0
Matrix is::
02.00   0.00    1.00
0.00    02.00   0.00
1.00    0.00    02.00
Initial eigen value is:
1.00
0.00
0.00
The largest eigen value is::03.000
The corresponding eigen vector is:
1.00
0.00
1.00*/



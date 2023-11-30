/*C program to implement Jacobian Iteration method for system of linear equations*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
   float nr,x[3],y[3],z[3],c[3],X[20],Y[20],Z[20];
   int i;
   printf("Enter the co-efficient of equations and constants of 3 equations\n");
   for(i=0;i<3;i++)
   {
     scanf("%f%f%f%f",&x[i],&y[i],&z[i],&c[i]);
   }
   X[0]=c[0]/x[0];
   Y[0]=c[1]/y[1];
   Z[0]=c[2]/z[2];
   printf("\n Iteration 1is: x=%0.3f  y=%0.3f  z=%0.3f",x[0],y[0],z[0]);
   i=1;
   while(i<20)
   {
      nr=(c[0]-(y[0]*Y[i-1])-(z[0]*Z[i-1]));
      X[i]=nr/x[0];
      nr=(c[1]-(x[1]*X[i-1])-(z[1]*Z[i-1]));
      Y[i]=nr/y[1];
      nr=(c[2]-(x[2]*X[i-1])-(y[2]*Y[i-1]));
      Z[i]=nr/z[2];
      printf("\n Iterations %d is:x=%0.3f, y=%0.3f z=%0.3f",i+1,X[i],Y[i],Z[i]);
      if((fabs((X[i]-X[i-1]))<0.00001)&&(fabs((Y[i]-Y[i-1]))<0.00001)&&(fabs(Z[i]-Z[i-1])<0.00001))
      {
	printf("\n Final values");
	printf("\n X=%0.3f  Y=%0.3f  Z=%0.3f",X[i],Y[i],Z[i]);
	exit(0);
      }
      i++;
   }
   printf("Iterations are not sufficient\n");
   return 0;
}
/*Output*/
/*Enter the co-efficient of equations and constants of 3 equations
 10    1   -1   11.19
  1   10    1   28.08
 -1    1   10   35.61

 Iteration 1is: x=10.000  y=1.000  z=-1.000
 Iterations 2 is:x=1.194, y=2.340 z=3.392
 Iterations 3 is:x=1.224, y=2.349 z=3.446
 Iterations 4 is:x=1.229, y=2.341 z=3.448
 Iterations 5 is:x=1.230, y=2.340 z=3.450
 Iterations 6 is:x=1.230, y=2.340 z=3.450
 Iterations 7 is:x=1.230, y=2.340 z=3.450
 Iterations 8 is:x=1.230, y=2.340 z=3.450
 Final values
 X=1.230  Y=2.340  Z=3.450*/


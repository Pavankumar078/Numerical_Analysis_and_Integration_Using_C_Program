/*C program to implement Inverse Lagrenge's interpolation*/
#include<stdio.h>
int main()
{
   int i,j,n;
   float x=0,y,nr,dr,x1[20],y1[20];
   printf("Enter the number of inputs\n");
   scanf("%d",&n);
   printf("Enter the X values associated Y values\n");
   for(i=0;i<n;i++)
   {
      scanf("%f%f",&x1[i],&y1[i]);
   }
   printf("Enter the value of Y for which X is needed:\n");
   scanf("%f",&y);
   for(i=0;i<n;i++)
   {
      printf("y(%0.3f):%0.3f\n",y1[i],x1[i]);
      nr=dr=1;
      for(j=0;j<n;j++)
      {
	 if(i!=j)
	 {
	    nr*=(y-y1[j]);
	    dr*=(y1[i]-y1[j]);
	 }
      }
      x=x+((nr*x1[i])/dr);
   }
   printf("At y=%0.3f value of x=%0.3f\n",y,x);
   return 0;
}
/*Output*/
/*Enter the number of inputs
4                                                                               
Enter the X values associated Y values                                          
30 -30                                                                          
34 -13                                                                          
38 3                                                                            
42 18                                                                           
Enter the value of Y for which X is needed:                                     
0                                                                               
y(-30.000):30.000                                                               
y(-13.000):34.000                                                               
y(3.000):38.000                                                                 
y(18.000):42.000
At y=0.000 value of x=37.230*/

/*C program to implement Newton's divided difference*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int dDifference(float d[10][10],float x[],int n)
{
    int i,j,k;
    for(j=1;j<n;j++)
    {
       printf("%d DD:  ",j);
       for(i=j;i<n;i++)
       {
	  k=abs(i-j);
	  d[i][j]=(d[i][j-1]-d[i-1][j-1])/(x[i]-x[k]);
	  printf("%f\t",d[i][j]);
       }
       printf("\n");
    }
}
int main()
{
   int i,n;
   float x[10],fx[10][10],x1,fx1,t=1;
   printf("Enter the number of values:");
   scanf("%d",&n);
   printf("\n Enter the value of x and fx\n");
   for(i=0;i<n;i++)
   {
      scanf("%f%f",&x[i],&fx[i][0]);
   }
   dDifference(fx,x,n);
   printf("Enter the value of x1 for which fx is needed\n");
   scanf("%f",&x1);
   fx1=fx[0][0];
   for(i=1;i<n;i++)
   {
      t*=(x1-x[i-1]);
      fx1+=t*fx[i][i];
   }
   printf("The value of f(x) at x=%0.3f  is %0.3f\n",x1,fx1);
   return 0;
}







/*Output*/
/*Enter the number of values:4
                                                                                
 Enter the value of x and fx                                                    
0 -4                                                                            
2 2                                                                             
3 14                                                                            
6 158                                                                           
1 DD:  3.000000 12.000000       48.000000                                       
2 DD:  3.000000 9.000000                                                        
3 DD:  1.000000                                                                 
Enter the value of x1 for which fx is needed                                    
4
The value of f(x) at x=4.000  is 40.000*/

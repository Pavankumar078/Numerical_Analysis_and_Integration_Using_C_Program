/*C program to implement Lagrenge’s interpolation formula*/
#include<stdio.h>
int main()
{
   int x[20],fx[20],i,j,nr,dr,x1,n;
   float fx1;
   printf("Enter the number of inputs\n");
   scanf("%d",&n);
   printf("Enter the x values asociated f(x) is values:\n");
   for(i=0;i<n;i++)
   {
     scanf("%d%d",&x[i],&fx[i]);
   }
   printf("Enter the value of x for which fx is needed\n");
   scanf("%d",&x1);
   for(i=0;i<n;i++)
   {
     printf("fx[%d] : %d\n",x[i],fx[i]);
     nr=dr=1;
     for(j=0;j<n;j++)
     {
       if(i!=j)
       {
	 nr*=(x1-x[j]);
	 dr*=(x[i]-x[j]);
       }
     }
     fx1=fx1+((float)nr*fx[i]/dr);
   }
   printf("At x=%d value of fx=%f\n",x1,fx1);
}
/*Output*/
/*Enter the number of inputs
4
Enter the x values asociated f(x) values:
0  -4
2  2
3  14
6  158                                                                           
Enter the value of x for which fx is needed                                     
4                                                                               
fx[0] : -4                                                                      
fx[2] : 2                                                                       
fx[3] : 14                                                                      
fx[6] : 158                                                                     
At x=4 value of fx=40.000000*/ 


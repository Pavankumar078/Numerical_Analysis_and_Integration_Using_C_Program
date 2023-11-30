/*C program to implement second order parabola fitting*/
#include<stdio.h>
#include<math.h>
void solution(float x[],float y[],float z[],float d[],double *a,double *b,double *c)
{
	double X[10],Y[10],Z[10],D;
	D = (x[0]*y[1]*z[2]+y[0]*x[2]*z[1]+z[0]*x[1]*y[2])-(x[0]*z[1]*y[2]+y[0]*x[1]*z[2]+z[0]*y[1]*x[2]);
	*a = ((y[0]*z[2]*(-1*d[1])+z[0]*y[1]*(-1*d[2])+(-1*d[0])*z[1]*y[2])-(y[0]*z[1]*(-1*d[2])+z[0]*y[2]*(-1*d[1])+(-1*d[0])*y[1]*z[2]))/D;
	*b = ((x[0]*z[1]*(-1*d[2])+z[0]*x[2]*(-1*d[1])+(-1*d[0])*x[1]*z[2])-(x[0]*z[2]*(-1*d[1])+z[0]*x[1]*(-1*d[2])+(-1*d[0])*z[1]*x[2]))/D;
	*c = ((x[0]*y[2]*(-1*d[1])+y[0]*x[1]*(-1*d[2])+(-1*d[0])*y[1]*x[2])-(x[0]*y[1]*(-1*d[2])+y[0]*x[2]*(-1*d[1])+(-1*d[0])*x[1]*y[2]))/D;
}
int main()
{
	int n,i;
	float x[10],y[10],x2[10],xy[10],x2y[10],x3[10],x4[10];
	float sx=0,sy=0,sx2=0,sxy=0,sx2y=0,sx3=0,sx4=0;
	float a[3],b[3],c[3],d[3];double x1,y1,z1;
	printf("Enter the number of values\n");
	scanf("%d",&n);
	printf("Enter the value of x and y array\n");
	for(i=0;i<n;i++)
	{
	    scanf("%f%f",&x[i],&y[i]);
	    x2[i]=x[i]*x[i];
	    x3[i]=x[i]*x[i]*x[i];
	    x4[i]=x[i]*x[i]*x[i]*x[i];
	    x2y[i]=x2[i]*y[i];
	    xy[i]=x[i]*y[i];
	    sx+=x[i];
	    sy+=y[i];
	    sx2+=x2[i];
	    sx3+=x3[i];
	    sx4+=x4[i];
	    sx2y+=x2y[i];
	    sxy+=xy[i];
	}
	printf("\n\nNormal equations are:");
	printf("\n%0.2f=%da+%0.2fb+%0.2fc",sy,n,sx,sx2);
	a[0]=n;b[0]=sx;c[0]=sx2;d[0]=sy;
	printf("\n%0.2f=%0.2fa+%0.2fb+%0.2fc",sxy,sx,sx2,sx3);
	a[1]=sx;b[1]=sx2;c[1]=sx3;d[1]=sxy;
	printf("\n%0.2f=%0.2fa+%0.2fb+%0.2fc",sx2y,sx2,sx3,sx4);
	a[2]=sx2;b[2]=sx3;c[2]=sx4;d[2]=sx2y;
	solution(a,b,c,d,&x1,&y1,&z1);
	printf("\n\ny=%0.2lf+(%0.2lf)x+(%0.2lf)x^2. This is the required parabola of best fit",x1,y1,z1);
	return 0;
}
/*Output*/
/*Enter the number of values
5                                                                               
Enter the value of x and y array                                                
0 1                                                                             
1 1.8                                                                           
2 1.3                                                                           
3 2.5                                                                           
4 6.3                                                                           
Normal equations are:                                                           
12.90=5a+10.00b+30.00c                                                          
37.10=10.00a+30.00b+100.00c                                                     
130.30=30.00a+100.00b+354.00c                                                   
y=1.42+(-1.07)x+(0.55)x^2. This is the required parabola of best fit*/ 


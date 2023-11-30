/*C program to illustrate Fuzzy set operations*/
#include<stdio.h>
#include<math.h>
#include<string.h>
typedef struct fuzzy
{
  float mf;
  char element[10];
}Fuzzyset;
void linkfloat()
{
  float *a,b;
  a=&b;
}
void unionfz(Fuzzyset s1[],Fuzzyset s2[],Fuzzyset s3[],int m,int n,int *x)
{
  	int i,q,temp,p=0,t[20],k=0,j;
  	t[0]=1;
  	for(i=0;i<m;i++)
  	{
 p=0;
    		for(j=0;j<n;j++)
   		 {

      if(strcmp(s1[i].element,s2[j].element)==0)
      {
	p=1;
	strcpy(s3[i].element,s1[i].element);
	if(s1[i].mf>=s2[j].mf)
	{
	  	s3[i].mf=s1[i].mf;
	  	t[k++]=j;
	}
	else
	{
	  	t[k++]=j;
	  	s3[i].mf=s2[j].mf;
	}
	break;
      }
    }
    if(p!=1)
    {
      strcpy(s3[i].element,s1[i].element);
      s3[i].mf=s1[i].mf;
    }
  }
  k=0;
  for(j=0;j<n;j++)
  {
      if(t[k++]!=j)
      {
      strcpy(s3[i].element,s2[j].element);
      s3[i].mf=s2[j].mf;
      i++;
      }
  }
  *x=i;
}
void intersectfz(Fuzzyset s1[],Fuzzyset s2[],Fuzzyset s3[],int m,int n,int *x)
{
   int i,j,k=0;
   for(i=0;i<m;i++)
   {
     for(j=0;j<n;j++)
     {
       if (strcmp(s1[i].element,s2[j].element)==0)
       {
	 strcpy(s3[k].element,s1[i].element);
	 if(s1[i].mf<=s2[i].mf)
	   s3[k].mf=s1[i].mf;
	 else
	   s3[k].mf=s2[j].mf;
	 k++;
	 break;
       }
     }
   }
   *x=k;
}
void fz_complement(Fuzzyset s[],Fuzzyset sc[],int n)
{
   int i;
   for(i=0;i<n;i++)
   {
     strcpy(sc[i].element,s[i].element);
     sc[i].mf=(1.-s[i].mf);
   }
}
void display(Fuzzyset s[],int num)
{
   int i;
   printf("{");
   for(i=0;i<num;i++)
     printf("(%s,%0.2f)",s[i].element,s[i].mf);
   printf("}");
}
void read(Fuzzyset s[],int num)
{
     int i;
     for(i=0;i<num;i++)
     {
       scanf("%s%f",s[i].element,&s[i].mf);
     }
}
int main()
{
   Fuzzyset s1[10],s2[10],s3[10],s4[10];
   int n,i,m,p;
   printf("Enter the number of elements of fuzzy set\n");
   scanf("%d%d",&m,&n);
   printf("Enter the elements of 1st set\n");
   read(s1,m);
   printf("Enter the elements of 2nd set\n");
   read(s2,n);
   printf("\nUnion of two sets is\n");
   unionfz(s1,s2,s3,m,n,&p);
   display(s3,p);
   printf("\nIntersection of two sets is\n");
   intersectfz(s1,s2,s3,m,n,&p);
   display(s3,p);
   printf("\nComplement of first set is\n");
   fz_complement(s1,s3,m);
   display(s3,m);
   return 0;;
}
/*Output*/
/*Enter the number of elements of fuzzy set
5                                                                               
5                                                                               
Enter the elements of 1st set                                                   
a 0.1                                                                           
b 0.4                                                                           
c 0.6                                                                           
d 0.9                                                                           
e 1                                                                             
Enter the elements of 2nd set                                                   
a 0                                                                             
b 0.6                                                                           
c 0.7                                                                           
d 0.8                                                                           
e 0.5                                                                           
                                                                                
Union of two sets is                                                            
{(a,0.10)(b,0.60)(c,0.70)(d,0.90)(e,1.00)}                                      
Intersection of two sets is                                                     
{(a,0.00)(b,0.40)(c,0.60)(d,0.80)(e,0.50)}                                      
Complement of first set is
{(a,0.90)(b,0.60)(c,0.40)(d,0.10)(e,0.00)}*/


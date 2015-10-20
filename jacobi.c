#include <stdio.h>
#include <math.h>
	
	static double *u,*v;
	static int x=10;
	static int y=10;

int jacobi(double **a,double *c);

int main()
{
	double  **a;
	double *c;
	int i,j,counter;

	//dynamically allocate the variables
	a = new double*[x];
	for(j=0;j<y;j++){
		a[j] = new double[y];
	}
	u = new double[x];	
	c = new double[x];	
	v = new double[x];

	//assign values for A matrix
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(i==j) a[i][j] = 5;
		}
		c[i] = 100*i;
	}

	/*
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			printf("a[%d][%d]=%lf\n",i,j,a[i][j]);
		}
	} */

	
	//performing jacobi iterations
	counter = jacobi(a,c);
	

	//printing output
	for(i=0;i<x;i++){	
		printf("u[%d] = %lf\n",i,u[i]);
	}
	printf("Number of iterations = %d\n",counter-1);
}

int jacobi(double **a,double *c){

	double e,eMax = 1,m;
	int i,j,counter=1;
 	
	while(eMax > pow(10,-5)){
		eMax = e = 0;
		for(i=0;i<x;i++){	
			m=0;
			for(j=0;j<y;j++){
				if(i!=j) m = m + a[i][j]*v[i];
			}	
			u[i] = (c[i] - m)/a[i][i];
			e = u[i] - v[i];
			if(e>eMax) eMax = e;
			v[i]=u[i]; 
		}
	counter += 1;
	}	
	
	return counter;
}
	

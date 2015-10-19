#include <stdio.h>
#include <math.h>

int main()
{

	double  **a;
	double *u;
	double *c;
	int x=100;
	int y=100;
	int i,j;	
	double e,eMax,tmp1,tmp2;

	//dynamically allocate the variables
	a = new double*[x];
	for(j=0;j<y;j++){
		a[j] = new double[y];
	}
	u = new double[x];	
	c = new double[x];	

	//assign values for A matrix
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(i==j) a[i][j] = 1;
		}
		c[i] = 500;
	}

	/*
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			printf("a[%d][%d]=%lf\n",i,j,a[i][j]);
		}
	} */

	
	//performing jacobi iterations
	while(eMax > pow(10,-5)){
		e = 0;
		for(i=0;i<x;i++){
			tmp1 = u[i];
			u[i]=0;	
			for(j=0;j<y;j++){
				if(i!=j) u[i] += a[i][j]*u[i];
			}	
			u[i] = (c[i] - u[i])/a[i][i];
			tmp2 = e;
			e = u[i] - tmp1;
			if(e>tmp2) eMax = e; 
		}
	}
	
	for(i=0;i<x;i++){
		printf("c[%d] = %lf\n",i,c[i]);
	}
	
}

	

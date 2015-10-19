#include <stdio.h>
#include <math.h>

int main()
{

	double  **a;
	double *u,*v,*c;
	int x=10;
	int y=10;
	int i,j, counter = 1;	
	double e,tmp1,tmp2,m=0;
	double eMax=1;

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
		c[i] = 100;
		v[i] = 0;
	}

	/*
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			printf("a[%d][%d]=%lf\n",i,j,a[i][j]);
		}
	} */

	
	//performing jacobi iterations
	
	while(counter<=3){
//	while(eMax > pow(10,-5)){
		e = 0;
		for(i=0;i<x;i++){	
			m=0;
			for(j=0;j<y;j++){
				if(i!=j) m = m + a[i][j]*v[i];
			}	
			u[i] = (c[i] - m)/a[i][i];
			tmp1 = e;
			e = u[i] - v[i];
			if(e>eMax) eMax = e;
			v[i]=u[i]; 
		}
		for(i=0;i<x;i++){
			printf("u[%d] = %lf\n",i,u[i]);
		}
	counter += 1;
	}
	
}

	

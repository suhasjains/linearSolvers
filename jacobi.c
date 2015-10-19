#include <stdio.h>

int main()
{

	double  **a;
	int x=100;
	int y=100;
	int i,j;	

	a = new double*[x];
	for(i=0;i<y;i++){
		a[i] = new double[y];
	}

	for(i=0;i<x;i++){
		a[i][j] = 1;
		for(j=0;j<y;j++){
			a[i][j] = 1;
		}
	}

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			printf("a[%d][%d]=%lf\n",i,j,a[i][j]);
		}
	}

	
}	
 

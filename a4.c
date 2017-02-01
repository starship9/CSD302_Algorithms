/*
Lab 4: Strassen's multiplication for 2 2x2 matrices
Submitted by: Nishank Saini
Date: 1st February, 2017
ID: 1410110266
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//function for printing the matrix
void printMatrix(int arr[][2]){
	int i,j;

for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\n",arr[i][j]);
		}
	}

}

//function for implementing Strassen's algorithm
void strassensMultiply(int m1[][2], int m2[][2]){

	int p,q,r,s,t,u,v;
	int res[2][2];
	int i,j;

	p = (m1[0][0] + m1[1][1])*(m2[0][0] + m2[1][1]);
	q = (m1[1][0] + m1[1][1])*m2[0][0];
	r = (m2[0][1]-m2[1][1])*m1[0][0];
	s = m1[1][1]*(m2[1][0]-m2[0][0]);
	t = (m1[0][0]+m1[0][1])*m2[1][1];
	u = (m1[1][0]-m1[0][0])*(m2[0][0]+m2[0][1]);
	v = (m1[0][1]-m1[1][1])*(m2[1][0]+m2[1][1]);

	res[0][0] = p+s-t+v; 
	res[0][1] = r+t;
	res[1][0] = q+s;
	res[1][1] = p+r-q+u;

	printf("Here's the result:\n");
		printMatrix(res);
		
	}
void main(){

	int m1[2][2] = {{1,2},{3,4}};
	int m2[2][2] = {{5,6},{7,8}};

	printf("Here's matrix 1:\n\t");
		printMatrix(m1);

	printf("Here's matrix 2:\n\t");
		printMatrix(m2);

		strassensMultiply(m1,m2);
	
}

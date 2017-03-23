// /*
// Assignment 11: Matrix Chain Multiplication
// Name: Nishank Saini
// SNU ID: 1410110266
// Date: 22.3.17
// CSD32


// */
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <malloc.h>

// #define INFINITY 9999

// void printOptimalParenthesis(int s[][100],int i, int j){
// 	if (i==j)
// 		printf("Matrix %d",i);

// 	else {
// 		printf("(");
// 		printOptimalParenthesis(s,i,s[i][j]); 
// 		printOptimalParenthesis(s,s[i][j]+1,j);
// 		printf(")");
// 	}
// }


// void matrixChainOrder(int arr[]){
// 	int n = sizeof(arr)/sizeof(int);
// 	// int m[100][100];
// 	// int s[100][100];
// 	 int q;

// 	int** m = (int**)malloc(sizeof(int*)*n);
// 	for (int i = 0; i < n; ++i)
// 	{
// 		/* code */
// 		m[i] = (int *)malloc(sizeof(int)*n);
// 	}


// 	int** s = (int**)malloc(sizeof(int*)*(n-1));
// 	for (int i = 0; i < (n-1); ++i)
// 	{
// 		/* code */
// 		s[i] = (int *)malloc(sizeof(int)*(n-2));
// 	}

// 	for (int i = 0; i < n; ++i)
// 	{
// 		for (int j = 0; j < n; ++j)
// 		{
// 			/* code */
// 			if(i==j)
// 				m[i][j]=0;
// 		}
// 	}

// 	for (int l = 2; l < n; ++l)
// 	{
// 		/* code */
// 		for (int i = 1; i < (n-l+1); ++i)
// 		{
// 			/* code */
// 			int j = i+l-1;
// 			m[i][j]=INFINITY;
// 			for (int k = i; i < j-1; ++i)
// 			{
// 				/* code */

// 				q = m[i][k] + m[k+1][j] + (arr[i-1]*arr[k]*arr[j]);
// 				if(q<m[i][j]){
// 					m[i][j] = q;
// 					s[i][j]=k;
// 				}

// 			}
// 		}
// 	}
// 	// m = (int **)malloc(sizeof(int *)*n);
// 	// s = (int **)malloc(sizeof(int *)*n);
// 	printOptimalParenthesis(s,n-1,n);
// //return s;
// }




// void main(){
// 	int lenArr[] =  {20, 10, 5, 35, 45, 5, 10, 15};
// 	//int** s ;
// 	matrixChainOrder(lenArr);
// 	// s = matrixChainOrder(lenArr);
// 	// printOptimalParenthesis();
// }


#include<stdio.h>
#include<limits.h>
 
char name = 'A';

void parenthesize(int i, int j, int n, int *bracket){

    if (i == j){
        printf("%c", name++);
        return;
    }
 
    printf("(");
 
    parenthesize(i, *((bracket+i*n)+j), n, bracket);
 
    parenthesize(*((bracket+i*n)+j) + 1, j, n, bracket);
    
    printf(")");
}
 
void matrixChain(int p[], int n){
    int m[n][n];
 
    int bracket[n][n];
 
    
    int i,L,k;
 
    for (i=1; i<n; i++)
        m[i][i] = 0;
 
    for (L=2; L<n; L++){
        
        for (i=1; i<n-L+1; i++){
            
            int j = i+L-1;
            m[i][j] = INT_MAX;
            
            for (k=i; k<=j-1; k++){
                
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
 
                    bracket[i][j] = k;
                }
            }
        }
    }   
 
    printf("Optimal Parenthesization is : ");
    parenthesize(1, n-1, n, (int *)bracket);
}
 
int main()
{
    int arr[] = {20, 10, 5, 35, 45, 5, 10, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    matrixChain(arr, n);
    return 0;
}

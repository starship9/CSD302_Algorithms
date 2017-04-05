/*
Name: Nishank Saini
Roll number: 1410110266
Assignment 12
29.3.17
*/
#include <stdio.h>
#include <limits.h>
 
int sum(int keyFrequency[], int i, int j);
 
int optimalSearchTree(int keys[], int keyFrequency[], int n)
{
    //temporary matrix for storing the result of each subproblem
    int bstCost[n][n];
    // For a single key, bstCost is equal to frequency of the key
    for (int i = 0; i < n; i++)
        bstCost[i][i] = keyFrequency[i];
 
    //for subsequent chains
    // chainLength is chain length.
    for (int chainLength=2; chainLength<=n; chainLength++)
    {
        for (int i=0; i<=n-chainLength+1; i++)
        {
            int j = i+chainLength-1;
            bstCost[i][j] = INT_MAX;
 
            // Try making all keys in interval keys[i..j] as root
            for (int r=i; r<=j; r++)
            {
               // tempCost = bstCost when keys[r] becomes root of this subtree
               int tempCost = ((r > i)? bstCost[i][r-1]:0) + 
                       ((r < j)? bstCost[r+1][j]:0) + 
                       sum(keyFrequency, i, j);
               if (tempCost < bstCost[i][j])
                  bstCost[i][j] = tempCost;
            }
        }
    }
    return bstCost[0][n-1];
}

int sum(int keyFrequency[], int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
       s += keyFrequency[k];
    return s;
}

int main()
{
    int keys[] = {10, 12, 20, 30, 40};
    int keyFrequency[] = {34, 8, 50, 12, 25};
    int n = sizeof(keys)/sizeof(keys[0]);
    printf("The optimal cost would be: %d ", optimalSearchTree(keys, keyFrequency, n));
    return 0;
}
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
 
// Number of vertices in the graph
#define V 100
 

int findMinKey(int key[], int mstSet[], int numNode)
{

   int minNode = INT_MAX, minIndex;
 
   for (int v = 0; v < numNode; v++)
     if (mstSet[v] == 0 && key[v] < minNode)
         minNode = key[v], minIndex = v;
 
   return minIndex;
}
 

void printMST(int parent[], int numNode, int graph[V][V])
{
   printf("Edge\t\tWeight\n");
   for (int i = 1; i < numNode; i++)
      printf("%d-%d\t\t%d \n", parent[i], i, graph[i][parent[i]]);
}
 

void primMST(int graph[V][V], int numNode)
{
     int* parent = (int *)malloc(numNode * sizeof(int)); 
     int* key = (int *)malloc(numNode * sizeof(int));    
     int* mstSet=(int *)malloc(numNode * sizeof(int)); 
    
     

     for (int i = 0; i < numNode; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
 
     
     key[0] = 0;     
     parent[0] = -1; 
 
     
     for (int count = 0; count < numNode-1; count++)
     {
     
        int u = findMinKey(key, mstSet,numNode);
 
     
        mstSet[u] = 1;
 
        for (int v = 0; v < numNode; v++)
 
          if (graph[u][v] && mstSet[v] == 0 && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     
     printMST(parent, numNode, graph);
}
 
 

int main(int argc, char* argv[])
{

  if(argc!=3){
    printf("usage: ./a.out <nodes> <edge_weight>");
    exit(1);
  }

  int n = atoi(argv[1]);
  int m = atoi(argv[2]);
  if(m>n*(n-1)/2)
    {
      printf("You've entered way too many edges!\n");
      exit(1);
    }
    

   // int graph[V][V] = {{0, 2, 0, 6, 0},
   //                    {2, 0, 3, 8, 5},
   //                    {0, 3, 0, 0, 7},
   //                    {6, 8, 0, 0, 9},
   //                    {0, 5, 7, 9, 0},
   //                   };
 
    int i,j;
    int newGraph[V][V];
    srand(time(NULL));
    for(i=0;i<atoi(argv[1]);i++){
      for(j=0;j<atoi(argv[2]);j++){
        newGraph[i][j] = 1+rand()%10;
      }
    }
    primMST(newGraph,atoi(argv[1]));
 
    return 0;
}
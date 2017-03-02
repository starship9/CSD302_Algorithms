#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>

#define MAX_TREE_HEIGHT 100

struct minimumHeapNode{
	char data;
	int freq;
	struct minimumHeapNode *left,*right;
};

struct minimumHeap {
	int heapSize;
	int heapCap;
	struct minimumHeapNode **array;
};

struct minimumHeapNode* newNode(char data, int freq){
	struct minimumHeapNode* temp = (struct minimumHeapNode*) malloc(sizeof(struct minimumHeapNode));
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;

}


struct minimumHeap* createminimumHeap(int heapCap){
	struct minimumHeap* minHeap = (struct minimumHeap*)malloc(sizeof(struct minimumHeapNode*));
	
	minHeap->heapSize = 0;  // current heapSize is 0
    minHeap->heapCap = heapCap;
    minHeap->array =
     (struct minimumHeapNode**)malloc(minHeap->heapCap * sizeof(struct minimumHeapNode*));

	return minHeap;
}

void swapminimumHeapNode(struct minimumHeapNode** a, struct minimumHeapNode** b){
	struct minimumHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct minimumHeap* minHeap, int idx){
	int smallest = idx;
	int left = 2*idx + 1;
	int right = 2*idx + 2;

	if(left<minHeap->heapSize && minHeap->array[left]->freq <minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->heapSize &&
        minHeap->array[right]->freq < minHeap->array[smallest]->freq)
      smallest = right;
 
    if (smallest != idx)
    {
        swapminimumHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int checkForOneSize(struct minimumHeap* minHeap){
	return(minHeap->heapSize==1);
}

struct minimumHeapNode* getMinValue(struct minimumHeap* minHeap){

	struct minimumHeapNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->heapSize-1];
	--minHeap->heapSize;
	minHeapify(minHeap,0);
	return temp;
}

void insertminimumHeap(struct minimumHeap* minHeap, struct minimumHeapNode* minHeapNode){
	++minHeap->heapSize;
    int i = minHeap->heapSize - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1)/2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildminimumHeap(struct minimumHeap* minHeap){
	int n = minHeap->heapSize-1;
	int i;
	for(i=(n-1)/2;i>=0;i--){
		minHeapify(minHeap,i);
	}
}

void printArr(int arr[], int n){
	int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isLeaf(struct minimumHeapNode* root)
{
    return !(root->left) && !(root->right) ;
}

struct minimumHeap* createAndBuildminimumHeap(char data[], int freq[], int heapSize)
{
    struct minimumHeap* minHeap = createminimumHeap(heapSize);
    for (int i = 0; i < heapSize; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->heapSize = heapSize;
    buildminimumHeap(minHeap);
    return minHeap;
}
 

struct minimumHeapNode* buildHuffmanTree(char data[], int freq[], int heapSize)
{
    struct minimumHeapNode *left, *right, *top;
 
    
    struct minimumHeap* minHeap = createAndBuildminimumHeap(data, freq, heapSize);
 
    
    while (!checkForOneSize(minHeap))
    {
        
        left = getMinValue(minHeap);
        right = getMinValue(minHeap);
 
        
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertminimumHeap(minHeap, top);
    }
    return getMinValue(minHeap);
}
 
void showHMCodes(struct minimumHeapNode* root, int arr[], int top)
{

    if (root->left)
    {
        arr[top] = 0;
        showHMCodes(root->left, arr, top + 1);
    }
 

    if (root->right)
    {
        arr[top] = 1;
        showHMCodes(root->right, arr, top + 1);
    }
     if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
 
 void genHMCode(char data[], int freq[], int heapSize)
{
 
   struct minimumHeapNode* root = buildHuffmanTree(data, freq, heapSize);
   int arr[MAX_TREE_HEIGHT], top = 0;
   showHMCodes(root, arr, top);
}

char alphaBet[4] = {'a','b','c','d'};
char str[100];
char freqAlpha[4] = {'a','b','c','d'};
int freqCount[4] = {0,0,0,0};
//calculates the frequency of each letter in the given string
void calculateFrequency(int n){
	
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			if(freqAlpha[j]==str[i]){
				freqCount[j]++;
			}
		}
	}
	for(i=0;i<4;i++){
		printf("\nThe frequency for letter %c is: %d\n",freqAlpha[i],freqCount[i]);
	}
}
//generates a random string from the given alphabet
void genRandString(int n) {
	srand(time(NULL));
	int i,j;

	for(i=0;i<n;i++){
		str[i] = alphaBet[rand()%4];
	}
	printf("Here's the randomly generated string:\n");
	puts(str);
	calculateFrequency(n);
}
//driver function
int main(int argc, char* argv[]){
	
	if(argc!=2){
		printf("usage: ./a.out <length of the string>");
		exit(1);
	}
	genRandString(atoi(argv[1]));

	int heapSize = sizeof(alphaBet)/sizeof(alphaBet[0]);
    genHMCode(alphaBet, freqCount, heapSize);
	//calculateFrequency();
return 0;

}
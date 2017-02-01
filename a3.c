#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define MAX (int)1e8
int sortArr[MAX];
int tempArr[MAX];

unsigned long long int randNum, findNum, fileNum;
	struct timeval t1,t2;
	float dataRate, elapsedTime;
	ssize_t totalSize = 0,totalTime = 0;

void printArr(int arr[], int n){
	//printf("Here's the sorted array\n");
	printf("---------------------------------\n");
	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("\n%d\n",arr[i]);
	}
}
void bubbleSort(int arr[], int n){
	int i,j,temp;
	//gettimeofday(&t1,NULL);
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	// gettimeofday(&t2,NULL);
	// elapsedTime = (t2.tv_sec - t1.tv_sec)*1000000L + (t2.tv_usec - t1.tv_usec);
 //    // totalTime += elapsedTime;
 //    printf("Elapsed time %d micro seconds\n", elapsedTime);

	//printArr(arr,n);
}

int getMaxForRadix(int arr[],int n){
	int max = arr[0];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if(max<arr[i])
			max=arr[i];
		return max;
	}
}

void radixSort(int arr[], int n){
	int digiBucket[1000][1000], digiCount[10];
	int maxNum, rem, div=1, minPass=0, loopPass,i,j,k;

	maxNum = getMaxForRadix(arr,n);

	while(maxNum>0){
		minPass++;
		maxNum=maxNum/10;
	}

	for(loopPass=0;loopPass<minPass;loopPass++){
		for(i=0;i<10;i++){
			digiCount[i]=0;
		}
		for (i=0;i<n;i++){
			rem = (arr[i]/div)%10;
			digiBucket[rem][digiCount[rem]]=arr[i];
			digiCount[rem]+=1;
		}
		i=0;
		for(j=0;j<10;j++){
			for(k=0;k<digiCount[j];k++){
				arr[i]=digiBucket[j][k];
				i++;
			}
		}
		div*=10;
		
	}
	// gettimeofday(&t2,NULL);
	// elapsedTime = (t2.tv_sec - t1.tv_sec)*1000000L + (t2.tv_usec - t1.tv_usec);
 //    // totalTime += elapsedTime;
 //    printf("Elapsed time %d micro seconds\n", elapsedTime);
	// printArr(arr,n);
}

void mergeArray(int arr[],int x1, int y1, int x2, int y2){
	int tempArr[1000000];
	int i,j,k;
	i=x1;
	j=y1;
	k=0;

	while(i<=x2 && j<=y2){
		if(arr[i]<arr[j])
			tempArr[k++] = arr[i++];
		else
			tempArr[k++]=arr[j++];
		}
	while(i<=x2){
		tempArr[k++] = arr[i++];
		}

	while(j<=y2){
		tempArr[k++] = arr[j++];
	}		
	for(i=x1,j=0;i<=y2;i++,j++){
		arr[i] = tempArr[j];
	}
}

void mergeSort(int arr[], int beg,int end){
	int mid;

	if(beg<end){
		mid = (beg+end)/2;
		mergeSort(arr,beg,mid);
		mergeSort(arr,mid+1,end);
		mergeArray(arr,beg,mid,mid+1,end);
	}
	// gettimeofday(&t2,NULL);
	// elapsedTime = (t2.tv_sec - t1.tv_sec)*1000000L + (t2.tv_usec - t1.tv_usec);
 //    // totalTime += elapsedTime;
 //    printf("Elapsed time %d micro seconds\n", elapsedTime);
	// printArr(arr,end);
}


void main()
{
	int n,i;

	

	printf("Enter the number of elements you wish to sort.\n");
	scanf("%d",&n);

	srand(time(NULL));
	for (i = 0; i < n; ++i)
	{
		/* code */
		sortArr[i] = (rand()%n);
	}
//	int tempArr[MAX];
	for(i=0;i<n;i++){
		tempArr[i]=sortArr[i];
	}
	printf("Here are the elements you've entered.\n");
	printArr(sortArr,n);
	gettimeofday(&t1,NULL);
	bubbleSort(sortArr,n);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000000L + (t2.tv_usec - t1.tv_usec);
		totalTime += elapsedTime;
	elapsedTime=elapsedTime/1000000;	
	   printf("Elapsed time %f seconds\n", elapsedTime);
	gettimeofday(&t1,NULL);
	radixSort(tempArr,n);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000000L + (t2.tv_usec - t1.tv_usec);
	totalTime += elapsedTime;
	elapsedTime=elapsedTime/1000000;
	printf("Elapsed time %f micro seconds\n", elapsedTime);
	gettimeofday(&t1,NULL);
	mergeSort(tempArr,0,n-1);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000000L + (t2.tv_usec - t1.tv_usec);
		totalTime += elapsedTime;
		elapsedTime=elapsedTime/1000000;
	 printf("Elapsed time %f micro seconds\n", elapsedTime);
}
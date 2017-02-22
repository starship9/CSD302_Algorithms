#include <stdio.h>
#include <math.h>

struct Items {
	int itemValue;
	int weight;
	double density;
}s[100];

//assigns densities to the items

void genDensities(struct Items arr[], int num){
	int i;
	for(i=0;i<num;i++){
		arr[i].density = floor(arr[i].itemValue/arr[i].weight);
	}
}

//for sorting the items according to their densities
void bubbleSort(struct Items arr[], int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j].density>arr[j+1].density){
				temp = arr[j].density;
				arr[j].density = arr[j+1].density;
				arr[j+1].density=temp;
			}
		}
	}
}

//the actual implementation of the knapsack algorithm
void knapSackGen(int num, struct Items item[], int knapCap){
	float x[100],temp = 0;

	int i,j,k;

	k = knapCap;

	for(i=0;i<num;i++){
		x[i]=0.0;
	}
	for(i=0;i<num;i++){
		if(item[i].weight>k){
			break;
		}
		else {
			x[i]=1.0;
			temp+=item[i].itemValue;
			k-=item[i].weight;
		}

	}

	if(i<num){
		x[i] = (float)k/item[i].weight;
	}

	temp+= (x[i]*item[i].itemValue);

	 printf("\nThe result vector is:- ");
   for (i = 0; i < num; i++)
      printf("%f ", x[i]);
 
   printf("\nMaximum profit is:- %f", temp);


}



int main() {
	struct Items item[100];
	int i,num,itemWeight, knapCap;
	printf("Enter the capacity of the knapsack.\n");
	scanf("%d",&knapCap);

	printf("Enter the number of items.\n");
	scanf("%d",&num);

	for(i=0;i<num;i++){
		printf("Enter the weight for item number: %d\n",i+1);
		scanf("%d",&itemWeight);
		item[i].weight = itemWeight;
	}
	int itemValue;

	for(i=0;i<num;i++){
		printf("Enter the value for item number: %d\n",i+1);
		scanf("%d",&itemValue);
		item[i].itemValue = itemValue;
	}

	genDensities(item,num);

	printf("Here are the densities of the items you've entered.\n");
	for(i=0;i<num;i++){
		printf("\t\n%f\n\t",item[i].density);
	}
	bubbleSort(item,num);
	printf("Here are the items, sorted in order of density.\n");
	for(i=0;i<num;i++){
		printf("\t\n%f\n\t",item[i].density);
	}

	knapSackGen(num,item,knapCap);



}
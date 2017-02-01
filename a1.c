#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {

	FILE* fp;
	int i,j;
	int numArr[1000000];
	fp = fopen("in1.txt","w+");
	unsigned long long int randNum;

	if(fp==NULL){
		printf("File not being created, exiting!\n");
		exit(1);
	}

	for(i=1;i<=1000;i++) {
		for(j=1;j<=1000;j++)
			fprintf(fp,"%d\n",i);
	}

	FILE* fp2;

	fp2 = fopen("in2.txt","w+");
	if(fp2==NULL){
		printf("File not being created, exiting!\n");
		exit(1);	
	}
	//srand(time(NULL));
	for(i=1;i<=1000000;i++){
		randNum = rand()%1000+1;
		fprintf(fp2, "%llu\n", randNum);
	}
	// for(i=1;i<=1000;i++){
	// 	randNum = rand()%1000 +1;
	// 	fprintf(fp3,"%d\n",randNum);
	// }

	FILE* fp3;
	fp3 = fopen("in3.txt","w+");
	if(fp3==NULL) {
		printf("File not being created, exiting!\n");
		exit(1);
	}

	for(i=1;i<=1000000;i++){
		randNum = 1000000 + rand()%1000000000+1;
		fprintf(fp3, "%llu\n", randNum);
	}
	fclose(fp);
	fclose(fp2);
	fclose(fp3);


}




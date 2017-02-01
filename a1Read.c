#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void main(int argc, char *argv[]) {

	FILE* fp;
	fp = fopen(argv[1],"r");
	
	unsigned long long int randNum, findNum, fileNum;
	struct timeval t1,t2;
  	int dataRate, elapsedTime;
  	ssize_t totalSize = 0,totalTime = 0;

	if(argc!=2) {
		printf("Error, enter the file to be searched!\n");
		exit(1);
	}


	if(fp==NULL){
		printf("Unable to find the file, exiting!\n");
	}

	printf("Enter a number to search for!\n");
	scanf("%llu",&findNum);

	gettimeofday(&t1,NULL);
	while(!feof(fp)) {
			fscanf(fp,"%llu\n",&fileNum);

			if(findNum==fileNum) {
				printf("Success!\n");
				break;
				
			}
			

	}

	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000000L + (t2.tv_usec - t1.tv_usec);
    // totalTime += elapsedTime;
    printf("Elapsed time %d micro seconds\n", elapsedTime);







}
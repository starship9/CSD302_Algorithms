#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int convertBinToDec(int n){
	int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

void main(int argc, char* argv[]) {

	
	if(argc!=2) {
		printf("Error, you need to specify the number of times you wish to flip the coin as well!\n");
		exit(1);
	}

	int i=0,n,m;
	FILE* fp;
	fp = fopen("prob.txt","w+");

	if(fp==NULL){
		printf("Error, file not created.\n");
		exit(1);
	}

	n = atoi(argv[1]); //user input for the number of tosses

	m = ceil(log(n)/log(2)); //simulating a 2-sided coin as a n-sided coin

	int coinFlips[] = {1,0};
	unsigned int recordFlips[100];
	char charFlips[100];
	int concatNum = 0;
	srand(time(NULL));
	int decNum,j=0;

	// for(j=0;j<1000;j++)
	{
	for(i=0;i<=m; i++) {
		recordFlips[i] = coinFlips[rand()%2];
	}

	printf("The tosses recorded thus far: \n");
	for (i=0;i<=m;i++) {
		if(recordFlips[i] == 1)
			printf("Heads\t%d\n",recordFlips[i]);
		else if(recordFlips[i]==0)
			printf("Tails\t%d\n", recordFlips[i]);
	}

	

	// for(i=0;i<100;i++){
	// 	sprintf(charFlips[i],"%d",recordFlips[i]);
	// }
	

	for(i=0;i<=m;i++) {
		concatNum = concatNum*10 + recordFlips[i];
 	}
 	printf("Concatenated number\t%d\n",concatNum);

 	
 	decNum = convertBinToDec(concatNum);
 	

 	printf("The decimal equivalent:\t%d\n",decNum);
	if(decNum<7 || decNum>1)
		fprintf(fp,"%d\n",decNum);
 	
}
fclose(fp);
}

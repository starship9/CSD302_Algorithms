#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

struct timeval t1,t2;
    float dataRate, elapsedTime;
    ssize_t totalSize = 0,totalTime = 0;

int checkSum(int sum, int num) {
	return(sum==num);
}

int genDivSum(int n) {
	int sum=1,i;

	for (i = 2; i < n; ++i)
	{
		/* code */
		if(n%i==0){
			sum+=i;
		}
	}
	return sum;
}

int main() {

	printf("Enter a number\n");
	int num;
	scanf("%d",&num);

	gettimeofday(&t1,NULL);
	int res = checkSum(genDivSum(num),num);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000000L + (t2.tv_usec - t1.tv_usec);
        totalTime += elapsedTime;
    elapsedTime=elapsedTime/1000000;    
       printf("Elapsed time %f seconds\n", elapsedTime);
	
	printf("Here's the result: %d",res);
//6,28:0.000001 | 496: 0.000007 | 8128: 0.000061
return 0;
}
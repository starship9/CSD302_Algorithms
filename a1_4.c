#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define LARGE 9999
int mcPrime(int num, int probFact) {

	int q = num-1;
	int i;
	for(i=0;i<LARGE;i++) {
		int m = q;
		int y = 1;
		int a = rand()%q + 1;
		int z = a;

		while(m>0) {
			while(m%2==0){
				z = (z*z)%num;
				m = ceil(m/2);
				}
			m-=1;
			y=(y*z)%num;

		}
	if(y!=1){
		return 0;
	}

	}
	return 1;
}

int main(int argc, float* argv[]) {
	if(argc!=3){
		printf("usage: ./a.out <INT>");
		exit(1);
	}

	int res = mcPrime(argv[1],argv[2]);
	printf("Here's the result: %d\n",res);


	return 0;
}
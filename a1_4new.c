#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>

int primeMC(int num) {
	int i,j,m;
	int t;
	t = pow(num,0.5);
	if(num==1)
		return 1;
	for(i=1;i<t;i++) {
		m = pow(num,0.5);
		j=rand()%m + 2;
		if(num%j==0)
			return 0;
	}
	return 1;
}

int main(int argc, char* argv[]) {

	if(argc!=2){
		printf("usage: <NUM> <PF>");
		exit(1);
	}
	printf("%d",primeMC(atoi(argv[1])));


	return 0;
}
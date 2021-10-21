#include <stdio.h>
#include <unistd.h>

int main(){
	int sum1=0, sum2=0;
	int p1=fork();

	
	for(int i = 1; i <= 20; i++){
		if(i % 2 == 0 && p1 == 0){
			sum2 += i;
		}
		else if(i % 2 == 1 && p1 > 0){
			sum1 += i;
		}
	}
	
	if(p1==0){
		printf("Child process pid is %d and even sum is %d\n", getpid(), sum2);
	}
	else{
	        printf("Parent process pid is %d and odd sum is %d\n", getpid(), sum1);
	}
	return 0;
}

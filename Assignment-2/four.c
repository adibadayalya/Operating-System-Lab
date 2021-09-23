#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void createChild(int x)
{
	if(fork()==0)
		printf("NUMBER: %d PROCESS ID %d and PARENT NUMBER: %d PROCESS ID is %d\n",x,getpid(),x-1,getppid());
	else

    sleep(1000);
}
int main()
{

	for(int i=1;i<=7;i++){
		createChild(i);
	}
	return 0;
}

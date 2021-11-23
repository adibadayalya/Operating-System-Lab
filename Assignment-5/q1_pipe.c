#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
	int key;
	key=mkfifo("pipe1", 0777);
	printf("Successful\n");
	return 0;
}

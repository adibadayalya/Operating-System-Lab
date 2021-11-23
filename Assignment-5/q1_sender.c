#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
int fd=open("pipe1", O_RDWR | O_NONBLOCK);
write(fd, "Sending data from process1", 27);
printf("Data sent from process1 with pid: %d\n", getpid());
char buff[100];
read(fd, buff, 100);
printf("Data received from process2 is: %s\n", buff);
close(fd);
}

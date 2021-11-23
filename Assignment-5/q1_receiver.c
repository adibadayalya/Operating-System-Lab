#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
char buff[100];
int fd=open("pipe1", O_RDWR | O_NONBLOCK);
read(fd, buff, 100);
printf("Data received from process2 is: %s\n", buff);
write(fd, "Sending data from process2", 27);
printf("Data sent from process2 with pid: %d\n", getpid());
close(fd);
}

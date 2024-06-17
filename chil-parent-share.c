#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);
    int pid = fork(); // creates 2 process .. child and parent
    char buffer[11];
    if (pid == 0)
    {
        // executes in child process
        read(fd, buffer, 10);
        buffer[10] = '\0';
        printf("Child Process %s\n", buffer);
    }
    else
    {
        // executes in parent process
        wait(NULL); // waits till child process completes
        read(fd, buffer, 10);
        buffer[10] = '\0';
        printf("Parent read: %s\n", buffer);
    }
    close(fd);
    return 0;
}

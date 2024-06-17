#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{

    int fd = open("file.txt", O_RDONLY); // opens in read only mode
    int size = lseek(fd, 0, SEEK_END);  // move the file offset(pointer) 0th place from end of file ( meaning dont move ) and returns the pointer position (ie, size of file) 
    char ch;

    while (size--)
    {

        // lseek ( from , no of position to move , move from/ to)
      
        lseek(fd, size, SEEK_SET);  // SEEK_SET = file start.... and here lseek will move pointer from file start to size 
        read(fd, &ch, 1); // read( from , to , no of char)
        putchar(ch);
    }
    close(fd);

    return 0;
}

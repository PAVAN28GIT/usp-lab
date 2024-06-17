#include <stdio.h>
#include <sys/stat.h>

int main()
{

    struct stat ft;
    stat("file.txt", &ft);
    printf("size is %lld bytes \n :", ft.st_size);
    printf("no of links %hu\n :", ft.st_nlink);
    printf("access time %ld\n :", ft.st_atime);
    printf("file inode %llu\n:", ft.st_ino);
    printf("modified time %ld\n:", ft.st_mtime);
    return 0;
}

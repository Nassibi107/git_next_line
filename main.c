#include <stdio.h>
#include <string.h>
#include <sys/fcntl.h>
#include <unistd.h>

int main ()
{
   char str[] = "yassine\nnassibi@1773.ma";
   int fd = open("yassinssedd
   .txt",O_CREAT | O_RDWR,0474);

   write(fd, str, strlen(str));

   // fprintf(fd, const char *, ...)
}

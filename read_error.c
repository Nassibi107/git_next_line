
#include "get_next_line.h"
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdio.h>

void fun()
{
	system("leaks a.out");
}


int main ()
{
	int	f;

	atexit(fun);
	f = open("read_error.txt", O_CREAT | O_RDWR, 0777);
	char *str = get_next_line(f);

	while (str)
	{
		printf("%s\n", str);
		free (str);
		str = get_next_line(f);
	}
}

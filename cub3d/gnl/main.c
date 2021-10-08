#include "get_next_line.h"

int main ()
{
	char *buf;
	int fd = open("./get_next_line.c", O_RDONLY);
	int res = get_next_line(fd, &buf);
	printf("%s\n",buf);
	free(buf);
	close(fd);
}

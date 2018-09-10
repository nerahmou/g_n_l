#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"

int main(int argc, const char *argv[])
{
	int i = 2;
	char *str;
	int ret;

	while ((ret = get_next_line(0, &str)))
	{
		printf("%s\n",str);
	free(str);
	}
	return 0;
}

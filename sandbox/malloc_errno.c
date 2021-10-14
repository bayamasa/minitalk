#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

int	main()
{
	char *a = malloc(ULONG_LONG_MAX * ULONG_LONG_MAX * ULONG_LONG_MAX);
	if (a == NULL)
		printf("strerror : %s\n", strerror(errno));
	return (0);
}

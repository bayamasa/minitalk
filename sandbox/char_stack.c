#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	main()
{
	long long a = 126;
	printf("c = %p\n", (void *)a);
	return (0);
}

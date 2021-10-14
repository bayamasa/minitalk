#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	main()
{
	int num = 127;
	int one = 1;
	for (size_t i = 0; i < 8; i++)
	{
		printf("i & one = %d\n", num & one);
		num >>= 1;
	}
	return (0);
}

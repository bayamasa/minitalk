#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	main()
{
	int count = 6;
	char a = 0;
	int bit = 1;
	for (size_t i = 0; i < count; i++)
	{
		a |= bit;
		a <<= 1;
	}
	printf("a = %d\n", a);
	
	return (0);
}

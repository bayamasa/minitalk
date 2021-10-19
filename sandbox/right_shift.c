#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	main()
{
	int count = 7;
	char a = 0;
	for (size_t i = 0; i < count; i++)
	{
		a <<= 1;
	}
	a <<= 0;
	printf("a = %d\n", a);
	
	return (0);
}
